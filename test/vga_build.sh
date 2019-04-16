#!/bin/bash

verilator -Wno-fatal --cc ../vga_unit.sv write_test_image.cpp ../bus_adapter ../vga_unit_modules fetch_vga.cpp vgasim.cpp --exe -I../ -CFLAGS -g -LDFLAGS -lsdl2 -LDFLAGS -L/opt/X11/lib -LDFLAGS -lX11 -LDFLAGS -ljpeg \
    -CFLAGS -I/opt/X11/include -LDFLAGS -pthread

verilator --cc ../bus_adapter.sv adapter_test.cpp --exe -I../ -CFLAGS -g
make -C obj_dir -f Vbus_adapter.mk
cp obj_dir/Vbus_adapter ./

make -C obj_dir -f Vvga_unit.mk
cp obj_dir/Vvga_unit ./

