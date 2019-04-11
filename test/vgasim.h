#pragma once

#include <cstdint>
#include "SDL2/SDL.h"

class VGASimulator {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    int hcount, vcount;
    bool prevClock = 0;
public:
    VGASimulator();
    
    void poll();

    void tick(bool clk, uint8_t r, uint8_t g, uint8_t b,
            bool hsync, bool vsync);
};
