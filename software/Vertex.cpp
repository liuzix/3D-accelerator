#include <glm/vec4.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Vertex {
    int x, y, z, w;

    Vertex(int x1, int y1, int z1, int w1) {
        x = x1;
        y = y1;
        z = z1; 
        w = w1;
	}

    glm:vec4 get_vector() {
        return glm:vec4(x,y,z,w);
    }
}
