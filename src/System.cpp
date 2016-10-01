#include "System.h"
#include <SDL.h>
#include "Utility.h"

const std::string System::ASSETS_DIRECTORY = "assets/";
const std::string System::CONFIG_FILE = "config.cfg";
const std::string System::ENGINE_TITLE = "Game Engine v0.01";

System::System()
{
    //ctor
    std::cout<<"System Inited"<<std::endl;

        loadConfig(ASSETS_DIRECTORY+CONFIG_FILE);
}

System::~System()
{
    //dtor
    std::cout<<"System Destroyed"<<std::endl;
}

void System::loadConfig(std::string cfgString)
{

    std::ifstream inFile;
    inFile.open(cfgString);//open the input file

    std::stringstream strStream;
    strStream << inFile.rdbuf();//read the file
    std::string str = strStream.str();//str holds the content of the file

    winHeight = std::stoi(getConfigValue("winHeight", str));
    winWidth = std::stoi(getConfigValue("winWidth", str));
    glMajorVersion = std::stoi(getConfigValue("glMajor", str));
    glMinorVersion = std::stoi(getConfigValue("glMinor", str));
    glDepth = std::stoi(getConfigValue("glDepth", str));
}

std::string System::getConfigValue(char* key, std::string configContents)
{
    std::size_t keyPos = configContents.find (key);
    std::string keyValue;

    if (keyPos!=std::string::npos)
    {
        for(std::string::size_type i = keyPos+sizeof(key)+1; i < configContents.size(); i++)
            {
                if(configContents[i] != '\n')
                {
                    if(configContents[i] !=' ' && configContents[i]!='=')keyValue+=(configContents[i]);
                }
                else if(configContents[i] == '\n')
                {
                    i=configContents.size();
                    std::cout<<"key:"<<key<<" value:"<<keyValue<<std::endl;
                }
            }
    }
    return keyValue;

}

int System::getGLDepth()
{
    return glDepth;
}

int System::getGLMajor()
{
    return glMajorVersion;
}

int System::getGLMinor()
{
    return glMinorVersion;
}

int System::getWinHeight()
{
    return winHeight;
}

int System::getWinWidth()
{
    return winWidth;
}

std::string System::getTitle()
{
    return ENGINE_TITLE;
}
