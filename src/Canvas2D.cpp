#include "Canvas2D.h"

#include <iostream>

Canvas2D::Canvas2D()
{
    //default
    vboID=0;
    std::cout<<"2D Canvas object created..."<<std::endl;
}

void Canvas2D::build(float x, float y, float width, float height)
{
    std::cout<<"building the canvas"<<std::endl;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    if (vboID == 0)
    {
        std::cout<<"attempting to gen buffers..."<<std::endl;
        glGenBuffers(1, &vboID);
    }
    std::cout<<"buffers generated!"<<std::endl;

    float vertexData [12];

    //triangle 1
    vertexData[0] = x + width;
    vertexData[1] = y + height;

    vertexData[2] = x;
    vertexData[3] = y + height;

    vertexData[4] = x;
    vertexData[5] = y;

    //next triangle
    vertexData[6] = x;
    vertexData[7] = y;

    vertexData[8] = x + width;
    vertexData[9] = y;

    vertexData[10] = x + width;
    vertexData[11] = y + height;

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


}

void Canvas2D::render()
{

    GLuint vao = 0;
    glGenVertexArrays (1, &vao);
    glBindVertexArray (vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
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
