#ifndef AREA_H
#define AREA_H

#include <SDL2/SDL.h>
#include <vector>
#include "subArea.h"

using std::vector;

class Area
{
    private:
        SDL_Rect* area;
        vector<SubArea*> subAreas;
        bool ativo;
    public:
        Area(int x, int y, int w, int h, bool ativo);

        int getX(void);
        int getY(void);
        int getW(void);
        int getH(void);
        bool isAtivo(void);

        void setX(int x);
        void setY(int y);
        void setW(int w);
        void setH(int h);
        void setAtivo(bool ativo);

        void adicionarSubArea(SubArea* subArea);
        void removerSubArea(SubArea* subArea);
        void removerSubArea(int indice);
        int tamanhoSubAreas(void);
        SubArea* retornarSubArea(int indice);
    };

#endif