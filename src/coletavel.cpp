#include "coletavel.h"

Coletavel::Coletavel(int x, int y, int w, int h, Rgba rgba)
{
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