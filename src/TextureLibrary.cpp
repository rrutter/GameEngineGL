#include "TextureLibrary.h"
#include "PngLoader.h"

TextureLibrary::TextureLibrary()
{
    //ctor
}

TextureLibrary::~TextureLibrary()
{
    //dtor
}

GLuint TextureLibrary::getTexture(const char* texturePath)
{
    //std::map<std::string, GLTexture>::iterator
    auto mit = textureMap.find(texturePath);
    GLuint newTexture = 0;

    if(mit == textureMap.end())
    {
        newTexture = PngLoader::load(texturePath);

        //std::pair <std::string, GLuint> tmpPair <"helloworld", newTexture>;
        textureMap.insert(std::make_pair(texturePath, newTexture));
        return newTexture;
    }

    return mit->second;
}
