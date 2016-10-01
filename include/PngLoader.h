#ifndef PNGLOADER_H
#define PNGLOADER_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
    #else
    #define GLEW_STATIC
    #define GL3_PROTOTYPES 1
    #include <GL/glew.h>
#endif

#include <iostream>
#include <stdio.h>

class PngLoader
{
    public:
        static GLuint load(std::string pngFile);
        static int color_type;
    protected:
    private:
};

#endif // PNGLOADER_H
