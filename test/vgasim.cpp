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
    
void VGASimulator::tick(uint8_t r, uint8_t g, uint8_t b,
            bool, bool)
{
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

int main()
{
    VGASimulator vsim;
    for (;;) {
        vsim.poll();
    }
}
