#define cimg_use_jpeg

#include <CImg.h>
#include <cstddef>
#include <string>

using namespace cimg_library;
using namespace std;

void loadFrameBuffer(uint32_t *buf, const string &file)
{
    CImg<unsigned char> img;
	img.load_jpeg(file.c_str());
    img.resize(640, 480);

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            auto ptr = (unsigned char *)&buf[(i * 640 + j) * 2];
            *(ptr) = img(j, i, 0, 0);
            *(ptr + 1) = img(j, i, 0, 1);
            *(ptr + 2) = img(j, i, 0 ,2);
        }
    }
    
}
