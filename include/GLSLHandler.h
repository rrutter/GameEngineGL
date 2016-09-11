#ifndef GLSLHANDLER_H
#define GLSLHANDLER_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
    #else
    #include <GL/glew.h>
#endif

#include <string>

class GLSLHandler
{
    public:
        GLSLHandler();
        virtual ~GLSLHandler();
        void compileShaders(const std::string &vertexFilePath, const std::string &fragFilePath);
        GLuint linkShaders();
        void addAttribute(const std::string &attribute);
        void apply();
        void kill();
    protected:
    private:
        GLuint programID;
        GLuint fragID;
        GLuint vertID;
        int numAttributes;
        void compileShader(const std::string &shaderFilePath, GLuint id);
};

#endif // GLSLHANDLER_H
