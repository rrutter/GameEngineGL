#include "Canvas2D.h"

#include <iostream>
#include <cstddef>
#include "VertStruct.h"
#include "ResourceHandler.h"

#include <SDL.h>

Canvas2D::Canvas2D()
{
    //default
    vboID=0;
    std::cout<<"2D Canvas object created..."<<std::endl;
}

void Canvas2D::build(float x, float y, float width, float height, const char* texturePath)
{
    std::cout<<"building the canvas"<<std::endl;
    x = x;
    y = y;
    width = width;
    height = height;

    texture = ResourceHandler::getTexture(texturePath);

    if (vboID == 0)
    {
        std::cout<<"attempting to gen buffers..."<<std::endl;
        glGenBuffers(1, &vboID);
        glGenVertexArrays (1, &vboID);
        glBindVertexArray (vboID);
    }
    std::cout<<"buffers generated!"<<std::endl;

    VertStruct vertexData[6];

    //triangle 1
    vertexData[0].setPosition(x+width, y+height);
    vertexData[0].setUV(1,1);

    vertexData[1].setPosition(x, y+height);
    vertexData[1].setUV(0,1);

    vertexData[2].setPosition(x, y);
    vertexData[2].setUV(0,0);

    vertexData[3].setPosition(x, y);
    vertexData[3].setUV(0,0);

    vertexData[4].setPosition(x+width, y);
    vertexData[4].setUV(1,0);

    vertexData[5].setPosition(x+width, y+height);
    vertexData[5].setUV(1,1);

    //vertexData.setColor(0, 0, 255, 255);

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


}

void Canvas2D::render()
{
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(VertStruct), (void*)offsetof(VertStruct, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(VertStruct), (void*)offsetof(VertStruct, color));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Canvas2D::~Canvas2D()
{
    if(vboID != 0)
    {
        glDeleteBuffers(1, &vboID);
    }
    std::cout<<"2D Canvas object destroyed..."<<std::endl;
}
