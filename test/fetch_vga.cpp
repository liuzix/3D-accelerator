#include <string.h>
#include <verilated.h>
#include <cassert>
#include <iostream>
#include "sdram_controller.h"

using namespace std;
using Vtop = Vrasterizer_fetch_logic;
Vtop* top;  // Instantiation of module

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

    for (int i = 0; i < 640 * 480; i++) {
        sdramController.memory[i * 2 + 1] = i;
    }

    top = new Vtop;  // Create instance

    top->clock = 0;
    top->reset = 1;  // Set some inputs
    top->eval();
    top->reset = 0;
    top->eval();
    top->reset = 1;

    uint32_t addr = 0;
    for (;;) {
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->master_readdata,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);

        top->clock = 0;
        top->eval();

        main_time++;
    }

    top->final();
    delete top;
}
