#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <SDL2/SDL.h>
#include "vivo.h"
#include "state.h"
#include "rgba.h"
#include "personagem.h"


class Guerreiro : public Vivo
{
private:

public:
    Guerreiro(int id, int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado);
    void machine(void);
};

#endif