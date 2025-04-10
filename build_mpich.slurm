#!/bin/bash
#SBATCH -J build-mpich
#SBATCH -o build.out
#SBATCH -e build.err
#SBATCH -p development
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:30:00
#SBATCH -A CCR23028

echo "==[ SLURM JOB STARTED ]=="
date
hostname

# Load compiler module
module purge
module load gcc/11.2.0

# Manually set CUDA environment
export CUDA_HOME=/opt/apps/cuda/12.0
export PATH=$CUDA_HOME/bin:$PATH
export LD_LIBRARY_PATH=$CUDA_HOME/lib64:$LD_LIBRARY_PATH

# Print debug info
echo "GCC: $(which gcc)"
echo "CUDA_HOME: $CUDA_HOME"
echo "LD_LIBRARY_PATH: $LD_LIBRARY_PATH"

# Debug: check libcudart in compute node
echo "==[ Checking CUDA library files... ]=="
ls -l $CUDA_HOME/lib64/ | grep libcudart || echo "⚠️ libcudart not listed in lib64"
ls -l $CUDA_HOME/lib64/libcudart.so || echo "⚠️ libcudart.so not directly accessible"
readlink -f $CUDA_HOME/lib64/libcudart.so || echo "⚠️ libcudart.so link is broken"
echo "==[ End of check ]=="

# Check if libcudart.so exists
if [[ ! -f "$CUDA_HOME/lib64/libcudart.so" ]]; then
  echo "❌ ERROR: libcudart.so not found in $CUDA_HOME/lib64" >&2
  exit 1
fi

# Go to MPICH source dir
cd /work/10127/jwang259/ls6/sw/mpich

# Configure MPICH with CUDA
./configure \
  --prefix=/work/10127/jwang259/ls6/sw/mpich-install \
  --with-device=ch4:ofi \
  --with-cuda=$CUDA_HOME \
  --disable-fortran \
  CC=gcc CXX=g++ \
  CFLAGS="-I$CUDA_HOME/include" \
  LDFLAGS="-L$CUDA_HOME/lib64 -L$CUDA_HOME/lib64/stubs -Wl,-rpath=$CUDA_HOME/lib64 -Wl,--no-as-needed" \
  LIBS="-lcudart -lcuda -ldl"

echo "==[ DONE ]=="
date


