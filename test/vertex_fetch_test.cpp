#include <string.h>
#include <verilated.h>  // Defines common routines
#include <cassert>
#include <iostream>                   // Need std::cout
#include "Vrasterizer_vertex_fetch.h"  // From Verilating "top.v"
#include "sdram_controller.h"

using namespace std;
using Vtop = Vrasterizer_vertex_fetch;
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
        sdramController.memory[i] = i;
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
        if (addr < 640 * 480 * 8) {
            if (!top->fetch_busy) {
                top->fetch_enable = 1;
                top->addr_in = addr;
                addr += 16;
            } else {
                cout << "fetch busy" << endl;
                top->fetch_enable = 0;
            }
        } else {
            cout << "not inputing anything" << endl;
            top->fetch_enable = 0;
        }
        top->clock = 1;
        top->eval();

        if (top->output_valid) {
            cout << "top->vertex_out = " << top->vertex_out[0] << " " <<
             top->vertex_out[1] << " " <<
             top->vertex_out[2] << " " <<
             top->vertex_out[3] << endl;
            
        } else {
            cout << "output is not valid" << endl;
        }

        cout << "-----------------------" << endl;
        top->clock = 0;
        top->eval();

        main_time++;
    }

    top->final();
    delete top;
}
