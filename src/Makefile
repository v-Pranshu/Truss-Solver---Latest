
CXX = g++
# Path to source code
PATHSC = src/

# Using C++20 standard
CXXFLAGS := -std=c++2a

all:Solve

Inputs.o: Inputs.hpp 
	$(CXX) $(CXXFLAGS) -c Inputs.hpp

mem.o: mem.hpp mem.cpp
	$(CXX) $(CXXFLAGS) -c mem.cpp

jo.o: jo.hpp jo.cpp
	$(CXX) $(CXXFLAGS) -c jo.cpp 

supp.o: supp.hpp supp.cpp
	$(CXX) $(CXXFLAGS) -c supp.cpp

main.o: duplicate_main.cpp
	$(CXX) $(CXXFLAGS) -c duplicate_main.cpp

Solve: Inputs.o mem.o jo.o supp.o main.o
	$(CXX) $(CXXFLAGS) *.o -o RunCode





