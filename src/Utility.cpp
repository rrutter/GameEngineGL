#include "Utility.h"

#include <iostream>
#include <fstream>

bool Utility::readFile(std::string filePath, std::vector<char> &fileBuffer)
{
    std::ifstream file(filePath, std::ios::binary);
    if(file.fail())
    {
        std::cout<<"failed to load file "<<filePath<<std::endl;
        return false;
    }

    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    fileBuffer.resize(fileSize);
    file.read(&(fileBuffer[0]), fileSize);
    file.close();

    std::cout<<"file "<<filePath<<" loaded successfully"<<std::endl;
    return true;
}
