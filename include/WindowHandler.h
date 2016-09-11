#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SDL.h>
#include "System.h"

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
    #else
    #define GLEW_STATIC
    #define GL3_PROTOTYPES 1
    #include <GL/glew.h>
#endif


class WindowHandler
{
    public:
        WindowHandler();
        WindowHandler(System &);
        SDL_Window* getSDLWindow();
        void registerSystem(System &);
        virtual ~WindowHandler();
        int doTest();
    protected:
    private:
        const char* title;
        void killSdl(const char *);
        void checkSdlError(int);
        SDL_Window* window;
        SDL_GLContext mainContext;
};

#endif // WINDOWHANDLER_H
