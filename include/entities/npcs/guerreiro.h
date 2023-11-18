#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <SDL2/SDL.h>
#include "backMap.h"
#include "vivo.h"
#include "state.h"
#include "rgba.h"
#include "personagem.h"


class Guerreiro : public Vivo
{
private:

public:
    Guerreiro(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro, BackMap mundo);
    void machine(BackMap backMap);
};

#endif