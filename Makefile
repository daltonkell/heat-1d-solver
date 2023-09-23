# Makefile for heat1fdm

CXX=g++

# use if compiling with OpenMP
USEOMP=1
CXXFLAGS=-fopenmp

INCLUDE=./include
SRC=./src

# use if you want to print debugging output
DEBUG=0

# use if you want to write output data to file
WRITEOUT=1

heat1d.o: $(SRC)/heat1d.cpp
	$(CXX) $(CXXFLAGS) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -DWRITEOUT=$(WRITEOUT) -o heat1d.o $(SRC)/heat1d.cpp

algs.o: $(SRC)/algs.cpp
	$(CXX) $(CXXFLAGS) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -DWRITEOUT=$(WRITEOUT) -o algs.o $(SRC)/algs.cpp

heat: heat1d.o algs.o
	$(CXX) $(CXXFLAGS) -o heat heat1d.o algs.o

clean:
	rm -rf *.o heat
