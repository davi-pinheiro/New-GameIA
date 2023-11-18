#include "area.h"

Area::Area(int x, int y, int w, int h, bool ativo)
{
    area = new SDL_Rect;
    area->x = x;
    area->y = y;
    area->w = w;
    area->h = h;

    this->ativo = ativo;
}

int Area::getX(void)
{
    return area->x;
}
int Area::getY(void)
{
    return area->y;
}
int Area::getW(void)
{
    return area->w;
}
int Area::getH(void)
{
    return area->h;
}
bool Area::isAtivo(void)
{
    return ativo;
}

void Area::setX(int x)
{
    area->x = x;
}
void Area::setY(int y)
{
    area->y = y;
}
void Area::setW(int w)
{
    area->w = w;
}
void Area::setH(int h)
{
    area->h = h;
}
void Area::setAtivo(bool ativo)
{
    this->ativo = ativo;
}

void Area::adicionarSubArea(SubArea* subArea)
{
    subAreas.push_back(subArea);
}
void Area::removerSubArea(SubArea* subArea)
{
    for(int i = 0; i < (int) subAreas.size(); i++)
    {
        if((subAreas[i]->getX() == subArea->getX()) &&
        (subAreas[i]->getY() == subArea->getY()))
        {
            subAreas.erase(subAreas.begin() + i);
            break;
        }
    }
}
void Area::removerSubArea(int indice)
{
    subAreas.erase(subAreas.begin() + indice);
}
int Area::tamanhoSubAreas(void)
{
    return (int) subAreas.size();
}
SubArea* Area::retornarSubArea(int indice)
{
    return subAreas[indice];
}
