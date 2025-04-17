/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpiimpl.h"
#include <cuda_runtime.h>
#include <cuSZp.h>
#include <stdlib.h>    /* for malloc/free */
#include <string.h>    /* for memcpy */

#if !defined(MPIC_REQUEST_PTR_ARRAY_SIZE)
#define MPIC_REQUEST_PTR_ARRAY_SIZE 64
#endif

/* These functions are used in the implementation of collective
   operations. They are wrappers around MPID send/recv functions. They do
   sends/receives by setting the context offset MPIR_CONTEXT_COLL_OFFSET.
 */

/* These macros are from the original file to handle MPID_Isend/Irecv with threadcomm. */
#ifdef ENABLE_THREADCOMM
#define DO_MPID_ISEND(buf, count, datatype, dest, tag, comm_ptr, attr, req)       \
    do {                                                                          \
        if (comm_ptr->threadcomm) {                                              \
            mpi_errno = MPIR_Threadcomm_isend_attr(buf, count, datatype, dest,   \
                                                   tag, comm_ptr->threadcomm,    \
                                                   attr, req);                   \
        } else {                                                                 \
            mpi_errno = MPID_Isend(buf, count, datatype, dest, tag, comm_ptr,    \
                                   attr, req);                                   \
        }                                                                        \
    } while (0)

#define DO_MPID_IRECV(buf, count, datatype, source, tag, comm_ptr, attr, req)    \
    do {                                                                          \
        if (comm_ptr->threadcomm) {                                              \
            mpi_errno = MPIR_Threadcomm_irecv_attr(buf, count, datatype, source, \
                                                   tag, comm_ptr->threadcomm,    \
                                                   attr, req, true);             \
        } else {                                                                 \
            mpi_errno = MPID_Irecv(buf, count, datatype, source, tag, comm_ptr,  \
                                   attr, req);                                   \
        }                                                                        \
    } while (0)

#else
#define DO_MPID_ISEND(buf, count, datatype, dest, tag, comm_ptr, attr, req)   \
    do {                                                                      \
        mpi_errno = MPID_Isend(buf, count, datatype, dest, tag, comm_ptr,     \
                               attr, req);                                    \
    } while (0)

#define DO_MPID_IRECV(buf, count, datatype, source, tag, comm_ptr, attr, req) \
    do {                                                                       \
        mpi_errno = MPID_Irecv(buf, count, datatype, source, tag, comm_ptr,    \
                               attr, req);                                     \
    } while (0)
#endif

/* ------------------------------------------------------------------------
 * cuSZp integration helpers
 * ------------------------------------------------------------------------ */

/* Helper: check if pointer is in GPU memory (only works if CUDA is enabled) */
static bool is_buffer_on_gpu(const void *buf)
{
    struct cudaPointerAttributes attr;
    cudaError_t cerr = cudaPointerGetAttributes(&attr, buf);
    if (cerr != cudaSuccess) {
        return false;
    }
#if CUDART_VERSION >= 10000
    return (attr.type == cudaMemoryTypeDevice);
#else
    return (attr.memoryType == cudaMemoryTypeDevice);
#endif
}

/* Determine if MPI_Datatype is float or double for cuSZp */
static cuszp_type_t get_cuszp_datatype(MPI_Datatype datatype)
{
    if (datatype == MPI_FLOAT) {
        return CUSZP_TYPE_FLOAT;
    } else if (datatype == MPI_DOUBLE) {
        return CUSZP_TYPE_DOUBLE;
    } else {
        return (cuszp_type_t) -1;  /* not supported */
    }
}

/* Choose the compression mode for cuSZp (PLAIN or OUTLIER) */
static cuszp_mode_t get_cuszp_mode()
{
    return CUSZP_MODE_PLAIN; /* example uses PLAIN mode */
}

/* Set the error bound for cuSZp compression */
static float get_error_bound()
{
    return 1e-3f;  /* example: 1e-3 */
}

/* If you have a particular CUDA stream, return it here, else 0 (default) */
static cudaStream_t get_cuda_stream()
{
    return 0;
}

/*
 * compress_gpu:
 *   - inbuf_gpu: GPU pointer with float/double data
 *   - count: number of elements
 *   - dtype: CUSZP_TYPE_FLOAT or CUSZP_TYPE_DOUBLE
 *   - outbuf_host: (output) host pointer allocated internally, 
 *                  containing [ size_t(cmpSize) + compressed bytes ]
 *   - outsize_host: total bytes in outbuf_host
 */
static int compress_gpu(const void *inbuf_gpu, size_t count, cuszp_type_t dtype,
                        unsigned char **outbuf_host, size_t *outsize_host)
{
    int rc = 0;
    cudaStream_t stream = get_cuda_stream();
    float eb = get_error_bound();
    cuszp_mode_t mode = get_cuszp_mode();

    /* Over-allocate a device buffer for compressed data. 
     * For demonstration, we assume worst-case = same size as uncompressed. */
    size_t max_len = count * ((dtype == CUSZP_TYPE_FLOAT) ? sizeof(float) : sizeof(double));
    unsigned char *d_cmp = NULL;
    cudaMalloc((void **) &d_cmp, max_len);

    size_t cmpSize = 0;
    rc = cuSZp_compress(inbuf_gpu, d_cmp, count, &cmpSize, eb, dtype, mode, stream);
    if (rc != 0) {
        cudaFree(d_cmp);
        return rc;
    }

    /* We will send [ cmpSize + compressed bytes ] as one MPI message. */
    size_t total_size = sizeof(size_t) + cmpSize;
    unsigned char *h_buf = (unsigned char *) malloc(total_size);

    memcpy(h_buf, &cmpSize, sizeof(size_t));
    cudaMemcpy(h_buf + sizeof(size_t), d_cmp, cmpSize, cudaMemcpyDeviceToHost);

    cudaFree(d_cmp);

    *outbuf_host = h_buf;
    *outsize_host = total_size;

    return rc;
}

/*
 * decompress_gpu:
 *   - outbuf_gpu: GPU pointer where final data is decompressed
 *   - inbuf_host: host pointer with [ size_t(cmpSize) + compressed bytes ]
 *   - inbuf_size: total bytes in inbuf_host
 */
static int decompress_gpu(void *outbuf_gpu, size_t count, cuszp_type_t dtype,
                          unsigned char *inbuf_host, size_t inbuf_size)
{
    if (inbuf_size < sizeof(size_t)) {
        return -1; /* error */
    }

    size_t cmpSize;
    memcpy(&cmpSize, inbuf_host, sizeof(size_t));
    if (inbuf_size < cmpSize + sizeof(size_t)) {
        return -2; /* mismatch */
    }

    unsigned char *d_cmp = NULL;
    cudaMalloc((void **) &d_cmp, cmpSize);
    cudaMemcpy(d_cmp, inbuf_host + sizeof(size_t), cmpSize, cudaMemcpyHostToDevice);

    float eb = get_error_bound();
    cuszp_mode_t mode = get_cuszp_mode();
    cudaStream_t stream = get_cuda_stream();

    int rc = cuSZp_decompress(outbuf_gpu, d_cmp, count, cmpSize, eb, dtype, mode, stream);
    cudaFree(d_cmp);

    return rc;
}

/*
 * For the sake of the demo, we guess a max compressed size for receiving:
 *  2x uncompressed + some overhead
 */
static size_t guess_max_compressed_bytes(size_t count, cuszp_type_t dtype)
{
    size_t uncompressed = count * ((dtype == CUSZP_TYPE_FLOAT) ? sizeof(float) : sizeof(double));
    /* naive guess: 2x + size_t overhead */
    return uncompressed * 2 + sizeof(size_t);
}


int MPIC_Probe(int source, int tag, MPI_Comm comm, MPI_Status * status)
{
    int mpi_errno = MPI_SUCCESS;
    int attr = 0;
    MPIR_Comm *comm_ptr;

    if (unlikely(source == MPI_PROC_NULL)) {
        MPIR_Status_set_procnull(status);
        goto fn_exit;
    }

    MPIR_Comm_get_ptr(comm, comm_ptr);

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);

    mpi_errno = MPID_Probe(source, tag, comm_ptr, attr, status);
    if (mpi_errno != MPI_SUCCESS)
        goto fn_fail;

fn_exit:
    return mpi_errno;
fn_fail:
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    goto fn_exit;
}

/* Wait wrapper */
int MPIC_Wait(MPIR_Request * request_ptr)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIR_Wait(request_ptr, MPI_STATUS_IGNORE);
    MPIR_ERR_CHECK(mpi_errno);

    if (request_ptr->kind == MPIR_REQUEST_KIND__RECV) {
        mpi_errno = MPIR_Process_status(&request_ptr->status);
        MPIR_ERR_CHECK(mpi_errno);
    }

fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
fn_fail:
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    goto fn_exit;
}

/* FIXME: For the brief-global and finer-grain control, we must ensure that
   the global lock is *not* held when this routine is called. (unless we change
   progress_start/end to grab the lock, in which case we must *still* make
   sure that the lock is not held when this routine is called). */


/* Fault-tolerance versions.  When a process fails, collectives will
   still complete, however the result may be invalid.  Processes
   directly communicating with the failed process can detect the
   failure, however another mechanism is needed to commuinicate the
   failure to other processes receiving the invalid data.  To do this
   we introduce the _ft versions of the MPIC_ helper functions.  These
   functions take a pointer to an error flag.  When this is set to
   TRUE, the send functions will communicate the failure to the
   receiver.  If a function detects a failure, either by getting a
   failure in the communication operation, or by receiving an error
   indicator from a remote process, it sets the error flag to TRUE.

   In this implementation, we indicate an error to a remote process by
   sending an empty message instead of the requested buffer.  When a
   process receives an empty message, it knows to set the error flag.
   We count on the fact that collectives that exchange data (as
   opposed to barrier) will never send an empty message.  The barrier
   collective will not communicate failure information this way, but
   this is OK since there is no data that can be received corrupted. */

/* MPIC_Send with blocking semantics + potential GPU compression. */
int MPIC_Send(const void *buf, MPI_Aint count, MPI_Datatype datatype,
              int dest, int tag, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int attr = 0;
    MPIR_Request *request_ptr = NULL;

    MPIR_FUNC_ENTER;

    MPIR_DATATYPE_ASSERT_BUILTIN(datatype);

    if (unlikely(dest == MPI_PROC_NULL)) {
        /* dummy process => no operation */
        goto fn_exit;
    }

    MPIR_ERR_CHKANDJUMP1((count < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", count);

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);
    MPIR_PT2PT_ATTR_SET_ERRFLAG(attr, errflag);

    bool on_gpu = is_buffer_on_gpu(buf);
    cuszp_type_t czp_dtype = get_cuszp_datatype(datatype);

    if (on_gpu && czp_dtype != (cuszp_type_t) -1 && count > 0) {
        /* Compress to host buffer */
        unsigned char *host_buffer = NULL;
        size_t host_size = 0;
        int rc = compress_gpu(buf, (size_t) count, czp_dtype, &host_buffer, &host_size);
        if (rc == 0 && host_buffer && host_size > 0) {
            /* Now do a single Isend with MPI_BYTE + wait + free */
            DO_MPID_ISEND(host_buffer, host_size, MPI_BYTE, dest, tag,
                          comm_ptr, attr, &request_ptr);
            MPIR_ERR_CHECK(mpi_errno);

            if (request_ptr) {
                mpi_errno = MPIC_Wait(request_ptr);
                MPIR_ERR_CHECK(mpi_errno);
                MPIR_Request_free(request_ptr);
            }
            free(host_buffer);
            goto fn_exit;
        }
        /* if compression fails => fallback to original path below */
    }

    /* Normal path (CPU buffer or unsupported type) */
    DO_MPID_ISEND(buf, count, datatype, dest, tag, comm_ptr, attr, &request_ptr);
    MPIR_ERR_CHECK(mpi_errno);

    if (request_ptr) {
        mpi_errno = MPIC_Wait(request_ptr);
        MPIR_ERR_CHECK(mpi_errno);
        MPIR_Request_free(request_ptr);
    }

fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
fn_fail:
    /* error handling */
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    if (request_ptr)
        MPIR_Request_free(request_ptr);
    goto fn_exit;
}

/* MPIC_Recv with blocking semantics + potential GPU decompression. */
int MPIC_Recv(void *buf, MPI_Aint count, MPI_Datatype datatype,
              int source, int tag, MPIR_Comm * comm_ptr, MPI_Status * status)
{
    int mpi_errno = MPI_SUCCESS;
    int attr = 0;
    MPI_Status mystatus;
    MPIR_Request *request_ptr = NULL;

    MPIR_FUNC_ENTER;

    MPIR_DATATYPE_ASSERT_BUILTIN(datatype);

    if (unlikely(source == MPI_PROC_NULL)) {
        MPIR_Status_set_procnull(status);
        goto fn_exit;
    }

    MPIR_ERR_CHKANDJUMP1((count < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", count);

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);

    if (status == MPI_STATUS_IGNORE)
        status = &mystatus;

    bool on_gpu = is_buffer_on_gpu(buf);
    cuszp_type_t czp_dtype = get_cuszp_datatype(datatype);

    if (on_gpu && czp_dtype != (cuszp_type_t) -1 && count > 0) {
        /* We'll do an Irecv to a large host buffer, then decompress to GPU. */
        size_t max_size = guess_max_compressed_bytes((size_t) count, czp_dtype);
        unsigned char *host_buffer = (unsigned char *) malloc(max_size);

        /* irecv: we don't know the exact compressed size, so we guess. */
        DO_MPID_IRECV(host_buffer, max_size, MPI_BYTE, source, tag, comm_ptr, attr, &request_ptr);
        MPIR_ERR_CHECK(mpi_errno);

        if (request_ptr) {
            mpi_errno = MPIC_Wait(request_ptr);
            MPIR_ERR_CHECK(mpi_errno);

            *status = request_ptr->status;
            mpi_errno = status->MPI_ERROR;
            MPIR_Request_free(request_ptr);
            request_ptr = NULL;
        }

        /* The actual bytes are in status->count. */
        int recv_bytes = 0;
        MPIR_Get_count_impl(status, MPI_BYTE, &recv_bytes);
        if (recv_bytes < 0) {
            free(host_buffer);
            goto fn_fail;
        }

        /* Decompress to buf (GPU). */
        int rc = decompress_gpu(buf, (size_t) count, czp_dtype,
                                host_buffer, (size_t) recv_bytes);
        free(host_buffer);
        if (rc != 0) {
            goto fn_fail;
        }
        goto fn_exit;
    } else {
        /* Normal CPU path */
        DO_MPID_IRECV(buf, count, datatype, source, tag, comm_ptr, attr, &request_ptr);
        MPIR_ERR_CHECK(mpi_errno);

        if (request_ptr) {
            mpi_errno = MPIC_Wait(request_ptr);
            MPIR_ERR_CHECK(mpi_errno);

            *status = request_ptr->status;
            mpi_errno = status->MPI_ERROR;
            MPIR_Request_free(request_ptr);
        }
    }

fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
fn_fail:
    /* error handling */
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    if (request_ptr)
        MPIR_Request_free(request_ptr);
    goto fn_exit;
}

int MPIC_Sendrecv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                  int dest, int sendtag, void *recvbuf, MPI_Aint recvcount,
                  MPI_Datatype recvtype, int source, int recvtag,
                  MPIR_Comm * comm_ptr, MPI_Status * status, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int attr = 0;
    MPI_Status mystatus;
    MPIR_Request *recv_req_ptr = NULL, *send_req_ptr = NULL;

    MPIR_FUNC_ENTER;

    MPIR_DATATYPE_ASSERT_BUILTIN(sendtype);
    MPIR_DATATYPE_ASSERT_BUILTIN(recvtype);

    MPIR_ERR_CHKANDJUMP1((sendcount < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", sendcount);
    MPIR_ERR_CHKANDJUMP1((recvcount < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", recvcount);

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);

    if (status == MPI_STATUS_IGNORE)
        status = &mystatus;

    /* If source is MPI_PROC_NULL, create a completed request and return. */
    if (unlikely(source == MPI_PROC_NULL)) {
        recv_req_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__RECV);
        MPIR_ERR_CHKANDSTMT(recv_req_ptr == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail,
                            "**nomemreq");
        MPIR_Status_set_procnull(&recv_req_ptr->status);
    } else {
        DO_MPID_IRECV(recvbuf, recvcount, recvtype, source, recvtag, comm_ptr, attr, &recv_req_ptr);
        MPIR_ERR_CHECK(mpi_errno);
    }

    /* If dest is MPI_PROC_NULL, create a completed request and return. */
    if (unlikely(dest == MPI_PROC_NULL)) {
        send_req_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__SEND);
        MPIR_ERR_CHKANDSTMT(send_req_ptr == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail,
                            "**nomemreq");
    } else {
        MPIR_PT2PT_ATTR_SET_ERRFLAG(attr, errflag);
        DO_MPID_ISEND(sendbuf, sendcount, sendtype, dest, sendtag, comm_ptr, attr, &send_req_ptr);
        MPIR_ERR_CHECK(mpi_errno);
    }

    mpi_errno = MPIC_Wait(send_req_ptr);
    MPIR_ERR_CHECK(mpi_errno);
    mpi_errno = MPIC_Wait(recv_req_ptr);
    if (mpi_errno)
        MPIR_ERR_POPFATAL(mpi_errno);

    *status = recv_req_ptr->status;

    if (mpi_errno == MPI_SUCCESS) {
        mpi_errno = recv_req_ptr->status.MPI_ERROR;

        if (mpi_errno == MPI_SUCCESS) {
            mpi_errno = send_req_ptr->status.MPI_ERROR;
        }
    }

    MPIR_Request_free(send_req_ptr);
    MPIR_Request_free(recv_req_ptr);

  fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    if (send_req_ptr)
        MPIR_Request_free(send_req_ptr);
    if (recv_req_ptr)
        MPIR_Request_free(recv_req_ptr);
    goto fn_exit;
}

/* NOTE: for regular collectives (as opposed to irregular collectives) calling
 * this function repeatedly will almost always be slower than performing the
 * equivalent inline because of the overhead of the repeated malloc/free */
int MPIC_Sendrecv_replace(void *buf, MPI_Aint count, MPI_Datatype datatype,
                          int dest, int sendtag,
                          int source, int recvtag,
                          MPIR_Comm * comm_ptr, MPI_Status * status, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    MPI_Status mystatus;
    int attr = 0;
    MPIR_Request *sreq = NULL;
    MPIR_Request *rreq = NULL;
    void *tmpbuf = NULL;
    MPI_Aint tmpbuf_size = 0;
    MPI_Aint actual_pack_bytes = 0;
    MPIR_CHKLMEM_DECL();

    MPIR_FUNC_ENTER;

    MPIR_ERR_CHKANDJUMP1((count < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", count);

    if (status == MPI_STATUS_IGNORE)
        status = &mystatus;

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);

    if (count > 0 && dest != MPI_PROC_NULL) {
        MPIR_Pack_size(count, datatype, &tmpbuf_size);
        MPIR_CHKLMEM_MALLOC(tmpbuf, tmpbuf_size);

        mpi_errno =
            MPIR_Typerep_pack(buf, count, datatype, 0, tmpbuf, tmpbuf_size, &actual_pack_bytes,
                              MPIR_TYPEREP_FLAG_NONE);
        MPIR_ERR_CHECK(mpi_errno);
    }

    /* If source is MPI_PROC_NULL, create a completed request and return. */
    if (unlikely(source == MPI_PROC_NULL)) {
        rreq = MPIR_Request_create_complete(MPIR_REQUEST_KIND__RECV);
        MPIR_ERR_CHKANDSTMT(rreq == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail, "**nomemreq");
        MPIR_Status_set_procnull(&rreq->status);
    } else {
        DO_MPID_IRECV(buf, count, datatype, source, recvtag, comm_ptr, attr, &rreq);
        MPIR_ERR_CHECK(mpi_errno);
    }

    /* If dest is MPI_PROC_NULL, create a completed request and return. */
    if (unlikely(dest == MPI_PROC_NULL)) {
        sreq = MPIR_Request_create_complete(MPIR_REQUEST_KIND__SEND);
        MPIR_ERR_CHKANDSTMT(sreq == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail, "**nomemreq");
    } else {
        MPIR_PT2PT_ATTR_SET_ERRFLAG(attr, errflag);
        DO_MPID_ISEND(tmpbuf, actual_pack_bytes, MPIR_BYTE_INTERNAL, dest, sendtag, comm_ptr, attr,
                      &sreq);
        MPIR_ERR_CHECK(mpi_errno);
        if (mpi_errno != MPI_SUCCESS) {
            /* --BEGIN ERROR HANDLING-- */
            /* FIXME: should we cancel the pending (possibly completed) receive
             * request or wait for it to complete? */
            MPIR_Request_free(rreq);
            MPIR_ERR_POP(mpi_errno);
            /* --END ERROR HANDLING-- */
        }
    }

    mpi_errno = MPIC_Wait(sreq);
    MPIR_ERR_CHECK(mpi_errno);
    mpi_errno = MPIC_Wait(rreq);
    MPIR_ERR_CHECK(mpi_errno);

    *status = rreq->status;

    if (mpi_errno == MPI_SUCCESS) {
        mpi_errno = rreq->status.MPI_ERROR;

        if (mpi_errno == MPI_SUCCESS) {
            mpi_errno = sreq->status.MPI_ERROR;
        }
    }

    MPIR_Request_free(sreq);
    MPIR_Request_free(rreq);

  fn_exit:
    MPIR_CHKLMEM_FREEALL();
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    if (sreq)
        MPIR_Request_free(sreq);
    if (rreq)
        MPIR_Request_free(rreq);
    goto fn_exit;
}

int MPIC_Isend(const void *buf, MPI_Aint count, MPI_Datatype datatype, int dest, int tag,
               MPIR_Comm * comm_ptr, MPIR_Request ** request_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int attr = 0;

    MPIR_FUNC_ENTER;

    /* Create a completed request and return immediately for dummy process */
    if (unlikely(dest == MPI_PROC_NULL)) {
        *request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__SEND);
        MPIR_ERR_CHKANDSTMT((*request_ptr) == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail,
                            "**nomemreq");
        goto fn_exit;
    }

    MPIR_ERR_CHKANDJUMP1((count < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", count);

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);
    MPIR_PT2PT_ATTR_SET_ERRFLAG(attr, errflag);

    DO_MPID_ISEND(buf, count, datatype, dest, tag, comm_ptr, attr, request_ptr);
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    goto fn_exit;
}

int MPIC_Irecv(void *buf, MPI_Aint count, MPI_Datatype datatype, int source,
               int tag, MPIR_Comm * comm_ptr, MPIR_Request ** request_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    int attr = 0;

    MPIR_FUNC_ENTER;

    /* Create a completed request and return immediately for dummy process */
    if (unlikely(source == MPI_PROC_NULL)) {
        MPIR_Request *rreq = MPIR_Request_create_complete(MPIR_REQUEST_KIND__RECV);
        MPIR_ERR_CHKANDSTMT(rreq == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail, "**nomemreq");
        *request_ptr = rreq;
        MPIR_Status_set_procnull(&rreq->status);
        goto fn_exit;
    }

    MPIR_ERR_CHKANDJUMP1((count < 0), mpi_errno, MPI_ERR_COUNT,
                         "**countneg", "**countneg %d", count);

    MPIR_PT2PT_ATTR_SET_CONTEXT_OFFSET(attr, MPIR_CONTEXT_COLL_OFFSET);

    DO_MPID_IRECV(buf, count, datatype, source, tag, comm_ptr, attr, request_ptr);
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    if (mpi_errno == MPIX_ERR_NOREQ)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**nomem");
    goto fn_exit;
}


int MPIC_Waitall(int numreq, MPIR_Request * requests[], MPI_Status * statuses)
{
    int mpi_errno = MPI_SUCCESS;
    int i;
    MPI_Status status_static_array[MPIC_REQUEST_PTR_ARRAY_SIZE];
    MPI_Status *status_array = statuses;
    MPIR_CHKLMEM_DECL();

    MPIR_FUNC_ENTER;

    if (statuses == MPI_STATUSES_IGNORE) {
        status_array = status_static_array;
    }

    if (numreq > MPIC_REQUEST_PTR_ARRAY_SIZE) {
        if (statuses == MPI_STATUSES_IGNORE) {
            MPIR_CHKLMEM_MALLOC(status_array, numreq * sizeof(MPI_Status));
        }
    }

    mpi_errno = MPIR_Waitall(numreq, requests, status_array);
    MPIR_ERR_CHECK(mpi_errno);

    /* The errflag value here is for all requests, not just a single one.  If
     * in the future, this function is used for multiple collectives at a
     * single time, we may have to change that. */
    for (i = 0; i < numreq; ++i) {
        if (requests[i]->kind == MPIR_REQUEST_KIND__RECV) {
            mpi_errno = MPIR_Process_status(&status_array[i]);
            MPIR_ERR_CHECK(mpi_errno);
        }
        MPIR_Request_free(requests[i]);
    }

  fn_exit:
    if (numreq > MPIC_REQUEST_PTR_ARRAY_SIZE)
        MPIR_CHKLMEM_FREEALL();
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}