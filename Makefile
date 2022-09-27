# Makefile for heat1fdm

CXX=g++ -g
INCLUDE=./include
SRC=./src
#DEBUG=DEBUG
DEBUG=0

heat1d.o: $(SRC)/heat1d.cpp
	$(CXX) -Wall -c -I$(INCLUDE) -o heat1d.o $(SRC)/heat1d.cpp

algs.o: $(SRC)/algs.cpp
	$(CXX) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -o algs.o $(SRC)/algs.cpp

heat: heat1d.o algs.o
	$(CXX) -o heat heat1d.o algs.o

clean:
	rm -rf *.o heat
