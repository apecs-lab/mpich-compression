
#!/usr/bin/env bash

cd /grand/sbi-fair/Jiamin/sw/osu-micro-benchmarks-7.5-1/c/mpi/collective/blocking

cd /grand/sbi-fair/Jiamin/sw/mpich-compression

./autogen.sh

./configure \
  --prefix=/grand/sbi-fair/Jiamin/sw/mpich-install \
  --with-device=ch4:ofi \
  2>&1 | tee configure.log


make -j 2>&1 | tee m.txt