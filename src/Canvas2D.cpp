#include "Canvas2D.h"

#include <iostream>
#include <cstddef>
#include "VertStruct.h"

#include <SDL.h>

Canvas2D::Canvas2D()
{
    //default
    vboID=0;
    std::cout<<"2D Canvas object created..."<<std::endl;
}

void Canvas2D::build(float x, float y, float width, float height)
{
    std::cout<<"building the canvas"<<std::endl;
    x = x;
    y = y;
    width = width;
    height = height;

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
    vertexData[0].position.x = x + width;
    vertexData[0].position.y = y + height;

    vertexData[1].position.x = x;
    vertexData[1].position.y = y + height;

    vertexData[2].position.x = x;
    vertexData[2].position.y = y;

    //next triangle
    vertexData[3].position.x = x;
    vertexData[3].position.y = y;

    vertexData[4].position.x = x + width;
    vertexData[4].position.y = y;

    vertexData[5].position.x = x + width;
    vertexData[5].position.y = y + height;

    for(int i=0; i<6; i++)
    {
        vertexData[i].color.r = 0;
        vertexData[i].color.g = 0;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255;
    }

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


}

void Canvas2D::render()
{
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
