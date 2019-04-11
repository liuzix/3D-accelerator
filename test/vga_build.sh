#!/bin/bash

verilator -Wno-fatal --cc ../vga_unit.sv write_test_image.cpp ../vga_unit_modules fetch_vga.cpp vgasim.cpp --exe -I../ -CFLAGS -g -LDFLAGS -lsdl2 -LDFLAGS -L/opt/X11/lib -LDFLAGS -lX11 -LDFLAGS -ljpeg
make -C obj_dir -f Vvga_unit.mk
cp obj_dir/Vvga_unit ./

