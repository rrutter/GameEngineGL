#include "../include/PngLoader.h"
#include <png.h>
#include <iostream>
#include <cstring>
#include <string>

PngLoader::PngLoader(std::string pngName)
{
    ASSETS_DIR = "assets/";
    name = pngName;
    std::cout << "Png Loader Initialized " << std::endl;
    load();
}

int PngLoader::load()
{
    std::cout<<"testing...."<<std::endl;
    std::cout<<ASSETS_DIR<<std::endl;

    int buffer = strlen(ASSETS_DIR.c_str())+strlen(name.c_str())+1;
    char* fileName = new char[ buffer ];
    strcpy(fileName, ASSETS_DIR.c_str());
    strcat(fileName, name.c_str());

    std::cout <<"Loading png file"<< fileName << std::endl;

    png_structp png_ptr;
    png_infop info_ptr;
    int sig_read = 0;
    png_uint_32 width, height;
    int bit_depth, color_type, interlace_type;
    //FILE *fp;

    FILE * fp;

    if ((fp = fopen(fileName, "rb")) == NULL)
    {
        std::cout<< "png didnt load successfully" << std::endl;
    }
   else{
    std::cout<<"loaded png correctly" << std::endl;
   }

    return 0;
}

std::string PngLoader::getName()
{
    return name;
}

PngLoader::~PngLoader()
{
    //dtor
    std::cout << "Png Loader Destroyed" << std::endl;
}
