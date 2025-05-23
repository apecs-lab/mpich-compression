#!/bin/sh
#
# Copyright (C) 2018, Northwestern University
# See COPYRIGHT notice in top-level directory.
#

# Exit immediately if a command exits with a non-zero status.
set -e
# Below line turn on echo mode
# set -x

prefix=/grand/sbi-fair/Jiamin/sw/mpich-install
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
mpirun="${bindir}/mpiexec"

# valgrind_opt="libtool --mode=execute valgrind --quiet --leak-check=full"

exe_name=`basename $1`

FILENAME="romio_test"_$exe_name

rm -f ${FILENAME}*

if test "x$exe_name" = xfile_info ; then
   for fs in testfs ufs nfs ; do
       if [ $fs = "testfs" ] ; then
          $mpirun -np 4 ${valgrind_opt} $1 -fname $FILENAME
       elif [ $fs = "ufs" ] ; then
          $mpirun -np 4 ${valgrind_opt} $1 -u -fname $FILENAME
       elif [ $fs = "gpfs" ] ; then
          $mpirun -np 4 ${valgrind_opt} $1 -b -fname $FILENAME
       elif [ $fs = "lustre" ] ; then
          $mpirun -np 4 ${valgrind_opt} $1 -l -fname $FILENAME
       fi
    done
elif test "x$exe_name" = xaggregation1 ; then
   $mpirun -np 4 ${valgrind_opt} ./aggregation1 -h -f $FILENAME
elif test "x$exe_name" = xperf ; then
   # $mpirun -np 4 ${valgrind_opt} $1 -h -f $FILENAME
   echo "skip testing $1"
elif test "x$exe_name" = xcoll_perf ; then
   # $mpirun -np 4 ${valgrind_opt} $1 -h -f $FILENAME
   echo "skip testing $1"
elif test "x$exe_name" = xlarge_array ; then
   # $mpirun -np 4 ${valgrind_opt} $1 -h -f $FILENAME
   echo "skip testing $1"
elif test "x$exe_name" = xlarge_file ; then
   # $mpirun -np 4 ${valgrind_opt} $1 -h -f $FILENAME
   echo "skip testing $1"
elif test "x$exe_name" = xexternal32 ; then
   echo "skip testing $1"
elif test "x$exe_name" = xnoncontig ; then
   $mpirun -np 2 ${valgrind_opt} $1 -fname $FILENAME
elif test "x$exe_name" = xi_noncontig ; then
   $mpirun -np 2 ${valgrind_opt} $1 -fname $FILENAME
elif test "x$exe_name" = xnoncontig_coll ; then
   $mpirun -np 2 ${valgrind_opt} $1 -fname $FILENAME
elif test "x$exe_name" = xsyshints ; then
   $mpirun -np 1 ${valgrind_opt} $1 -fname $srcdir/test_hintfile
elif test "x$exe_name" = xtypes_with_zeros ; then
   $mpirun -np 2 ${valgrind_opt} $1 -fname $FILENAME
else
   $mpirun -np 4 ${valgrind_opt} $1 -fname $FILENAME
fi

rm -f $FILENAME*

