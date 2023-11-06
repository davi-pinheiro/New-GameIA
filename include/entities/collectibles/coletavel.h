#ifndef COLETAVEL_H
#define COLETAVEL_H

#include <SDL2/SDL.h>
#include "rgba.h"

class Coletavel
{
protected:
    int id;
    SDL_Rect coletavel;
    Rgba rgba;
public:
    Coletavel(int id, int x, int y, int w, int h, Rgba rgba);

    SDL_Rect* getColetavel(void);
    Rgba getRgba(void);

};

#endif