#pragma once

#include <cstdint>
#include "SDL2/SDL.h"

class VGASimulator {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    int hcount, vcount;
public:
    VGASimulator();
    
    void poll();

    void tick(uint8_t r, uint8_t g, uint8_t b,
            bool hsync, bool vsync);
};
