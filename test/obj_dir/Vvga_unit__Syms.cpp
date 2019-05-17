// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vvga_unit__Syms.h"
#include "Vvga_unit.h"

// FUNCTIONS
Vvga_unit__Syms::Vvga_unit__Syms(Vvga_unit* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scope names
    __Vscope_vga_unit__master.configure(this,name(),"vga_unit.master");
}
