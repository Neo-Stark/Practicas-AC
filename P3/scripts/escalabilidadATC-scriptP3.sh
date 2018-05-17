#! /bin/bash
#PBS -N escalabilidad
#PBS -q ac
for((i=1;i<13;i=i+1))
do
export OMP_NUM_THREADS=$i 
./pmm-OpenMP 750
printf '\n'
done
printf "\n\n"

for((i=1;i<13;i=i+1))
do
export OMP_NUM_THREADS=$i 
./pmm-OpenMP 1500
printf '\n'
done