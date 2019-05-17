# This sample Makefile allows you to make any OpenGL application
#   whose source is exactly one .cpp file.
#
# To use this Makefile, you must type:
#
#        make xxxx
#             ----
# where
#       xxxx.cpp is the name of the file you wish to compile.
#       ----
#
# This makefile will work for both Mac and Linux

# Macros
CC      = g++
CFLAGS  =

INCLUDE =

# Removes warnings about deprication
CCOPTS = -Wno-deprecated

# Testing for OS X v Linux
OS = $(shell uname -s)

ifeq ($(OS),Darwin)
	LDFLAGS = -framework GLUT -framework OpenGL -framework Cocoa
else
	LDFLAGS = -lGL -lGLU -lglut -lm -lstdc++
endif

rasterizer : rasterizer

% : 
	$(CC) $(CFLAGS) $(INCLUDE) $@.cpp -o $@ $< \
		$(LDFLAGS) $(LDLIBS) $(CCOPTS)

clean :
	rm -rf *a.out main rasterizer 
