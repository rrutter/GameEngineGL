#ifndef VERTSTRUCT_H_INCLUDED
#define VERTSTRUCT_H_INCLUDED

#include <GL/glew.h>

    struct Position
    {
        float x;
        float y;
    };

    struct Color
    {
        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;
    };

struct VertStruct
{
    Position position;
    Color color;

};

#endif // VERTSTRUCT_H_INCLUDED
