/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpichconf.h"
#include "io_abi_internal.h"
#include "mpir_io_impl.h"
#include <limits.h>

/* -- Begin Profiling Symbol Block for routine MPI_File_c2f */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_c2f = PMPI_File_c2f
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_c2f  MPI_File_c2f
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_c2f as PMPI_File_c2f
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Fint MPI_File_c2f(ABI_File file)  __attribute__ ((weak, alias("PMPI_File_c2f")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_c2f
#define MPI_File_c2f PMPI_File_c2f
#endif /* MPICH_MPI_FROM_PMPI */

MPI_Fint MPI_File_c2f(MPI_File file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return MPIR_File_c2f_impl(file);
#endif
}

/* -- Begin Profiling Symbol Block for routine MPI_File_close */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_close = PMPI_File_close
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_close  MPI_File_close
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_close as PMPI_File_close
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_close(ABI_File *fh)  __attribute__ ((weak, alias("PMPI_File_close")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_close
#define MPI_File_close PMPI_File_close
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_close(MPI_File *fh)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_close_impl(fh);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_delete */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_delete = PMPI_File_delete
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_delete  MPI_File_delete
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_delete as PMPI_File_delete
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_delete(const char *filename, ABI_Info info)
     __attribute__ ((weak, alias("PMPI_File_delete")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_delete
#define MPI_File_delete PMPI_File_delete
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_delete(const char *filename, MPI_Info info)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_delete_impl(filename, info);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_f2c = PMPI_File_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_f2c  MPI_File_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_f2c as PMPI_File_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_File MPI_File_f2c(ABI_Fint file)  __attribute__ ((weak, alias("PMPI_File_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_f2c
#define MPI_File_f2c PMPI_File_f2c
#endif /* MPICH_MPI_FROM_PMPI */

MPI_File MPI_File_f2c(MPI_Fint file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return MPIR_File_f2c_impl(file);
#endif
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_amode */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_amode = PMPI_File_get_amode
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_amode  MPI_File_get_amode
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_amode as PMPI_File_get_amode
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_amode(ABI_File fh, int *amode)
     __attribute__ ((weak, alias("PMPI_File_get_amode")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_amode
#define MPI_File_get_amode PMPI_File_get_amode
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_amode(MPI_File fh, int *amode)
{
    int mpi_errno = MPI_SUCCESS;

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_amode_impl(fh, amode);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_atomicity */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_atomicity = PMPI_File_get_atomicity
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_atomicity  MPI_File_get_atomicity
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_atomicity as PMPI_File_get_atomicity
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_atomicity(ABI_File fh, int *flag)
     __attribute__ ((weak, alias("PMPI_File_get_atomicity")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_atomicity
#define MPI_File_get_atomicity PMPI_File_get_atomicity
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_atomicity(MPI_File fh, int *flag)
{
    int mpi_errno = MPI_SUCCESS;

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_atomicity_impl(fh, flag);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_byte_offset */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_byte_offset = PMPI_File_get_byte_offset
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_byte_offset  MPI_File_get_byte_offset
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_byte_offset as PMPI_File_get_byte_offset
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_byte_offset(ABI_File fh, ABI_Offset offset, ABI_Offset *disp)
     __attribute__ ((weak, alias("PMPI_File_get_byte_offset")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_byte_offset
#define MPI_File_get_byte_offset PMPI_File_get_byte_offset
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
    int mpi_errno = MPI_SUCCESS;

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_byte_offset_impl(fh, offset, disp);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_group */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_group = PMPI_File_get_group
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_group  MPI_File_get_group
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_group as PMPI_File_get_group
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_group(ABI_File fh, ABI_Group *group)
     __attribute__ ((weak, alias("PMPI_File_get_group")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_group
#define MPI_File_get_group PMPI_File_get_group
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_group(MPI_File fh, MPI_Group *group)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_group_impl(fh, group);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_info = PMPI_File_get_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_info  MPI_File_get_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_info as PMPI_File_get_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_info(ABI_File fh, ABI_Info *info_used)
     __attribute__ ((weak, alias("PMPI_File_get_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_info
#define MPI_File_get_info PMPI_File_get_info
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_info_impl(fh, info_used);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_position */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_position = PMPI_File_get_position
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_position  MPI_File_get_position
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_position as PMPI_File_get_position
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_position(ABI_File fh, ABI_Offset *offset)
     __attribute__ ((weak, alias("PMPI_File_get_position")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_position
#define MPI_File_get_position PMPI_File_get_position
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_position_impl(fh, offset);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_position_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_position_shared = PMPI_File_get_position_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_position_shared  MPI_File_get_position_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_position_shared as PMPI_File_get_position_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_position_shared(ABI_File fh, ABI_Offset *offset)
     __attribute__ ((weak, alias("PMPI_File_get_position_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_position_shared
#define MPI_File_get_position_shared PMPI_File_get_position_shared
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_position_shared_impl(fh, offset);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_size */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_size = PMPI_File_get_size
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_size  MPI_File_get_size
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_size as PMPI_File_get_size
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_size(ABI_File fh, ABI_Offset *size)
     __attribute__ ((weak, alias("PMPI_File_get_size")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_size
#define MPI_File_get_size PMPI_File_get_size
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_size(MPI_File fh, MPI_Offset *size)
{
    int mpi_errno = MPI_SUCCESS;

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_size_impl(fh, size);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_type_extent */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_type_extent = PMPI_File_get_type_extent
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_type_extent  MPI_File_get_type_extent
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_type_extent as PMPI_File_get_type_extent
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_type_extent(ABI_File fh, ABI_Datatype datatype, ABI_Aint *extent)
     __attribute__ ((weak, alias("PMPI_File_get_type_extent")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_type_extent
#define MPI_File_get_type_extent PMPI_File_get_type_extent
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_type_extent_impl(fh, datatype, extent);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_type_extent_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_type_extent_c = PMPI_File_get_type_extent_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_type_extent_c  MPI_File_get_type_extent_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_type_extent_c as PMPI_File_get_type_extent_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_type_extent_c(ABI_File fh, ABI_Datatype datatype, ABI_Count *extent)
     __attribute__ ((weak, alias("PMPI_File_get_type_extent_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_type_extent_c
#define MPI_File_get_type_extent_c PMPI_File_get_type_extent_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_get_type_extent_impl(fh, datatype, (MPI_Aint *) extent);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint extent_c;
        mpi_errno = MPIR_File_get_type_extent_impl(fh, datatype, &extent_c);
        if (mpi_errno) {
            goto fn_fail;
        }
        *extent = extent_c;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_get_view */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_view = PMPI_File_get_view
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_view  MPI_File_get_view
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_view as PMPI_File_get_view
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_view(ABI_File fh, ABI_Offset *disp, ABI_Datatype *etype, ABI_Datatype *filetype,
                      char *datarep)  __attribute__ ((weak, alias("PMPI_File_get_view")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_view
#define MPI_File_get_view PMPI_File_get_view
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype,
                      char *datarep)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_view_impl(fh, disp, etype, filetype, datarep);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread = PMPI_File_iread
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread  MPI_File_iread
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread as PMPI_File_iread
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread(ABI_File fh, void *buf, int count, ABI_Datatype datatype, ABI_Request *request)
     __attribute__ ((weak, alias("PMPI_File_iread")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread
#define MPI_File_iread PMPI_File_iread
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_c = PMPI_File_iread_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_c  MPI_File_iread_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_c as PMPI_File_iread_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                     ABI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iread_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_c
#define MPI_File_iread_c PMPI_File_iread_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_all = PMPI_File_iread_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_all  MPI_File_iread_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_all as PMPI_File_iread_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_all(ABI_File fh, void *buf, int count, ABI_Datatype datatype,
                       ABI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iread_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_all
#define MPI_File_iread_all PMPI_File_iread_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_all_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_all_c = PMPI_File_iread_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_all_c  MPI_File_iread_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_all_c as PMPI_File_iread_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_all_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                         ABI_Request *request)
                          __attribute__ ((weak, alias("PMPI_File_iread_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_all_c
#define MPI_File_iread_all_c PMPI_File_iread_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_all_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_all_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at = PMPI_File_iread_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at  MPI_File_iread_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at as PMPI_File_iread_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at(ABI_File fh, ABI_Offset offset, void *buf, int count, ABI_Datatype datatype,
                      ABI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iread_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at
#define MPI_File_iread_at PMPI_File_iread_at
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                      MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_at_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at_c = PMPI_File_iread_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at_c  MPI_File_iread_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at_c as PMPI_File_iread_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at_c(ABI_File fh, ABI_Offset offset, void *buf, ABI_Count count,
                        ABI_Datatype datatype, ABI_Request *request)
                         __attribute__ ((weak, alias("PMPI_File_iread_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at_c
#define MPI_File_iread_at_c PMPI_File_iread_at_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_at_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at_all = PMPI_File_iread_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at_all  MPI_File_iread_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at_all as PMPI_File_iread_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at_all(ABI_File fh, ABI_Offset offset, void *buf, int count,
                          ABI_Datatype datatype, ABI_Request *request)
                           __attribute__ ((weak, alias("PMPI_File_iread_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at_all
#define MPI_File_iread_at_all PMPI_File_iread_at_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_at_all_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at_all_c = PMPI_File_iread_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at_all_c  MPI_File_iread_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at_all_c as PMPI_File_iread_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at_all_c(ABI_File fh, ABI_Offset offset, void *buf, ABI_Count count,
                            ABI_Datatype datatype, ABI_Request *request)
                             __attribute__ ((weak, alias("PMPI_File_iread_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at_all_c
#define MPI_File_iread_at_all_c PMPI_File_iread_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_at_all_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_shared = PMPI_File_iread_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_shared  MPI_File_iread_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_shared as PMPI_File_iread_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_shared(ABI_File fh, void *buf, int count, ABI_Datatype datatype,
                          ABI_Request *request)
                           __attribute__ ((weak, alias("PMPI_File_iread_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_shared
#define MPI_File_iread_shared PMPI_File_iread_shared
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_shared_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_shared_c = PMPI_File_iread_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_shared_c  MPI_File_iread_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_shared_c as PMPI_File_iread_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_shared_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                            ABI_Request *request)
                             __attribute__ ((weak, alias("PMPI_File_iread_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_shared_c
#define MPI_File_iread_shared_c PMPI_File_iread_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_shared_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_shared_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite = PMPI_File_iwrite
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite  MPI_File_iwrite
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite as PMPI_File_iwrite
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                    ABI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iwrite")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite
#define MPI_File_iwrite PMPI_File_iwrite
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_c = PMPI_File_iwrite_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_c  MPI_File_iwrite_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_c as PMPI_File_iwrite_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                      ABI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iwrite_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_c
#define MPI_File_iwrite_c PMPI_File_iwrite_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                      MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_all = PMPI_File_iwrite_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_all  MPI_File_iwrite_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_all as PMPI_File_iwrite_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_all(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                        ABI_Request *request)
                         __attribute__ ((weak, alias("PMPI_File_iwrite_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_all
#define MPI_File_iwrite_all PMPI_File_iwrite_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                        MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_all_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_all_c = PMPI_File_iwrite_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_all_c  MPI_File_iwrite_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_all_c as PMPI_File_iwrite_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_all_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                          ABI_Request *request)
                           __attribute__ ((weak, alias("PMPI_File_iwrite_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_all_c
#define MPI_File_iwrite_all_c PMPI_File_iwrite_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_all_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_all_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at = PMPI_File_iwrite_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at  MPI_File_iwrite_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at as PMPI_File_iwrite_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at(ABI_File fh, ABI_Offset offset, const void *buf, int count,
                       ABI_Datatype datatype, ABI_Request *request)
                        __attribute__ ((weak, alias("PMPI_File_iwrite_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at
#define MPI_File_iwrite_at PMPI_File_iwrite_at
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                       MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_at_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at_c = PMPI_File_iwrite_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at_c  MPI_File_iwrite_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at_c as PMPI_File_iwrite_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at_c(ABI_File fh, ABI_Offset offset, const void *buf, ABI_Count count,
                         ABI_Datatype datatype, ABI_Request *request)
                          __attribute__ ((weak, alias("PMPI_File_iwrite_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at_c
#define MPI_File_iwrite_at_c PMPI_File_iwrite_at_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_at_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at_all = PMPI_File_iwrite_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at_all  MPI_File_iwrite_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at_all as PMPI_File_iwrite_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at_all(ABI_File fh, ABI_Offset offset, const void *buf, int count,
                           ABI_Datatype datatype, ABI_Request *request)
                            __attribute__ ((weak, alias("PMPI_File_iwrite_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at_all
#define MPI_File_iwrite_at_all PMPI_File_iwrite_at_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_at_all_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at_all_c = PMPI_File_iwrite_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at_all_c  MPI_File_iwrite_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at_all_c as PMPI_File_iwrite_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at_all_c(ABI_File fh, ABI_Offset offset, const void *buf, ABI_Count count,
                             ABI_Datatype datatype, ABI_Request *request)
                              __attribute__ ((weak, alias("PMPI_File_iwrite_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at_all_c
#define MPI_File_iwrite_at_all_c PMPI_File_iwrite_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_at_all_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_shared = PMPI_File_iwrite_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_shared  MPI_File_iwrite_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_shared as PMPI_File_iwrite_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_shared(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                           ABI_Request *request)
                            __attribute__ ((weak, alias("PMPI_File_iwrite_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_shared
#define MPI_File_iwrite_shared PMPI_File_iwrite_shared
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_shared_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_shared_c = PMPI_File_iwrite_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_shared_c  MPI_File_iwrite_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_shared_c as PMPI_File_iwrite_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_shared_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                             ABI_Request *request)
                              __attribute__ ((weak, alias("PMPI_File_iwrite_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_shared_c
#define MPI_File_iwrite_shared_c PMPI_File_iwrite_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_shared_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_shared_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_open */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_open = PMPI_File_open
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_open  MPI_File_open
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_open as PMPI_File_open
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_open(ABI_Comm comm, const char *filename, int amode, ABI_Info info, ABI_File *fh)
     __attribute__ ((weak, alias("PMPI_File_open")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_open
#define MPI_File_open PMPI_File_open
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_open_impl(comm, filename, amode, info, fh);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_preallocate */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_preallocate = PMPI_File_preallocate
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_preallocate  MPI_File_preallocate
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_preallocate as PMPI_File_preallocate
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_preallocate(ABI_File fh, ABI_Offset size)
     __attribute__ ((weak, alias("PMPI_File_preallocate")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_preallocate
#define MPI_File_preallocate PMPI_File_preallocate
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_preallocate_impl(fh, size);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read = PMPI_File_read
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read  MPI_File_read
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read as PMPI_File_read
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read(ABI_File fh, void *buf, int count, ABI_Datatype datatype, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read
#define MPI_File_read PMPI_File_read
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_c = PMPI_File_read_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_c  MPI_File_read_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_c as PMPI_File_read_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                    ABI_Status *status)  __attribute__ ((weak, alias("PMPI_File_read_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_c
#define MPI_File_read_c PMPI_File_read_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                    MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all = PMPI_File_read_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all  MPI_File_read_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all as PMPI_File_read_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all(ABI_File fh, void *buf, int count, ABI_Datatype datatype, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all
#define MPI_File_read_all PMPI_File_read_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_all_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_c = PMPI_File_read_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_c  MPI_File_read_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_c as PMPI_File_read_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                        ABI_Status *status)  __attribute__ ((weak, alias("PMPI_File_read_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_c
#define MPI_File_read_all_c PMPI_File_read_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                        MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_all_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_all_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_begin = PMPI_File_read_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_begin  MPI_File_read_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_begin as PMPI_File_read_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_begin(ABI_File fh, void *buf, int count, ABI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_begin
#define MPI_File_read_all_begin PMPI_File_read_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_all_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_begin_c = PMPI_File_read_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_begin_c  MPI_File_read_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_begin_c as PMPI_File_read_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_begin_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_begin_c
#define MPI_File_read_all_begin_c PMPI_File_read_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_all_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_all_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_end = PMPI_File_read_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_end  MPI_File_read_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_end as PMPI_File_read_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_end(ABI_File fh, void *buf, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_end
#define MPI_File_read_all_end PMPI_File_read_all_end
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at = PMPI_File_read_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at  MPI_File_read_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at as PMPI_File_read_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at(ABI_File fh, ABI_Offset offset, void *buf, int count, ABI_Datatype datatype,
                     ABI_Status *status)  __attribute__ ((weak, alias("PMPI_File_read_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at
#define MPI_File_read_at PMPI_File_read_at
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                     MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_c = PMPI_File_read_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_c  MPI_File_read_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_c as PMPI_File_read_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_c(ABI_File fh, ABI_Offset offset, void *buf, ABI_Count count,
                       ABI_Datatype datatype, ABI_Status *status)
                        __attribute__ ((weak, alias("PMPI_File_read_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_c
#define MPI_File_read_at_c PMPI_File_read_at_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                       MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_at_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all = PMPI_File_read_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all  MPI_File_read_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all as PMPI_File_read_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all(ABI_File fh, ABI_Offset offset, void *buf, int count,
                         ABI_Datatype datatype, ABI_Status *status)
                          __attribute__ ((weak, alias("PMPI_File_read_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all
#define MPI_File_read_at_all PMPI_File_read_at_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_all_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_c = PMPI_File_read_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_c  MPI_File_read_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_c as PMPI_File_read_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_c(ABI_File fh, ABI_Offset offset, void *buf, ABI_Count count,
                           ABI_Datatype datatype, ABI_Status *status)
                            __attribute__ ((weak, alias("PMPI_File_read_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_c
#define MPI_File_read_at_all_c PMPI_File_read_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_at_all_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_begin = PMPI_File_read_at_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_begin  MPI_File_read_at_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_begin as PMPI_File_read_at_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_begin(ABI_File fh, ABI_Offset offset, void *buf, int count,
                               ABI_Datatype datatype)
                                __attribute__ ((weak, alias("PMPI_File_read_at_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_begin
#define MPI_File_read_at_all_begin PMPI_File_read_at_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count,
                               MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_all_begin_impl(fh, offset, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_begin_c = PMPI_File_read_at_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_begin_c  MPI_File_read_at_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_begin_c as PMPI_File_read_at_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_begin_c(ABI_File fh, ABI_Offset offset, void *buf, ABI_Count count,
                                 ABI_Datatype datatype)
                                  __attribute__ ((weak, alias("PMPI_File_read_at_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_begin_c
#define MPI_File_read_at_all_begin_c PMPI_File_read_at_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                 MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_at_all_begin_impl(fh, offset, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_at_all_begin_impl(fh, offset, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_end = PMPI_File_read_at_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_end  MPI_File_read_at_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_end as PMPI_File_read_at_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_end(ABI_File fh, void *buf, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_at_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_end
#define MPI_File_read_at_all_end PMPI_File_read_at_all_end
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered = PMPI_File_read_ordered
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered  MPI_File_read_ordered
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered as PMPI_File_read_ordered
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered(ABI_File fh, void *buf, int count, ABI_Datatype datatype,
                          ABI_Status *status)
                           __attribute__ ((weak, alias("PMPI_File_read_ordered")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered
#define MPI_File_read_ordered PMPI_File_read_ordered
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_ordered_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_c = PMPI_File_read_ordered_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_c  MPI_File_read_ordered_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_c as PMPI_File_read_ordered_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                            ABI_Status *status)
                             __attribute__ ((weak, alias("PMPI_File_read_ordered_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_c
#define MPI_File_read_ordered_c PMPI_File_read_ordered_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_ordered_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_ordered_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_begin = PMPI_File_read_ordered_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_begin  MPI_File_read_ordered_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_begin as PMPI_File_read_ordered_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_begin(ABI_File fh, void *buf, int count, ABI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_ordered_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_begin
#define MPI_File_read_ordered_begin PMPI_File_read_ordered_begin
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_ordered_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_begin_c = PMPI_File_read_ordered_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_begin_c  MPI_File_read_ordered_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_begin_c as PMPI_File_read_ordered_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_begin_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_ordered_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_begin_c
#define MPI_File_read_ordered_begin_c PMPI_File_read_ordered_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_ordered_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_ordered_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_end = PMPI_File_read_ordered_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_end  MPI_File_read_ordered_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_end as PMPI_File_read_ordered_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_end(ABI_File fh, void *buf, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_ordered_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_end
#define MPI_File_read_ordered_end PMPI_File_read_ordered_end
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_ordered_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_shared = PMPI_File_read_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_shared  MPI_File_read_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_shared as PMPI_File_read_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_shared(ABI_File fh, void *buf, int count, ABI_Datatype datatype,
                         ABI_Status *status)
                          __attribute__ ((weak, alias("PMPI_File_read_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_shared
#define MPI_File_read_shared PMPI_File_read_shared
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_shared_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_read_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_shared_c = PMPI_File_read_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_shared_c  MPI_File_read_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_shared_c as PMPI_File_read_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_shared_c(ABI_File fh, void *buf, ABI_Count count, ABI_Datatype datatype,
                           ABI_Status *status)
                            __attribute__ ((weak, alias("PMPI_File_read_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_shared_c
#define MPI_File_read_shared_c PMPI_File_read_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                           MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_shared_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_shared_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_seek */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_seek = PMPI_File_seek
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_seek  MPI_File_seek
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_seek as PMPI_File_seek
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_seek(ABI_File fh, ABI_Offset offset, int whence)
     __attribute__ ((weak, alias("PMPI_File_seek")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_seek
#define MPI_File_seek PMPI_File_seek
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_seek_impl(fh, offset, whence);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_seek_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_seek_shared = PMPI_File_seek_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_seek_shared  MPI_File_seek_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_seek_shared as PMPI_File_seek_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_seek_shared(ABI_File fh, ABI_Offset offset, int whence)
     __attribute__ ((weak, alias("PMPI_File_seek_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_seek_shared
#define MPI_File_seek_shared PMPI_File_seek_shared
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_seek_shared_impl(fh, offset, whence);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_set_atomicity */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_atomicity = PMPI_File_set_atomicity
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_atomicity  MPI_File_set_atomicity
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_atomicity as PMPI_File_set_atomicity
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_atomicity(ABI_File fh, int flag)
     __attribute__ ((weak, alias("PMPI_File_set_atomicity")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_atomicity
#define MPI_File_set_atomicity PMPI_File_set_atomicity
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_set_atomicity(MPI_File fh, int flag)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_atomicity_impl(fh, flag);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_set_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_info = PMPI_File_set_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_info  MPI_File_set_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_info as PMPI_File_set_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_info(ABI_File fh, ABI_Info info)
     __attribute__ ((weak, alias("PMPI_File_set_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_info
#define MPI_File_set_info PMPI_File_set_info
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_set_info(MPI_File fh, MPI_Info info)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_info_impl(fh, info);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_set_size */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_size = PMPI_File_set_size
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_size  MPI_File_set_size
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_size as PMPI_File_set_size
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_size(ABI_File fh, ABI_Offset size)
     __attribute__ ((weak, alias("PMPI_File_set_size")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_size
#define MPI_File_set_size PMPI_File_set_size
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_set_size(MPI_File fh, MPI_Offset size)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_size_impl(fh, size);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_set_view */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_view = PMPI_File_set_view
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_view  MPI_File_set_view
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_view as PMPI_File_set_view
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_view(ABI_File fh, ABI_Offset disp, ABI_Datatype etype, ABI_Datatype filetype,
                      const char *datarep, ABI_Info info)
                       __attribute__ ((weak, alias("PMPI_File_set_view")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_view
#define MPI_File_set_view PMPI_File_set_view
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype,
                      const char *datarep, MPI_Info info)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_view_impl(fh, disp, etype, filetype, datarep, info);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_sync */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync = PMPI_File_sync
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync  MPI_File_sync
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync as PMPI_File_sync
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync(ABI_File fh)  __attribute__ ((weak, alias("PMPI_File_sync")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_sync
#define MPI_File_sync PMPI_File_sync
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_sync(MPI_File fh)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_sync_impl(fh);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write = PMPI_File_write
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write  MPI_File_write
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write as PMPI_File_write
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                   ABI_Status *status)  __attribute__ ((weak, alias("PMPI_File_write")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write
#define MPI_File_write PMPI_File_write
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_c = PMPI_File_write_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_c  MPI_File_write_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_c as PMPI_File_write_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                     ABI_Status *status)  __attribute__ ((weak, alias("PMPI_File_write_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_c
#define MPI_File_write_c PMPI_File_write_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all = PMPI_File_write_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all  MPI_File_write_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all as PMPI_File_write_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                       ABI_Status *status)  __attribute__ ((weak, alias("PMPI_File_write_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all
#define MPI_File_write_all PMPI_File_write_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_all_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_c = PMPI_File_write_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_c  MPI_File_write_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_c as PMPI_File_write_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                         ABI_Status *status)
                          __attribute__ ((weak, alias("PMPI_File_write_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_c
#define MPI_File_write_all_c PMPI_File_write_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_all_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_all_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_begin = PMPI_File_write_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_begin  MPI_File_write_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_begin as PMPI_File_write_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_begin(ABI_File fh, const void *buf, int count, ABI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_write_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_begin
#define MPI_File_write_all_begin PMPI_File_write_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_all_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_begin_c = PMPI_File_write_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_begin_c  MPI_File_write_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_begin_c as PMPI_File_write_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_begin_c(ABI_File fh, const void *buf, ABI_Count count,
                               ABI_Datatype datatype)
                                __attribute__ ((weak, alias("PMPI_File_write_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_begin_c
#define MPI_File_write_all_begin_c PMPI_File_write_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                               MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_all_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_all_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_end = PMPI_File_write_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_end  MPI_File_write_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_end as PMPI_File_write_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_end(ABI_File fh, const void *buf, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_write_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_end
#define MPI_File_write_all_end PMPI_File_write_all_end
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at = PMPI_File_write_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at  MPI_File_write_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at as PMPI_File_write_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at(ABI_File fh, ABI_Offset offset, const void *buf, int count,
                      ABI_Datatype datatype, ABI_Status *status)
                       __attribute__ ((weak, alias("PMPI_File_write_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at
#define MPI_File_write_at PMPI_File_write_at
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_c = PMPI_File_write_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_c  MPI_File_write_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_c as PMPI_File_write_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_c(ABI_File fh, ABI_Offset offset, const void *buf, ABI_Count count,
                        ABI_Datatype datatype, ABI_Status *status)
                         __attribute__ ((weak, alias("PMPI_File_write_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_c
#define MPI_File_write_at_c PMPI_File_write_at_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_at_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all = PMPI_File_write_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all  MPI_File_write_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all as PMPI_File_write_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all(ABI_File fh, ABI_Offset offset, const void *buf, int count,
                          ABI_Datatype datatype, ABI_Status *status)
                           __attribute__ ((weak, alias("PMPI_File_write_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all
#define MPI_File_write_at_all PMPI_File_write_at_all
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_all_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_c = PMPI_File_write_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_c  MPI_File_write_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_c as PMPI_File_write_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_c(ABI_File fh, ABI_Offset offset, const void *buf, ABI_Count count,
                            ABI_Datatype datatype, ABI_Status *status)
                             __attribute__ ((weak, alias("PMPI_File_write_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_c
#define MPI_File_write_at_all_c PMPI_File_write_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_at_all_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_begin = PMPI_File_write_at_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_begin  MPI_File_write_at_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_begin as PMPI_File_write_at_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_begin(ABI_File fh, ABI_Offset offset, const void *buf, int count,
                                ABI_Datatype datatype)
                                 __attribute__ ((weak, alias("PMPI_File_write_at_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_begin
#define MPI_File_write_at_all_begin PMPI_File_write_at_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_all_begin_impl(fh, offset, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_begin_c = PMPI_File_write_at_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_begin_c  MPI_File_write_at_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_begin_c as PMPI_File_write_at_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_begin_c(ABI_File fh, ABI_Offset offset, const void *buf, ABI_Count count,
                                  ABI_Datatype datatype)
                                   __attribute__ ((weak, alias("PMPI_File_write_at_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_begin_c
#define MPI_File_write_at_all_begin_c PMPI_File_write_at_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                                  MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_at_all_begin_impl(fh, offset, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_at_all_begin_impl(fh, offset, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_end = PMPI_File_write_at_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_end  MPI_File_write_at_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_end as PMPI_File_write_at_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_end(ABI_File fh, const void *buf, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_write_at_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_end
#define MPI_File_write_at_all_end PMPI_File_write_at_all_end
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered = PMPI_File_write_ordered
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered  MPI_File_write_ordered
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered as PMPI_File_write_ordered
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                           ABI_Status *status)
                            __attribute__ ((weak, alias("PMPI_File_write_ordered")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered
#define MPI_File_write_ordered PMPI_File_write_ordered
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_ordered_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_c = PMPI_File_write_ordered_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_c  MPI_File_write_ordered_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_c as PMPI_File_write_ordered_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                             ABI_Status *status)
                              __attribute__ ((weak, alias("PMPI_File_write_ordered_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_c
#define MPI_File_write_ordered_c PMPI_File_write_ordered_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_ordered_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_ordered_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_begin = PMPI_File_write_ordered_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_begin  MPI_File_write_ordered_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_begin as PMPI_File_write_ordered_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_begin(ABI_File fh, const void *buf, int count, ABI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_write_ordered_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_begin
#define MPI_File_write_ordered_begin PMPI_File_write_ordered_begin
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_ordered_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_begin_c = PMPI_File_write_ordered_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_begin_c  MPI_File_write_ordered_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_begin_c as PMPI_File_write_ordered_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_begin_c(ABI_File fh, const void *buf, ABI_Count count,
                                   ABI_Datatype datatype)
                                    __attribute__ ((weak, alias("PMPI_File_write_ordered_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_begin_c
#define MPI_File_write_ordered_begin_c PMPI_File_write_ordered_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                                   MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_ordered_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_ordered_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_end = PMPI_File_write_ordered_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_end  MPI_File_write_ordered_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_end as PMPI_File_write_ordered_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_end(ABI_File fh, const void *buf, ABI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_write_ordered_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_end
#define MPI_File_write_ordered_end PMPI_File_write_ordered_end
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_ordered_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_shared = PMPI_File_write_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_shared  MPI_File_write_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_shared as PMPI_File_write_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_shared(ABI_File fh, const void *buf, int count, ABI_Datatype datatype,
                          ABI_Status *status)
                           __attribute__ ((weak, alias("PMPI_File_write_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_shared
#define MPI_File_write_shared PMPI_File_write_shared
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_shared_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_write_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_shared_c = PMPI_File_write_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_shared_c  MPI_File_write_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_shared_c as PMPI_File_write_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_shared_c(ABI_File fh, const void *buf, ABI_Count count, ABI_Datatype datatype,
                            ABI_Status *status)
                             __attribute__ ((weak, alias("PMPI_File_write_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_shared_c
#define MPI_File_write_shared_c PMPI_File_write_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_shared_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_shared_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_Register_datarep */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Register_datarep = PMPI_Register_datarep
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Register_datarep  MPI_Register_datarep
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Register_datarep as PMPI_Register_datarep
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Register_datarep(const char *datarep, ABI_Datarep_conversion_function *read_conversion_fn,
                         ABI_Datarep_conversion_function *write_conversion_fn,
                         ABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
                          __attribute__ ((weak, alias("PMPI_Register_datarep")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Register_datarep
#define MPI_Register_datarep PMPI_Register_datarep
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    mpi_errno = MPIR_Register_datarep_impl(datarep, read_conversion_fn, write_conversion_fn,
                                           dtype_file_extent_fn, extra_state);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_Register_datarep_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Register_datarep_c = PMPI_Register_datarep_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Register_datarep_c  MPI_Register_datarep_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Register_datarep_c as PMPI_Register_datarep_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Register_datarep_c(const char *datarep,
                           ABI_Datarep_conversion_function_c *read_conversion_fn,
                           ABI_Datarep_conversion_function_c *write_conversion_fn,
                           ABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
                            __attribute__ ((weak, alias("PMPI_Register_datarep_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Register_datarep_c
#define MPI_Register_datarep_c PMPI_Register_datarep_c
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_Register_datarep_c(const char *datarep,
                           MPI_Datarep_conversion_function_c *read_conversion_fn,
                           MPI_Datarep_conversion_function_c *write_conversion_fn,
                           MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Ext_cs_enter();

#ifndef HAVE_ROMIO
    mpi_errno = MPI_ERR_INTERN;
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Register_datarep_large_impl(datarep, read_conversion_fn, write_conversion_fn,
                                                     dtype_file_extent_fn, extra_state);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        mpi_errno = MPIR_Register_datarep_large_impl(datarep, read_conversion_fn, write_conversion_fn,
                                                     dtype_file_extent_fn, extra_state);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif

  fn_exit:
    MPIR_Ext_cs_exit();
    return mpi_errno;
  fn_fail:
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    goto fn_exit;
}

/* -- Begin Profiling Symbol Block for routine MPI_File_toint */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_toint = PMPI_File_toint
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_toint  MPI_File_toint
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_toint as PMPI_File_toint
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_toint(ABI_File file)  __attribute__ ((weak, alias("PMPI_File_toint")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_toint
#define MPI_File_toint PMPI_File_toint
#endif /* MPICH_MPI_FROM_PMPI */

int MPI_File_toint(MPI_File file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return (int) MPIR_File_c2f_impl(file);
#endif
}

/* -- Begin Profiling Symbol Block for routine MPI_File_fromint */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_fromint = PMPI_File_fromint
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_fromint  MPI_File_fromint
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_fromint as PMPI_File_fromint
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_File MPI_File_fromint(int file)  __attribute__ ((weak, alias("PMPI_File_fromint")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_fromint
#define MPI_File_fromint PMPI_File_fromint
#endif /* MPICH_MPI_FROM_PMPI */

MPI_File MPI_File_fromint(int file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return MPIR_File_f2c_impl(file);
#endif
}

