#!/bin/bash
#PBS -N salida
#PBS -q ac


export OMP_NUM_THREADS=12
for((i=0;i<2;i=i+1))
do
  echo "Iteracion $i"
  export OMP_SCHEDULE="static"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="dynamic"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="guided"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="static,1"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="dynamic,1"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="guided,1"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="static,64"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="dynamic,64"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  export OMP_SCHEDULE="guided,64"
  $PBS_O_WORKDIR/pmtv-OpenMP 30720
  printf "\n\n"
done