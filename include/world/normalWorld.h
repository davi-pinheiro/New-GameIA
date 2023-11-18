#ifndef NORMALWORLD_H
#define NORMALWORLD_H

#include "backMap.h"
#include "personagem.h"

class NormalWorld : public BackMap
{
    private:

    public:
    NormalWorld(int tamanhoMapa, int proporcaoMapa, Camera& camera, Personagem* personagem);
    
};

#endif