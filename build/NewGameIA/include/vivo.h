#ifndef VIVO_H
#define VIVO_H

#include <SDL2/SDL.h>
#include <vector>
#include "rgba.h"
#include "state.h"

using std::vector;

class Vivo
{
protected:
    int id;
    int vidaMaxima;
    int vida;
    int velocidade;
    int forca;
    bool isEnemy;
    SDL_Rect personagem;
    vector<Vivo*> inimigos;
    State estado;

    Rgba rgba;
public:
    Vivo(int id, int vidaMaxima, int velocidade, int forca, bool inimigo, int h, int w, int x, int y, Rgba rgba, State estado);

    int getId(void);
    int getVidaMaxima(void);
    int getVida(void);
    int getVelocidade(void);
    int getForca(void);
    bool getIsEnemy(void);
    vector<Vivo*> getInimigos(void);
    State getEstado(void);

    void setId(int id);
    void setVidaMaxima(int vidaMaxima);
    void setVida(int vida);
    void setVelocidade(int velocidade);
    void setForca(int forca);
    void setIsEnemy(bool isEnemy);
    void setInimigos(vector<Vivo*> inimigos);
    void setEstado(State estado);

    SDL_Rect* getPersonagem(void);
    Rgba getRgba(void);

    void machine();
};

#endif