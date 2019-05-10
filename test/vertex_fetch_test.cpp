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

    for (int i = 1; i < 640 * 480; i++) {
        sdramController.memory[i] = i-1;
    }
    // number of triangles to be read
    sdramController.memory[0] = 5;

    top = new Vtop;  // Create instance

    top->clock = 0;
    top->reset = 1;  // Set some inputs
    top->eval();
    top->reset = 0;
    top->eval();
    top->reset = 1;


    uint32_t addr = 0;
    int once = 0;
    int tri_count = 0;
    for (;;) {
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->master_readdata,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);
        top->stall_in = 0;
        if (addr < 640 * 480 * 8) {
            if (!once) {
                top->fetch_enable = 1;
                top->vertex_buffer_base = addr;
                once = 1;
               // addr += (4*15);
            } else {
                top->fetch_enable = 0;
            }
        } else {
            top->fetch_enable = 0;
        }
        top->clock = 1;
        top->eval();

        if (top->output_valid && once) {
            tri_count++;
            cout << "top->vertex_out = " << top->vertex_out[0] << " " <<
             top->vertex_out[1] << " " <<
             top->vertex_out[2] << " " <<
             top->vertex_out[3] << " " <<
             top->vertex_out[4] << " " <<
             top->vertex_out[5] << " " <<
             top->vertex_out[6] << " " <<
             top->vertex_out[7] << " " <<
             top->vertex_out[8] << " " <<
             top->vertex_out[9] << " " <<
             top->vertex_out[10] << " " <<
             top->vertex_out[11] << " " <<
             top->vertex_out[12] << " " <<
             top->vertex_out[13] << " " <<
             top->vertex_out[14] << endl;
        } else {
            cout << "output is not valid -- " << tri_count << endl;
        }

        if (top->done_out)
            break;

        cout << "-----------------------" << endl;
        top->clock = 0;
        top->eval();

        main_time++;
    }

    top->final();
    delete top;
}
