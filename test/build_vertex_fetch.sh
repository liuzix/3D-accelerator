#!/bin/bash

verilator --cc ../rasterizer_vertex_fetch.sv vertex_fetch_test.cpp --exe -I../ -CFLAGS -g
make -C obj_dir -f Vrasterizer_vertex_fetch.mk
cp obj_dir/Vrasterizer_vertex_fetch ./

