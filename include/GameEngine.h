#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "System.h"
#include "WindowHandler.h"
#include "ErrorHandler.h"

#include "Canvas2D.h"
#include "GLSLHandler.h"

enum GameState {ACTIVE, EXIT};

class GameEngine
{
    public:
        GameEngine();
        virtual ~GameEngine();
        void doRun();
        void killEngine();
        void initShaders();
    protected:
    private:
        void gameLoop();
        void processInput();
        void renderGame();
        WindowHandler window;
        System system;
        GameState gameState;

        //For testing
        Canvas2D testCanvas;
        GLSLHandler testGLSL;
        GLuint testShader;
};

#endif // GAMEENGINE_H
