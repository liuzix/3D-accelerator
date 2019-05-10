#include <string.h>
#include <verilated.h>
#include <cassert>
#include <iostream>
#include "sdram_controller.h"
#include "vgasim.h"
#include "Vvga_unit.h"
#include "Vrasterizer_unit.h"
#include "SDL2/SDL.h"

using namespace std;
//using Vvga_module = Vvga_unit;
//Vvga_module* vga;  // Instantiation of module
using Vras=Vrasterizer_unit;
Vras*top;
void loadFrameBuffer(void *buf, const string &file);

class VGADisplay {
public:
    VGADisplay(void *_framebuffer) {
        framebuffer = _framebuffer;
    }
    void poll()
    {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
        exit(0);
     }
    void refresh() {
        uint8_t *ptr = (uint8_t *)framebuffer;

        for (int y = 0; y < 480; y++) {
            for (int x = 0; x < 640; x++) {
                uint8_t r = *ptr;
                uint8_t g = *(ptr + 1);
                uint8_t b = *(ptr + 2);

                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        
            ptr += 8;
        }
        SDL_RenderPresent(renderer);
    }
private:
    void *framebuffer;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
};

vluint64_t main_time = 0;  // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  You can also use a double, if you wish.

double sc_time_stamp() {  // Called by $time in Verilog
    return main_time;     // converts to double, to match
                          // what SystemC does
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // Remember args
		
    VGADisplay*display=new VGADisplay();
    display.framebuffer=0x000000；
    // simulate a 64M sdram block
    SDRAMController<uint32_t> sdramController(64 * 1024 * 1024);

	//copy bitmap 
	//loadFrameBuffer(sdramController.memory.data(), "puppy.jpg");

     // Create instance
    top=new Vras;
	//rasterizer; 	

    
    top->clock = 0;
    top->reset = 1;  // Set some inputs
    top->eval();
    top->reset = 0;
    top->eval();
    top->reset = 1;
    uint32_t framebuffer_base = 0;
    uint32_t vertex_buffer_base = 640*480;
    //configuration
    uint16_t config_reg_addr=0;
    for(int i=0;i<3+512+512+97;i++){
        case(i)
            0:top->writedata=framebuffer_base;break;
            1:top->writedata=vertex_buffer_base;break;      
            2:top->writedata=0;break;
            default:
              if(i)
        top->address=4*i;
        top->write=1;
        top->write=1;
        top->clock=1;
        top->eval();
        top->clock=0;
        top->eval();
    }
    

    //begin rasterization
    for (;;) {
        
		vga->clk = 1;
		vgasim.poll();
        sdramController.tick(0, vga->master_address, vga->master_read,
                             vga->master_write, &vga->bus_data,
                             vga->master_readdatavalid, &vga->master_writedata,
                             vga->master_waitrequest);
	    vga->eval();
        vgasim.tick(vga->VGA_CLK, vga->VGA_R, vga->VGA_G, vga->VGA_B, vga->VGA_HS, vga->VGA_VS);

		vga->clk = 0;
		vga->eval();

        vgasim.tick(vga->VGA_CLK, vga->VGA_R, vga->VGA_G, vga->VGA_B, vga->VGA_HS, vga->VGA_VS);
        display->refresh();
        main_time++;
    }

    vga->final();
    delete vga;
}
