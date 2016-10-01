#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include "TextureLibrary.h"


class ResourceHandler
{
public:
    static GLuint getTexture(const char*);


private:
    static TextureLibrary textureLib;

};

#endif // RESOURCEHANDLER_H
