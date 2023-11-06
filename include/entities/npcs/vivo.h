#ifndef VIVO_H
#define VIVO_H

#include <SDL2/SDL.h>
#include <vector>
#include "efeito.h"
#include "tipoMonstro.h"
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
    int raioVisao;
    Rgba rgba;
    State estado;
    SDL_Rect personagem;
    TipoMonstro tipoMonstro;

    vector<Efeito> efeitos;
public:
    Vivo(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro);

    int getId(void);
    int getVidaMaxima(void);
    int getVida(void);
    int getVelocidade(void);
    int getForca(void);
    int getRaioVisao(void);
    Rgba getRgba(void);
    State getEstado(void);
    SDL_Rect* getPersonagem(void);
    TipoMonstro getTipoMonstro(void);

    void setVidaMaxima(int vidaMaxima);
    void setVida(int vida);
    void setVelocidade(int velocidade);
    void setForca(int forca);
    void setRaioVisao(int raioVisao);
    void setEstado(State estado);
    void setTipoMonstro(TipoMonstro tipoMonstro);
};

#endif