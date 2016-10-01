#include "GameEngine.h"
#include "ErrorHandler.h"
#include "Utility.h"

GameEngine::GameEngine():gameState(GameState::ACTIVE)
{
    std::cout<<"Constructed the Game engine"<<std::endl;
    window.registerSystem(system);
}

void GameEngine::killEngine()
{
    gameState = GameState::EXIT;
}

void GameEngine::doRun()
{
    testCanvas.build(-1.0, -1.0, 1.0, 1.0, "helloworld.png");
    initShaders();
    gameLoop();
}

void GameEngine::gameLoop()
{
    while(gameState != GameState::EXIT)
    {
        processInput();
        renderGame();
    }
}

void GameEngine::initShaders()
{
    testGLSL.compileShaders("assets/shaders/test.vert", "assets/shaders/test.frag");
    //testGLSL.addAttribute("vertexPosition");
    //testGLSL.addAttribute("vertexColor");
    //testGLSL.addAttribute("vertexUV");
    //testGLSL.linkShaders();

}

void GameEngine::processInput()
{
    SDL_Event evt;
    while(SDL_PollEvent(&evt))
    {
        switch(evt.type)
        {
            case SDL_QUIT:
                gameState = GameState::EXIT;
                break;

            case SDL_MOUSEMOTION:
                break;

            case SDL_KEYDOWN:
                std::cout<<SDL_GetKeyName(evt.key.keysym.sym)<<std::endl;
                break;
        }

    }
}

void GameEngine::renderGame()
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /** DO ALL RENDERING HERE **/
    testGLSL.apply();
    testCanvas.render();
    testGLSL.kill();
    /** DO ALL RENDERING HERE END **/

    SDL_Delay(100);
    SDL_GL_SwapWindow(window.getSDLWindow());
}

GameEngine::~GameEngine()
{
    std::cout<<"Destroying the Game engine"<<std::endl;
}
