# Makefile for heat1fdm

CXX=g++ -g
INCLUDE=./include
SRC=./src
#DEBUG=DEBUG
DEBUG=0

heat1fdm.o: $(SRC)/heat1fdm.cpp
	$(CXX) -Wall -c -I$(INCLUDE) -o heat1fdm.o $(SRC)/heat1fdm.cpp

algs.o: $(SRC)/algs.cpp
	$(CXX) -Wall -c -I$(INCLUDE) -DDEBUG=$(DEBUG) -o algs.o $(SRC)/algs.cpp

heat: heat1fdm.o algs.o
	$(CXX) -o heat heat1fdm.o algs.o

clean:
	rm -rf *.o heat
