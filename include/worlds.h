#ifndef WORLDS_H
#define WORLDS_H

#include <vector>
#include "janela.h"
#include "backMap.h"

using std::vector;

class Worlds
{
    private:
        vector<BackMap*> mundos;
    public:
        int tamanhoMundos(void);
        BackMap* getMundo(int indice);
        void adicionarMundo(BackMap* novoMundo);
        bool checkMundos(void);
        void mudarMundo(Janela& janela);
};

#endif