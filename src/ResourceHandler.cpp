#include "ResourceHandler.h"

TextureLibrary ResourceHandler::textureLib;

GLuint ResourceHandler::getTexture(const char* texturePath)
{
    return textureLib.getTexture(texturePath);
}
