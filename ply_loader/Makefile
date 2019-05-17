CXX=g++
CXXFLAGS=-g -std=c++11 -Wall
OBJS=loader.o

loader:	$(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o loader

clean:
	rm -f loader
	rm -f $(OBJS)

loader.o: loader.cpp
