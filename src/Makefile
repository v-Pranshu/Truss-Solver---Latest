#Makefile for compiling the code

CXX = g++
# Path to source code
PATHSC = src/

# Using C++20 standard
CXXFLAGS := -std=c++2a

OBJS = Inputs.o mem.o jo.o supp.o Truss.o ReadInputs.o main.o

all:Solve

Inputs.o: Inputs.hpp 
	$(CXX) $(CXXFLAGS) -c Inputs.hpp

mem.o: mem.hpp mem.cpp
	$(CXX) $(CXXFLAGS) -c mem.cpp

jo.o: jo.hpp jo.cpp
	$(CXX) $(CXXFLAGS) -c jo.cpp 

supp.o: supp.hpp supp.cpp
	$(CXX) $(CXXFLAGS) -c supp.cpp

Truss.o: TrussSolve.hpp TrussSolve.cpp
	$(CXX) $(CXXFLAGS) -c TrussSolve.cpp

ReadInputs.o: ReadInputs.hpp ReadInputs.cpp
	$(CXX) $(CXXFLAGS) -c ReadInputs.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp


Solve: $(OBJS)
	$(CXX) $(CXXFLAGS) *.o -o SolveTruss
	make clean

clean: 
	rm -f $(OBJS)


