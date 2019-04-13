#include <string.h>
#include <verilated.h>  // Defines common routines
#include <cassert>
#include <iostream>                   // Need std::cout
#include "Vbus_adapter.h"  // From Verilating "top.v"
#include "sdram_controller.h"
#include  <iomanip>

using namespace std;
using Vtop = Vbus_adapter;
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
    SDRAMController<uint16_t> sdramController(64 * 1024 * 1024);

    for (int i = 0; i < 640 * 480; i++) {
        sdramController.memory[2*i + 1] = i;
    }

    top = new Vtop;  // Create instance

    top->clock = 0;
    top->reset = 1;  // Set some inputs
    top->eval();
    top->reset = 0;
    top->eval();
    top->reset = 1;


    int counter = 0;

    uint32_t addr = 0;
    for (;;) {
        uint32_t data;
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->master_readdata,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);
        if (addr < 640 * 480 * 8) {
			// if (!top->slave_waitrequest) {
			// 	top->slave_address = addr;
   //              top->slave_read = 1;
   //              addr += 4;
			// } else
   //              top->slave_read = 0;

            if (!top->slave_waitrequest) {
                top->slave_address = addr;
                data = ((counter * 2) << 16) + (counter * 2 + 1);
                cout << "write data: " << hex << setfill('0') << setw(8) <<data << endl;
                top->slave_writedata = data;
                top->slave_write = 1;
                addr += 4;
                counter++;
            } else
                top->slave_write = 0;
		}
        top->clock = 1;
        top->eval();

        // if (top->slave_readdatavalid) {
        //     cout << top->slave_readdata << endl;
        // }
        cout << "-----------------------" << endl;
        top->clock = 0;
        top->eval();

        main_time++;
    }

    top->final();
    delete top;
}
