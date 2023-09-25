# Makefile for heat1fdm

CXX=g++
CXXFLAGS=

# use if compiling with OpenMP
USEOMP=$(SET_USEOMP)
ifeq ($(USEOMP), 1)
	CXXFLAGS += -fopenmp
endif

INCLUDE=./include
SRC=./src

# use 1 if you want to print debugging output, 0 otherwise
DEBUG=$(SET_DEBUG)

# use 1 if you want to write output data to file, 0 otherwise
WRITEOUT=$(SET_WRITEOUT)


heat1d.o: $(SRC)/heat1d.cpp
	$(CXX) $(CXXFLAGS) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -DWRITEOUT=$(WRITEOUT) -o heat1d.o $(SRC)/heat1d.cpp

algs.o: $(SRC)/algs.cpp
	$(CXX) $(CXXFLAGS) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -DWRITEOUT=$(WRITEOUT) -o algs.o $(SRC)/algs.cpp

heat: heat1d.o algs.o
	$(CXX) $(CXXFLAGS) -o heat heat1d.o algs.o

clean:
	rm -rf *.o heat
