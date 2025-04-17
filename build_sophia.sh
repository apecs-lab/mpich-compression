#!/bin/bash

# Load necessary modules
export CFLAGS="-I/usr/local/cuda/include"
export LDFLAGS="-L/usr/local/cuda/lib64"
export LIBS="-lcudart -lcuda -ldl"
export LIBRARY_PATH=/grand/sbi-fair/Jiamin/sw/cuSZp/install/lib64:$LIBRARY_PATH
export LD_LIBRARY_PATH=/grand/sbi-fair/Jiamin/sw/cuSZp/install/lib64:$LD_LIBRARY_PATH

cd /grand/sbi-fair/Jiamin/sw
cd mpich-compression/

./autogen.sh 

./configure   
    --prefix=/grand/sbi-fair/Jiamin/sw/mpich-install   
    --with-device=ch4:ofi   
    --with-cuda=/usr/local/cuda   
    --with-cuszp=/grand/sbi-fair/Jiamin/sw/cuSZp/install   
    CC=gcc CXX=g++

make 2>&1 | tee m.txt