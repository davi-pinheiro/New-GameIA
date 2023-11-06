#ifndef VAMPIRO_H
#define VAMPIRO_H

#include <SDL2/SDL.h>
#include "backMap.h"
#include "vivo.h"
#include "state.h"
#include "rgba.h"
#include "personagem.h"

class Vampiro : public Vivo
{
private:
    
public:
    Vampiro(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro);
    bool isNextToEnemy(BackMap& backMap);
    bool isAttackCondition(BackMap& backMap);
    void moveToPlayer(BackMap& backMap);
    void attack(BackMap& backMap);

    void machine(BackMap& backMap);
};

#endif