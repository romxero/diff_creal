#!/bin/sh 

echo "	heuristical building script " 
##use gcc to link

rm main.o main.bin
## first build line is for debugging 
gcc -g -c main.c -I/home/romxero/include -L/home/romxero/lib -lm
#~ gcc -O2 -g -c main.c -I/home/romxero/include -L/home/romxero/lib

gcc main.o -o main.bin
