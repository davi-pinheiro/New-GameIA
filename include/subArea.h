#ifndef SUBAREA_H
#define SUBAREA_H

#include <SDL2/SDL.h>
#include "rgba.h"

class SubArea 
{
    private:
        SDL_Rect* subArea;
        Rgba rgba;
        int umidade;
        int temperatura;
        bool barreira;
    public:
        SubArea(int x, int y , int w, int h, int umidade, int temperatura);

        int getX(void);
        int getY(void);
        int getW(void);
        int getH(void);
        int getUmidade(void);
        int getTemperatura(void);
        bool isBarreira();

        SDL_Rect* getSubArea();

        void setX(int x);
        void setY(int y);
        void setW(int w);
        void setH(int h);
        void setUmidade(int umidade);
        void setTemperatura(int temperatura);
        void setBarreira(bool barreira);
};

#endif