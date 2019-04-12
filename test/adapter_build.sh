#!/bin/bash

verilator --cc ../bus_adapter.sv adapter_test.cpp --exe -I../ -CFLAGS -g
make -C obj_dir -f Vbus_adapter.mk
cp obj_dir/Vbus_adapter ./