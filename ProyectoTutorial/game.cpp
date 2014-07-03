#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"
#include "imagen.h"
using namespace std;

Game::Game(const char* title, int width, int height) {
    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_hola = new Imagen(m_renderer, "hola.bmp");
    m_running = false;
    img_x = img_y = 50.0;
    img_vx = img_vy = 0.0;

    m_keys = SDL_GetKeyboardState(NULL);
}

Game::~Game() {
    delete m_hola;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

void Game::Run() {
    m_running = true;
    while (m_running) {
        Input();
        Update();
        Render();
    }
}

void Game::Input() {
    while (SDL_PollEvent(&m_evento)) {
        HandleEvent();
    }
}

void Game::HandleEvent() {
    SDL_Scancode sc;
    SDL_Keycode kc;
    int boton,x,y;
    switch (m_evento.type) {
        case SDL_QUIT:
            m_running = false;
            break;
//        case SDL_MOUSEMOTION:
//            int x  = m_evento.motion.x , y = m_evento.motion.y;
//            cout << "El raton esta en (" << x << ", "<< y << ")." << endl;
//            break;
        case SDL_MOUSEBUTTONDOWN:
            boton = m_evento.button.button;
            cout << "Se ha pulsado el boton: " << boton << endl;
            break;
        case SDL_MOUSEBUTTONUP:
            boton = m_evento.button.button;
            cout << "Se ha levantado el boton: " << boton << endl;
            break;
        case SDL_MOUSEWHEEL:
            img_vx = x = m_evento.wheel.x;
            img_vy = y = m_evento.wheel.y;
            cout << "La rueda se ha desplazado en (" << x << ", "<< y << ")." << endl;
            break;
    }
}

void Game::Update() {
//    if (m_keys[SDL_SCANCODE_UP]) {
//        img_vy = -1;
//    } else if (m_keys[SDL_SCANCODE_DOWN]) {
//        img_vy = 1;
//    } else {
//        img_vy = 0;
//    }
//
//    if (m_keys[SDL_SCANCODE_LEFT]) {
//        img_vx = -1;
//    } else if (m_keys[SDL_SCANCODE_RIGHT]) {
//        img_vx = 1;
//    } else {
//        img_vx = 0;
//    }

    img_x += img_vx;
    img_y += img_vy;
}

void Game::Render() {
    SDL_RenderClear(m_renderer);
    m_hola->Render((int) img_x, (int) img_y);
    SDL_RenderPresent(m_renderer);
}
