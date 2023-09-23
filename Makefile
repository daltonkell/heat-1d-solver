# Makefile for heat1fdm

CXX=g++

# use if compiling with OpenMP
USEOMP=1
CXXFLAGS=-fopenmp

INCLUDE=./include
SRC=./src
DEBUG=0

heat1d.o: $(SRC)/heat1d.cpp
	$(CXX) $(CXXFLAGS) -Wall -c -I$(INCLUDE) -o heat1d.o $(SRC)/heat1d.cpp

algs.o: $(SRC)/algs.cpp
	$(CXX) $(CXXFLAGS) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -o algs.o $(SRC)/algs.cpp

heat: heat1d.o algs.o
	$(CXX) $(CXXFLAGS) -o heat heat1d.o algs.o

clean:
	rm -rf *.o heat
