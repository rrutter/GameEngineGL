#include "GLSLHandler.h"
#include "ErrorHandler.h"

#include <fstream>
#include <iostream>
#include <vector>

GLSLHandler::GLSLHandler()
:vertID(0), fragID(0), programID(0), numAttributes(0)
{
    //ctor
    std::cout<<"GLSL Shader Handler Created"<<std::endl;
}

void GLSLHandler::compileShaders(const std::string &vertexFilePath, const std::string &fragFilePath)
{
    programID = glCreateProgram();

    vertID = glCreateShader(GL_VERTEX_SHADER);
    if(vertID == 0)
    {
        //handle error
        printError("Vertex shader failed to be created...");
    }

    fragID = glCreateShader(GL_FRAGMENT_SHADER);
    if(fragID == 0)
    {
        //handle error
        printError("Fragment shader failed to be created...");
    }

    compileShader(vertexFilePath, vertID);
    compileShader(fragFilePath, fragID);
}

void GLSLHandler::compileShader(const std::string &shaderFilePath, GLuint id)
{

    std::ifstream shaderFile(shaderFilePath);
    if(shaderFile.fail())
    {
        printError("failed to load file from path " + shaderFilePath);
    }

    std::string fileContents = "";
    std::string line;

    while(std::getline(shaderFile, line))
    {
        fileContents += line + '\n';
    }

    shaderFile.close();
    int infoLog;

    const GLchar* filePtr = fileContents.c_str();
    GLsizei test = 1;

    glShaderSource(id, test, &filePtr, nullptr);
    glCompileShader(id);

    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLog);

    if ( infoLog > 0 ){
		std::vector<char> shaderMsg(infoLog+1);
		glGetShaderInfoLog(id, infoLog, NULL, &shaderMsg[0]);
		printf("%s\n", &shaderMsg[0]);
	}

    if(success == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

        glDeleteShader(id);

        printError("Shader Failed at compile time...");
        printError(&errorLog[0]);
    }
}

GLuint GLSLHandler::linkShaders()
{
    glAttachShader(programID, vertID);
    glAttachShader(programID, fragID);

    glLinkProgram(programID);

    int infoLog;

    GLint isLinked = 0;
    glGetProgramiv(programID, GL_LINK_STATUS, (int *)&isLinked);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLog);
	if ( infoLog > 0 ){
		std::vector<char> ProgramErrorMessage(infoLog+1);
		glGetProgramInfoLog(programID, infoLog, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}


    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(programID, maxLength, &maxLength, &errorLog[0]);

        glDeleteProgram(programID);
        glDeleteShader(vertID);
        glDeleteShader(fragID);

        printError("Failed to link shaders to the shader program...");
    }
    glDetachShader(programID, vertID);
    glDetachShader(programID, fragID);

    glDeleteShader(vertID);
    glDeleteShader(fragID);

    return programID;
}

void GLSLHandler::apply()
{
    glUseProgram(programID);
    for(int i=0; i<numAttributes; i++)
    {
        glEnableVertexAttribArray(i);
    }
}

void GLSLHandler::kill()
{
    glUseProgram(0);
    for(int i=0; i<numAttributes; i++)
    {
        glDisableVertexAttribArray(i);
    }
}

void GLSLHandler::addAttribute(const std::string &attribute)
{
    glBindAttribLocation(programID, numAttributes++, attribute.c_str());
    //layout(attribute);
}

GLSLHandler::~GLSLHandler()
{
    //dtor
    std::cout<<"GLSL Shader Handler Destroyed"<<std::endl;
}
