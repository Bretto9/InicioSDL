#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <SDL2/SDL.h>

class Imagen
{
public:
    Imagen(SDL_Renderer* renderer, const char* ruta);
    ~Imagen();
    void Render(int x, int y);
private:
    SDL_Texture* m_textura;
    SDL_Renderer* m_renderer;
    SDL_Rect m_posicion;
};

#endif // IMAGEN_H_
