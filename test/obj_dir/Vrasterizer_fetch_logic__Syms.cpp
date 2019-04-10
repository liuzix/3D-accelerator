// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vrasterizer_fetch_logic__Syms.h"
#include "Vrasterizer_fetch_logic.h"

// FUNCTIONS
Vrasterizer_fetch_logic__Syms::Vrasterizer_fetch_logic__Syms(Vrasterizer_fetch_logic* topp, const char* namep)
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
    __Vscope_rasterizer_fetch_logic.configure(this,name(),"rasterizer_fetch_logic");
}
