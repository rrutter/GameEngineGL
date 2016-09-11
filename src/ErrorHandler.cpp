#include "ErrorHandler.h"
#include "SDL.h"
#include <iostream>

void printError(std::string errorString)
{
    std::cout<<"ERROR: "<<errorString<<std::endl;
    std::cout<<"Enter any key to exit..."<<std::endl;

    char tmp;
    std::cin >> tmp;
    SDL_Quit();
}
