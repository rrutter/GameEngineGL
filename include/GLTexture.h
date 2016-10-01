#ifndef GLTEXTURE_H_INCLUDED
#define GLTEXTURE_H_INCLUDED

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
    #else
    #define GLEW_STATIC
    #define GL3_PROTOTYPES 1
    #include <GL/glew.h>
#endif

struct GLTexture
{
    GLuint id;
    int width;
    int height;
};

#endif // GLTEXTURE_H_INCLUDED
