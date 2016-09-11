#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>

extern int winHeight;
extern int winWidth;

class System
{
    public:
        System();
        virtual ~System();
        std::string getTitle();
        int getWinHeight();
        int getWinWidth();
        int getGLDepth();
        int getGLMajor();
        int getGLMinor();
    protected:
    private:
        int winHeight;
        int winWidth;
        int glMajorVersion;
        int glMinorVersion;
        int glDepth;
        static const std::string ENGINE_TITLE;
        static const std::string ASSETS_DIRECTORY;
        static const std::string CONFIG_FILE;
        void loadConfig(std::string cfgString);
        std::string getConfigValue(char* key, std::string configContents);
};

#endif // SYSTEM_H
