#include <SDL2/SDL.h>
#include <iostream>
#include "imagen.h"

Imagen::Imagen(SDL_Renderer* renderer, const char* ruta)
{
    SDL_Surface* image_surface;

    m_renderer = renderer;
    image_surface = SDL_LoadBMP(ruta);
    m_textura = SDL_CreateTextureFromSurface(renderer, image_surface);
    m_posicion.w = image_surface->w;
    m_posicion.h = image_surface->h;
    SDL_FreeSurface(image_surface);
}

Imagen::~Imagen()
{
    SDL_DestroyTexture(m_textura);
}

void Imagen::Render(int x, int y)
{
    m_posicion.x = x;
    m_posicion.y = y;
    SDL_RenderCopy(m_renderer, m_textura, NULL, &m_posicion);
}
