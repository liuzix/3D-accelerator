CXX=g++
CXXFLAGS=-g -std=c++11 -Wall

.PHONY : all
all : render render_rotate

render:
	$(CXX) $(CXXFLAGS) -o render render.cpp

render_rotate:
	$(CXX) $(CXXFLAGS) -o render_rotate render_rotate.cpp

clean:
	rm -f render
	rm -f render_rotate

