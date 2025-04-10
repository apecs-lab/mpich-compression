#!/bin/bash

# Load necessary modules
module load gcc/11.2.0
module load python3/3.9.7
module load cuda/12.0
export CUDA_HOME=$TACC_CUDA_DIR
export CFLAGS="-I$CUDA_HOME/include"
export LDFLAGS="-L$CUDA_HOME/lib64"

cd /work/10127/jwang259/ls6/sw
cd mpich

./autogen.sh

./configure \
  --prefix=/work/10127/jwang259/ls6/sw/mpich-install \
  --with-device=ch4:ofi \
  --with-cuda=$CUDA_HOME \
  CC=gcc CXX=g++ \
  CFLAGS="-I$CUDA_HOME/include" \
  LDFLAGS="-L$CUDA_HOME/lib64 -Wl,-rpath=$CUDA_HOME/lib64 -Wl,--no-as-needed" \
  LIBS="-lcudart -lcuda -ldl" \
  2>&1 | tee configure.log
  
  # --enable-gpu \
  
# Compile
make -j 8 2>&1 | tee m.txt

# Install
make install 2>&1 | tee mi.txt

export PATH=/work/10127/jwang259/ls6/sw/mpich-install/bin:$PATH

# Verify
which mpicc
which mpiexec

echo "done"

