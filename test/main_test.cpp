#include "Vfifo.h"  // From Verilating "top.v"
#include <iostream> // Need std::cout
#include <string.h>
#include <verilated.h> // Defines common routines

using namespace std;
Vfifo *top; // Instantiation of module

vluint64_t main_time = 0; // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  You can also use a double, if you wish.

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;      // converts to double, to match
                         // what SystemC does
}

void feed(Vfifo *top, bool wr, bool rd, int *din) {
  top->wr = wr;
  top->rd = rd;
  memcpy(top->din, din, 3 * sizeof(int));
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv); // Remember args

  top = new Vfifo; // Create instance

  top->clk = 0;
  top->reset = 1; // Set some inputs
  top->eval();
  top->reset = 0;
  top->eval();
  top->reset = 1;

  int i[3] = {0, 0, 0};
  while (!Verilated::gotFinish()) {
    i[0] += 1;
    i[1] += 2;
    i[2] += 3;
    feed(top, 1, 0, i);
    top->clk = 1;
    if (!top->empty)
      top->rd = 1;
    else {
      top->rd = 0;
      cout << "empty!" << endl;
    }
    top->eval();

    cout << top->dout[0] << endl; // Read a output
    cout << top->dout[1] << endl; // Read a output
    cout << top->dout[2] << endl; // Read a output

    top->clk = 0;
    top->eval();
  }

  top->final(); // Done simulating
  //    // (Though this example doesn't get here)
  delete top;
}
