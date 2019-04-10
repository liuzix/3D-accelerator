#!/bin/bash

verilator --cc ../rasterizer_fetch_logic.sv fetch_test.cpp --exe -I../ -CFLAGS -g
make -C obj_dir -f Vrasterizer_fetch_logic.mk
cp obj_dir/Vrasterizer_fetch_logic ./

