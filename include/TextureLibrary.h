#ifndef TEXTURELIBRARY_H
#define TEXTURELIBRARY_H

#include <map>
#include "GLTexture.h"


class TextureLibrary
{
    public:
        TextureLibrary();
        virtual ~TextureLibrary();
        GLuint getTexture(const char* texturePath);

    protected:

    private:
        std::map <std::string, GLuint> textureMap;
};

#endif // TEXTURELIBRARY_H
