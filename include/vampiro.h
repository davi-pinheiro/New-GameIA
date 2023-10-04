#ifndef VAMPIRO_H
#define VAMPIRO_H

#include <SDL2/SDL.h>
#include "vivo.h"
#include "state.h"
#include "rgba.h"
#include "personagem.h"

class Vampiro : public Vivo
{
private:
    
public:
    Vampiro(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado);
    bool isNextToEnemy();
    bool isAttackCondition();
    void moveToPlayer();

    void machine();
};

#endif