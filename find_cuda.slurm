#!/bin/bash
#SBATCH -J find-cuda
#SBATCH -o find.out
#SBATCH -e find.err
#SBATCH -p development
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:05:00
#SBATCH -A CCR23028

module purge
module load gcc/11.2.0

echo "Searching for libcudart.so on compute node:"
find /opt/apps -name "libcudart.so" 2>/dev/null
