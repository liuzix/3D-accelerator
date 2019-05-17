// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vrasterizer_unit__Syms.h"
#include "Vrasterizer_unit.h"

// FUNCTIONS
Vrasterizer_unit__Syms::Vrasterizer_unit__Syms(Vrasterizer_unit* topp, const char* namep)
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
    __Vscope_rasterizer_unit__fetch_logic.configure(this,name(),"rasterizer_unit.fetch_logic");
    __Vscope_rasterizer_unit__raster__area_divider.configure(this,name(),"rasterizer_unit.raster.area_divider");
}
