PROG=simulator
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all

all:
		$(CC) $(CPPFLAGS) sim.cpp -o $(PROG)

clean:
		rm -f *.o $(PROG) core
