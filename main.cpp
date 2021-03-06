/* A simple program to show how to set up an X window for OpenGL rendering.
 * X86 compilation: gcc -o -L/usr/X11/lib   main main.c -lGL -lX11
 * X64 compilation: gcc -o -L/usr/X11/lib64 main main.c -lGL -lX11
 */
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "include/PngLoader.h"
#include "GameEngine.h"


int main(int argc, char *argv[])
{
    //PngLoader png = PngLoader("helloworld.png");
    //GLuint tex = PngLoader::load("helloworld.png");
    //WindowHandler win(sys);

    GameEngine engine;
    engine.doRun();

    return 0;
}
