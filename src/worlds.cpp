#include <iostream>
#include "worlds.h"

using std::cout;
using std::endl;

int Worlds::tamanhoMundos(void)
{
    return (int)mundos.size();
}

BackMap* Worlds::getMundo(int indice)
{
    return mundos[indice];
}

void Worlds::adicionarMundo(BackMap* novoMundo)
{
    mundos.push_back(novoMundo);
}

bool Worlds::checkMundos()
{
    for(int i = 0; i < (int) mundos.size(); i++)
    {
        if((*mundos[i]).getProximoMundo() != ANY_WORLD)
        {
            return true;
        }
    }
    return false;
}

void Worlds::mudarMundo(Janela& janela)
{
    TipoMundo tmp;
    for(int i = 0; i < (int) mundos.size(); i++)
    {
        if((*mundos[i]).getProximoMundo() != ANY_WORLD)
        {
            tmp = (*mundos[i]).getProximoMundo();
            (*mundos[i]).setProximoMundo(ANY_WORLD);
            (*mundos[i]).setAtivo(false);
            break;
        }
    }
    for(int i = 0; i < (int) mundos.size(); i++)
    {
        if((*mundos[i]).getTipoMundo() == tmp)
        {
            (*mundos[i]).setAtivo(true);
            break;
        }
        else if((i == (int) mundos.size() - 1) &&
        ((*mundos[i]).getProximoMundo() != tmp))
        {
            (*mundos[0]).setAtivo(true);
        }
    }
    for(int i = 0; i < (int) mundos.size(); i++)
    {
        if((*mundos[i]).isAtivo())
        {
            janela.setMundo(mundos[i]);
        }
    }
}