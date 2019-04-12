#include <string.h>
#include <verilated.h>
#include <cassert>
#include <iostream>
#include "sdram_controller.h"
#include "vgasim.h"
#include "Vvga_unit.h"

using namespace std;
using Vtop = Vvga_unit;
Vtop* top;  // Instantiation of module

void loadFrameBuffer(uint32_t *buf, const string &file);

vluint64_t main_time = 0;  // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  You can also use a double, if you wish.

double sc_time_stamp() {  // Called by $time in Verilog
    return main_time;     // converts to double, to match
                          // what SystemC does
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // Remember args
		

    // simulate a 64M sdram block
    SDRAMController<uint32_t> sdramController(64 * 1024 * 1024);

	//copy bitmap 
	loadFrameBuffer(sdramController.memory.data(), "puppy.jpg");

    top = new Vtop;  // Create instance
	VGASimulator vgasim; 	

    top->clk = 0;
    top->reset = 1;  // Set some inputs
    top->eval();
    top->reset = 0;
    top->eval();
    top->reset = 1;

    uint32_t addr = 0;
    for (;;) {
		top->clk = 1;
		vgasim.poll();
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->bus_data,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);
		top->eval();
        vgasim.tick(top->VGA_CLK, top->VGA_R, top->VGA_G, top->VGA_B, top->VGA_HS, top->VGA_VS);

		top->clk = 0;
		top->eval();

        main_time++;
    }

    top->final();
    delete top;
}
