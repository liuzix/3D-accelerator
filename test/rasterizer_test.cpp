#include <string.h>
#include <tgmath.h>
#include <verilated.h>
#include <cassert>
#include <fstream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <iostream>
#include "SDL2/SDL.h"
#include "Vrasterizer_unit.h"
#include "sdram_controller.h"
using namespace std;
// using Vvga_module = Vvga_unit;
// Vvga_module* vga;  // Instantiation of module
using Vras = Vrasterizer_unit;
Vras *top;
typedef uint32_t fixed_point_t;
#define FIXED_POINT_FRACTIONAL_BITS 16
void loadFrameBuffer(void *buf, const string &file);

class VGADisplay {
   public:
    VGADisplay(void *_framebuffer) {
        framebuffer = _framebuffer;
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    void poll() {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) exit(0);
    }
    void refresh() {
        SDL_RenderClear(renderer);
        uint8_t *ptr = (uint8_t *)framebuffer;

        for (int y = 0; y < 480; y++) {
            for (int x = 0; x < 640; x++) {
                uint8_t r = *ptr;
                uint8_t g = *(ptr + 1);
                uint8_t b = *(ptr + 2);
                
                ptr += 8;

//                if (r || g || b)
//                    printf("refresh r: %d, g: %d, b: %d\n", r, g, b);
                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
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
inline fixed_point_t float2fixed(double input) {
    return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}
fixed_point_t *load_matrix() {
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1
    // unit <-> 100 units
    //glm::mat4 Projection = glm::perspective(
    //    glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);
    // Or, for an ortho camera :
    glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f);
    // // In world coordinates
    // Camera matrix
    glm::mat4 View = glm::lookAt(
        glm::vec3(4, 3, 3),  // Camera is at (4,3,3), in World Space
        glm::vec3(0, 0, 0),  // and looks at the origin
        glm::vec3(0, 1, 0)   // Head is up (set to 0,-1,0 to look upside-down)
    );
    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 mvp =
        Projection * View *
        Model;  // Remember, matrix multiplication is the other way around

    glm::vec4 test = mvp * glm::vec4(0, 0, -8, 1);
    cout << "rasterizer: reference = " << glm::to_string(test) << endl;
    fixed_point_t *fixed_matrix = new fixed_point_t[16];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fixed_matrix[4 * i + j] = float2fixed(mvp[j][i]);
        }
    }
    // memcpy(matrix_base,fixed_matrix,16*4);
    return fixed_matrix;
}
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);  // Remember args
    // simulate a 64M sdram block
    SDRAMController<uint32_t> sdramController(64 * 1024 * 1024);
    char *framebuffer_base = (char *)sdramController.memory.data();
    uint32_t vertex_buffer_offset =
        640 * 480 * 8;  // byte addressable,one pixel 8 bytes
    // load vertex in sdram
    std::ifstream file("../ply_loader/data.binary",
                       std::ios::in | std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        cout << "file open failed";
        std::abort();
    }
    size_t size = file.tellg();
    cout << "binary file size = " << dec << size << endl;
    char *vertex_buffer_base = framebuffer_base + vertex_buffer_offset;
    file.seekg(0, ios::beg);
    file.read(vertex_buffer_base, size);
    file.close();
    cout << (void *)framebuffer_base << "\n";
    cout << (void *)vertex_buffer_base << "\n";
    cout << "the entire binary file content is in sdram\n";
    // initialize framebuffer
    for (int i = 0; i < 480 * 640; i++) {
        unsigned long *p = (unsigned long *)(framebuffer_base + i * 8);
        *p = 0xFFFFFFFFUL << 32;
    }
    VGADisplay *display = new VGADisplay(framebuffer_base);
    // Create instance
    top = new Vras;
    // rasterizer;
    top->clock = 0;
    top->reset = 1;  // Set some inputs
    top->eval();
    top->reset = 0;
    top->eval();
    top->reset = 1;

    // configuration

    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                top->writedata =
                    0x0;  // frame buffer start from the address 0 of sdram
                break;
            case 1:
                top->writedata = vertex_buffer_offset;
                break;
            case 2:
                top->writedata = 1;  //
                break;
        }
        top->address = 4 * i;
        top->write = 1;
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->master_readdata,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);
        sdramController.tick(
            1, top->master_address_2, top->master_read_2, top->master_write_2,
            &top->master_readdata_2, top->master_readdatavalid_2,
            &top->master_writedata_2, top->master_waitrequest_2);
        sdramController.tick(
            2, top->master_address_3, top->master_read_3, top->master_write_3,
            &top->master_readdata_3, top->master_readdatavalid_3,
            &top->master_writedata_3, top->master_waitrequest_3);
        top->eval();
        top->clock = 1;
        top->eval();
        top->clock = 0;
        top->eval();
    }
    uint16_t config_MVreg_addr = 0x100;
    uint16_t config_MVPreg_addr = 0x200;
    uint16_t config_lightingreg_addr = 0x300;
    fixed_point_t *matrix_base = load_matrix();
    for (int i = 0; i < 16 + 16 + 2; i++) {
        // MV address 256->316  60
        if (i > 0 && i < 16) {
            top->writedata = 1;
            top->address = config_MVreg_addr + 0x4 * i;
        }
        // MVP address 512->572 60
        else if (i >= 16 && i < 32) {
            top->writedata = matrix_base[i - 16];
            cout << "MVP matrix:" << matrix_base[i - 16] << "\n";
            top->address = config_MVPreg_addr + 4 * (i - 16);
        } else {
            // lighting address 768->176  8
            top->writedata = 3;
            top->address = config_lightingreg_addr + 0x4 * (i - 32);
        }
        top->write = 1;
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->master_readdata,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);
        sdramController.tick(
            1, top->master_address_2, top->master_read_2, top->master_write_2,
            &top->master_readdata_2, top->master_readdatavalid_2,
            &top->master_writedata_2, top->master_waitrequest_2);
        sdramController.tick(
            2, top->master_address_3, top->master_read_3, top->master_write_3,
            &top->master_readdata_3, top->master_readdatavalid_3,
            &top->master_writedata_3, top->master_waitrequest_3);
        top->eval();
        top->clock = 1;
        top->eval();
        top->clock = 0;
        top->eval();
    }
    cout << "configuration done!\n";
    // begin rasterization
    for (;;) {
        display->poll();
        display->refresh();
        cout << "tick\n";
        sdramController.tick(0, top->master_address, top->master_read,
                             top->master_write, &top->master_readdata,
                             top->master_readdatavalid, &top->master_writedata,
                             top->master_waitrequest);
        sdramController.tick(
            1, top->master_address_2, top->master_read_2, top->master_write_2,
            &top->master_readdata_2, top->master_readdatavalid_2,
            &top->master_writedata_2, top->master_waitrequest_2);
        sdramController.tick(
            2, top->master_address_3, top->master_read_3, top->master_write_3,
            &top->master_readdata_3, top->master_readdatavalid_3,
            &top->master_writedata_3, top->master_waitrequest_3);
        top->eval();
        top->clock = 1;
        top->eval();

        top->clock = 0;
        top->eval();

        display->refresh();
        main_time++;
    }

    // vga->final();
    delete top;
}
