#include "rgba.h"

Rgba::Rgba(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

int Rgba::getR()
{
    return r;
}

int Rgba::getG()
{
    return g;
}

int Rgba::getB()
{
    return b;
}

int Rgba::getA()
{
    return a;
}

void Rgba::setRgba(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}