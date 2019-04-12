#!/bin/bash

verilator -Wno-fatal --cc ../vga_unit.sv ../vga_unit_modules.sv write_test_image.cpp  fetch_vga.cpp vgasim.cpp --exe \
    -I../ -CFLAGS -g -LDFLAGS -lSDL2 -LDFLAGS -ljpeg -LDFLAGS -lX11 -LDFLAGS -pthread
make -C obj_dir -f Vvga_unit.mk
cp obj_dir/Vvga_unit ./

