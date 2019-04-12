#include <iostream>
#include "vgasim.h"

using namespace std;

VGASimulator::VGASimulator()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //for (int i = 0; i < 640; ++i)
    //    SDL_RenderDrawPoint(renderer, i, i);
    SDL_RenderPresent(renderer);
   
    hcount = vcount = 0;
}

void VGASimulator::poll()
{
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
        exit(0);
}
    
void VGASimulator::tick(bool clk, uint8_t r, uint8_t g, uint8_t b,
            bool, bool)
{
	cout << "vga clock: " << clk << endl;
	if (!(clk && !prevClock)) {
        prevClock = clk;
        return;
    }
    prevClock = clk;
    cout << "vgasim:  r " << (int)r << " g " << (int)g << " b " << (int)b << endl;
	cout << "vgasim: hcount: " << dec << hcount << endl;
	cout << "vgasim :vcount: " << dec << vcount << endl;
	if (hcount < 640 && vcount < 480) {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawPoint(renderer, hcount, vcount);
    } 
    if (hcount < 800)
        hcount ++;
    else {
        hcount = 0;
        if (vcount < 525)
            vcount ++;
        else
            vcount = 0;
    }
}

//vsim.poll();
