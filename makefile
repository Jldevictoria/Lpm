all: lpm

lpm: lpm.c lpm.h
	gcc -c -Wall -Werror -fpic lpm.c
	gcc -shared -o lpm.so lpm.o
