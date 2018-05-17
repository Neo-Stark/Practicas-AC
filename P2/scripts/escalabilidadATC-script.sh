#! /bin/bash
for((i=1;i<13;i=i+1))
do
export OMP_NUM_THREADS=$i 
./pmv-OpenMP-a 50000
printf '\n'
done
printf '\n'
printf '\n'

for((i=1;i<13;i=i+1))
do
export OMP_NUM_THREADS=$i 
./pmv-OpenMP-a 25000
printf '\n'
done