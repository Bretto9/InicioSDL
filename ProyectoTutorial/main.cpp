#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "game.h"

using namespace std;
int main(int argc, char* argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect rectangulo;
    SDL_Event event;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cerr << "No se puede inicializar SDL" << endl;
        return 1;
    }
    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != (IMG_INIT_JPG | IMG_INIT_PNG)){
        cerr << "No se puede inicializar SDL_Image" << endl;
        SDL_Quit();
        return 1;
    }
    if(SDL_CreateWindowAndRenderer(1440,900,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL, &window, &renderer) < 0){
        cerr << "No se puede inicializar la interfaz" << endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_SetWindowTitle(window, "Hola, SDL");
    
    texture = IMG_LoadTexture(renderer, "ejemplo.png");
    rectangulo.x = rectangulo.y = 50;
    SDL_QueryTexture(texture, NULL, NULL, &rectangulo.w, &rectangulo.h);
    for(;;){
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                break;
            }
        }
        
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture,NULL, &rectangulo);
        SDL_RenderPresent(renderer);
    }
    
//    Game* game = new Game("Hola, mundo", 640, 360);
//    game->Run();
//    delete game;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
