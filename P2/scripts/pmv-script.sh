#! /bin/bash

for((i=100;i<10000;i=i+100))
do
./pmv-OpenMP-a $i
printf '\n'
done
printf "\n\n\n"
for((i=100;i<10000;i=i+100))
do
./pmv-OpenMP-b $i
printf '\n'
done
printf "\n\n\n"
for((i=100;i<10000;i=i+100))
do
./pmv-OpenMP-reduction $i
printf '\n'
done
