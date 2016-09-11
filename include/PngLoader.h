#ifndef PNGLOADER_H
#define PNGLOADER_H

#include <iostream>
#include <stdio.h>

class PngLoader
{
    public:
        PngLoader(std::string pngName);
        std::string getName();
        virtual ~PngLoader();
    protected:
        std::string ASSETS_DIR;
    private:
        int load();
        std::string name;
};

#endif // PNGLOADER_H
