#include <glm/vec4.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
using namespace std;

mat4 translate_mat(float x, float y, float z) {
    mat4 t(1, 0, 0, x,
          0, 1, 0, y,
          0, 0, 1, z,
          0, 0, 0, 1);
    return t;
}

mat4 scale_mat(float x, float y, float z) {
    mat4 s(x, 0, 0, 0,
           0, y, 0, 0,
           0, 0, z, 0,
           0, 0, 0, 1);
    return s;
}

mat4 model_mat(mat4 tran, mat4 scale) {
    mat4 model;
    model = tran * scale;
    return model;
}

mat4 view_mat(float position, float target, float up_vector) {
    mat4 view = glm::lookAt(
                position, // the position of your camera, in world space
                yarget,   // where you want to look at, in world space
                up_vector);
    return view;
}


mat4 projection_mat(float l, float r, float b, float t, float zNear, float zFar) {
    mat4 proj = glm::ortho(f, r, b, t, zNear, zFar);
    return proj;
}


int main(int argc, char** argv) {
    mat4 view, model, projection;

    vec4 front, right, left, back;

    vec4 front_1(0, 1, 0, 1);
    vec4 front_2(-1, -1, 1, 1);
    vec4 fontt_3(1, -1, 1, 1);

    vec4 right_1(0, 1, 0, 1);
    vec4 right_2(1, -1, 1, 1);
    vec4 right_3(1, -1, -1, 1);

    vec4 back_1(0, 1, 0, 1);
    vec4 back_2(1, -1, -1, 1);
    vec4 back_3(-1, -1, -1, 1);

    vec4 left_1( 0, 1, 0, 1);
    vec4 left_2(-1,-1,-1, 1);
    vec4 left_3(-1,-1, 1, 1);

    return 0;
}

