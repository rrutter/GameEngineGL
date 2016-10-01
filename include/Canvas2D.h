#ifndef CANVAS2D_H
#define CANVAS2D_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
    #else
    #define GLEW_STATIC
    #define GL3_PROTOTYPES 1
    #include <GL/glew.h>
#endif

#include <string>

class Canvas2D
{
    public:
        void build(float x, float y, float width, float height, const char* texturePath);
        Canvas2D();
        virtual ~Canvas2D();
        void render();
    protected:
    private:
        float x;
        float y;
        float width;
        float height;
        GLuint vboID;
        GLuint texture;
};

#endif // CANVAS2D_H
