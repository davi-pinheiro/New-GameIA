#ifndef SUBAREA_H
#define SUBAREA_H

#include <SDL2/SDL.h>

class SubArea 
{
    private:
        SDL_Rect* subArea;
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

        void setX(int x);
        void setY(int y);
        void setW(int w);
        void setH(int h);
        void setUmidade(int umidade);
        void setTemperatura(int temperatura);
        void setBarreira(bool barreira);
};

#endif