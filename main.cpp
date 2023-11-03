#include <iostream>

#include "OBJ_Loader.h"

#include "png.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;

    fprintf(stderr, "   Compiled with libpng %s; using libpng %s.\n",
            PNG_LIBPNG_VER_STRING, png_libpng_ver);
//    fprintf(stderr, "   Compiled with zlib %s; using zlib %s.\n",
//            ZLIB_VERSION, zlib_version);

//OBJ LOADER CODE
    //initialize an obj loader named Loader
    objl::Loader Loader;

    //load the obj file, loadout = loads successfully
    //this will print out all the information of the obj file
    //including the 2 meshes it contains.
    bool loadout = Loader.LoadFile("../test.obj");

    //check to see if file loaded properly
    if(loadout) {
        //grab the first mesh
        objl::Mesh curMesh = Loader.LoadedMeshes[0];
        //print the name of the mesh. should be 'cube'
        std::cout << curMesh.MeshName << std::endl;
    }
    return 0;
}
