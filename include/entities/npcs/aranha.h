#ifndef ARANHA_H
#define ARANHA_H

#include <SDL2/SDL.h>
#include "backMap.h"
#include "rootNode.h"
#include "vivo.h"
#include "state.h"
#include "rgba.h"


class Aranha : public Vivo
{
private:
    RootNode* rootNode;

public:
    Aranha(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro, BackMap mundo);
    //void machine(BackMap backMap);

    void execute_tree();
};

#endif