#include "coletavel.h"

Coletavel::Coletavel(int id, int x, int y, int w, int h, Rgba rgba)
{
    this->id = id;
    this->coletavel.x = x;
    this->coletavel.y = y;
    this->coletavel.w = w;
    this->coletavel.h = h;

    this->rgba = rgba;
}

SDL_Rect* Coletavel::getColetavel(void)
{
    return &coletavel;
}

Rgba Coletavel::getRgba(void)
{
    return rgba;
}