// g++ -std=c++11 render.cpp -o render
#include <cstddef>
#include <cstdint>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/vec4.hpp>
#include <math.h>
#include <unistd.h>
using namespace std;
// generate MVP
typedef uint32_t fixed_point_t;
#define FIXED_POINT_FRACTIONAL_BITS 16
inline fixed_point_t float2fixed(double input) {
  return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}
fixed_point_t *load_matrix() {
  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1
  // unit <-> 100 units
  //    glm::mat4 Projection = glm::perspective(
  //      glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);
  // Or, for an ortho camera :

  glm::mat4 Projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
  // // In world coordinates
  // Camera matrix
  glm::mat4 View = glm::lookAt(
      glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
      glm::vec3(0, 0, 0), // and looks at the origin
      glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
  );
  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 Model = glm::mat4(1.0f);
  //    Model = glm::rotate(Model,1.57,glm::vec3(0,0,1));
  // Our ModelViewProjection : multiplication of our 3 matrices
  glm::mat4 mvp =
      Projection * View *
      Model; // Remember, matrix multiplication is the other way around

  glm::vec4 test = mvp * glm::vec4(0, 0, -8, 1);
  cout << "rasterizer: reference = " << glm::to_string(test) << endl;
  fixed_point_t *fixed_matrix = new fixed_point_t[16];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      fixed_matrix[4 * i + j] = float2fixed(mvp[j][i]);
    }
  }
  return fixed_matrix;
}

int main() {

  // write vertex into sdram
  int vertex_buffer_offset = 480 * 640 * 8;
  int fd; // manage physical address
  if ((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1) {
    cerr << "fd open failed" << endl;
    exit(-1);
  }
  std::ifstream file("./data.binary",
                     std::ios::in | std::ios::binary | std::ios::ate);
  if (!file.is_open()) {
    cout << "file open failed";
    std::abort();
  }
  size_t size = file.tellg();
  char *map_sdram =
      (char *)mmap(0, 64 * 1024 * 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
                   0xc0000000); // map the entire sdram
  cout << "binary file size = " << dec << size << endl;
  char *vertex_buffer_base = map_sdram + vertex_buffer_offset;

  file.seekg(0, ios::beg);
  file.read(vertex_buffer_base, size);
  file.close();
  cout << "the entire binary file content is in sdram\n";
  // configure the rasterizer

  char *map_render = (char *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED,
                                  fd, 0xff200000); // map the render to memory

  for (int i = 0; i < 480 * 640; i++) {
    *(int *)(map_sdram + i * 8) = 0;
    *(int *)(map_sdram + i * 8 + 4) = -1;
  }

  *(int *)(map_render + 4) = vertex_buffer_offset;

  fixed_point_t *mat = load_matrix();
  memcpy(map_render + 0x200, mat, 16 * 4);

  __sync_synchronize();
  *(int *)(map_render + 8) = 1;

}
