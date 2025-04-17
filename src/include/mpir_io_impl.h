/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#ifndef MPIR_IO_IMPL_H_INCLUDED
#define MPIR_IO_IMPL_H_INCLUDED

#ifdef BUILD_MPI_ABI
#define MPIR_ERR_RECOVERABLE 0
#define MPIR_ERR_FATAL 1
int MPIR_Err_create_code(int, int, const char[], int, int, const char[], const char[], ...);
int MPIR_Err_return_comm(void *, const char[], int);
#endif

void MPIR_Ext_cs_enter(void);
void MPIR_Ext_cs_exit(void);
#ifndef HAVE_ROMIO
#define MPIO_Err_return_file(fh, errorcode) MPIR_Err_return_comm((void *)0, __func__, errorcode)
#else
MPI_Fint MPIR_File_c2f_impl(MPI_File fh);
MPI_File MPIR_File_f2c_impl(MPI_Fint fh);
int MPIO_Err_return_file(MPI_File fh, int errorcode);
#endif

int MPIR_File_close_impl(MPI_File *fh);
int MPIR_File_delete_impl(const char *filename, MPI_Info info);
int MPIR_File_get_amode_impl(MPI_File fh, int *amode);
int MPIR_File_get_atomicity_impl(MPI_File fh, int *flag);
int MPIR_File_get_byte_offset_impl(MPI_File fh, MPI_Offset offset, MPI_Offset *disp);
int MPIR_File_get_group_impl(MPI_File fh, MPI_Group *group);
int MPIR_File_get_info_impl(MPI_File fh, MPI_Info *info_used);
int MPIR_File_get_position_impl(MPI_File fh, MPI_Offset *offset);
int MPIR_File_get_position_shared_impl(MPI_File fh, MPI_Offset *offset);
int MPIR_File_get_size_impl(MPI_File fh, MPI_Offset *size);
int MPIR_File_get_type_extent_impl(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent);
int MPIR_File_get_view_impl(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep);
int MPIR_File_iread_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iread_all_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iread_at_impl(MPI_File fh, MPI_Offset offset, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iread_at_all_impl(MPI_File fh, MPI_Offset offset, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iread_shared_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iwrite_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iwrite_all_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iwrite_at_impl(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iwrite_at_all_impl(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_iwrite_shared_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Request *request);
int MPIR_File_open_impl(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh);
int MPIR_File_preallocate_impl(MPI_File fh, MPI_Offset size);
int MPIR_File_read_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_read_all_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_read_all_begin_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype);
int MPIR_File_read_all_end_impl(MPI_File fh, void *buf, MPI_Status *status);
int MPIR_File_read_at_impl(MPI_File fh, MPI_Offset offset, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_read_at_all_impl(MPI_File fh, MPI_Offset offset, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_read_at_all_begin_impl(MPI_File fh, MPI_Offset offset, void *buf, MPI_Aint count, MPI_Datatype datatype);
int MPIR_File_read_at_all_end_impl(MPI_File fh, void *buf, MPI_Status *status);
int MPIR_File_read_ordered_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_read_ordered_begin_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype);
int MPIR_File_read_ordered_end_impl(MPI_File fh, void *buf, MPI_Status *status);
int MPIR_File_read_shared_impl(MPI_File fh, void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_seek_impl(MPI_File fh, MPI_Offset offset, int whence);
int MPIR_File_seek_shared_impl(MPI_File fh, MPI_Offset offset, int whence);
int MPIR_File_set_atomicity_impl(MPI_File fh, int flag);
int MPIR_File_set_info_impl(MPI_File fh, MPI_Info info);
int MPIR_File_set_size_impl(MPI_File fh, MPI_Offset size);
int MPIR_File_set_view_impl(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info);
int MPIR_File_sync_impl(MPI_File fh);
int MPIR_File_write_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_write_all_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_write_all_begin_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype);
int MPIR_File_write_all_end_impl(MPI_File fh, const void *buf, MPI_Status *status);
int MPIR_File_write_at_impl(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_write_at_all_impl(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_write_at_all_begin_impl(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Aint count, MPI_Datatype datatype);
int MPIR_File_write_at_all_end_impl(MPI_File fh, const void *buf, MPI_Status *status);
int MPIR_File_write_ordered_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_File_write_ordered_begin_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype);
int MPIR_File_write_ordered_end_impl(MPI_File fh, const void *buf, MPI_Status *status);
int MPIR_File_write_shared_impl(MPI_File fh, const void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Status *status);
int MPIR_Register_datarep_impl(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
int MPIR_Register_datarep_large_impl(const char *datarep, MPI_Datarep_conversion_function_c *read_conversion_fn, MPI_Datarep_conversion_function_c *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

#endif /* MPIR_IO_IMPL_H_INCLUDED */
