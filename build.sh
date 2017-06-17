#!/bin/sh 

echo "heuristical building script\n" 
##use gcc to link

gcc -c main.c 

gcc main.o -o main.bin
