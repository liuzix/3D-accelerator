#define cimg_use_jpeg

#include <CImg.h>
#include <cstddef>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <vector>

using namespace cimg_library;
using namespace std;

void loadFrameBuffer(void *buf, const string &file)
{
    CImg<unsigned char> img;
	img.load_jpeg(file.c_str());
    img.resize(640, 480);

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            auto ptr = (unsigned char *)buf + (i * 640 + j) * 8;
            *(ptr) = img(j, i, 0, 0);
            *(ptr + 1) = img(j, i, 0, 1);
            *(ptr + 2) = img(j, i, 0 ,2);
        }
    }
    
}

//gcc -g -std=c++17 write_test_image.cpp -lX11 -lpthread -lm -ljpeg -lstdc++
int main() {
    int size = 640 * 480 * 8;
    vector<unsigned char> buf(size);

    loadFrameBuffer(buf.data(), "puppy.jpg");

    int fd;
    if((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1) {
        cerr << "fd open failed" << endl;
        exit(-1);
    }

    void* map_base;
    map_base = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0xc0000000);

    if(map_base == (void *) -1) {
        cerr << "mmap failed" << endl;
        exit(-1);
    }

    memcpy(map_base, buf.data(), size);
    return 0;
}
