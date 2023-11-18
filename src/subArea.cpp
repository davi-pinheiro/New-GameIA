#include "subArea.h"

SubArea::SubArea(int x, int y , int w, int h, int umidade, int temperatura)
{
    subArea = new SDL_Rect;

    subArea->x = x;
    subArea->y = y;
    subArea->w = w;
    subArea->h = h;

    this->umidade = umidade;
    this->temperatura = temperatura;

    barreira = false;
    rgba.setRgba(0, 0, 0, 255);
}

int SubArea::getX(void)
{
    return subArea->x;
}
int SubArea::getY(void)
{
    return subArea->y;
}
int SubArea::getW(void)
{
    return subArea->w;
}
int SubArea::getH(void)
{
    return subArea->h;
}
int SubArea::getUmidade(void)
{
    return umidade;
}
int SubArea::getTemperatura(void)
{
    return temperatura;
}
bool SubArea::isBarreira()
{
    return barreira;
}


SDL_Rect* SubArea::getSubArea()
{
    return subArea;
}


void SubArea::setX(int x)
{
    subArea->x = x;
}
void SubArea::setY(int y)
{
    subArea->y = y;
}
void SubArea::setW(int w)
{
    subArea->w = w;
}
void SubArea::setH(int h)
{
    subArea->h = h;
}
void SubArea::setUmidade(int umidade)
{
    this->umidade = umidade;
}
void SubArea::setTemperatura(int temperatura)
{
    this->temperatura = temperatura;
}
void SubArea::setBarreira(bool barreira)
{
    this->barreira = barreira;
}