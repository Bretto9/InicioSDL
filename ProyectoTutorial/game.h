#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include "imagen.h"

class Game
{
public:
    Game(const char* title, int width, int height);
    ~Game();
    void Run();
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Event m_evento;
    bool m_running;
    Imagen* m_hola;

    float img_x, img_y, img_vx, img_vy;

    const Uint8* m_keys;

    void Input();
    void HandleEvent();
    void Update();
    void Render();
};

#endif // _GAME_H_
