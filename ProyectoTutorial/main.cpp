#include <SDL2/SDL.h>
#include "game.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Game* game = new Game("Hola, mundo", 640, 360);
    game->Run();
    delete game;
    SDL_Quit();
}
