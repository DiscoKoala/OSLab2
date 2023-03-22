#makefile for Lab 2 - Root folder

CC = gcc
CFLAGS = -g -Wall

main: main.cpp
	$(CC) $(CFLAGS) -o myscheduler main.cpp

clean:
	rm -f myscheduler main.o core