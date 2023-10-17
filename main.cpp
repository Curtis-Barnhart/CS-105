#include <iostream>

#include "png.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;

    fprintf(stderr, "   Compiled with libpng %s; using libpng %s.\n",
            PNG_LIBPNG_VER_STRING, png_libpng_ver);
//    fprintf(stderr, "   Compiled with zlib %s; using zlib %s.\n",
//            ZLIB_VERSION, zlib_version);
    return 0;
}
