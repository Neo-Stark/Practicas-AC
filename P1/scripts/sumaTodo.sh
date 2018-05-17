#!/bin/bash

printf "Suma Sections \n"
for ((i=16384;i<=67108864;i=i*2))
do
./sumaSections $i
printf '\n'
done
printf "\n\n\n"
printf "Suma for \n"
for ((i=16384;i<=67108864;i=i*2))
do
./sumaFor $i
printf '\n'
done
printf "\n\n\n"
printf "Suma secuencial \n"
for ((i=16384;i<=67108864;i=i*2))
do
./sumaGlobal $i
printf '\n'
done