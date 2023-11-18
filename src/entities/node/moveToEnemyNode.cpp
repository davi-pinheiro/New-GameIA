#include "moveToEnemyNode.h"

MoveToEnemyNode::MoveToEnemyNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario) : RootNode(mundo, tipoNode, proprietario)
{

}
bool MoveToEnemyNode::mainAction()
{
    int minDistancia = 136, distancia, indice;
    for(int i = 0; i < mundo.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(proprietario->getPersonagem()->x - mundo.retornarVivos(i)->getPersonagem()->x, 2) + pow(proprietario->getPersonagem()->y - mundo.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia <= proprietario->getRaioVisao())
        {
            if(distancia < minDistancia)
            {
                if((mundo.retornarVivos(i)->getTipoMonstro() == GUERREIRO) || 
                (mundo.retornarVivos(i)->getTipoMonstro() == PLAYER))
                {
                    minDistancia = distancia;
                    indice = i;
                }
            }
        }
    }

    if(proprietario->getPersonagem()->x - mundo.retornarVivos(indice)->getPersonagem()->x > 0)
    {
        if(proprietario->getPersonagem()->x - mundo.retornarVivos(indice)->getPersonagem()->x < 21)
        {
            proprietario->getPersonagem()->x += 21 - (proprietario->getPersonagem()->x - mundo.retornarVivos(indice)->getPersonagem()->x);
        }
        else
        {
            proprietario->getPersonagem()->x -= proprietario->getVelocidade();
        }
    }
    else if(proprietario->getPersonagem()->x - mundo.retornarVivos(indice)->getPersonagem()->x < 0)
    {
        if(proprietario->getPersonagem()->x - mundo.retornarVivos(indice)->getPersonagem()->x > -21)
        {
            proprietario->getPersonagem()->x -= -21 - (proprietario->getPersonagem()->x - mundo.retornarVivos(indice)->getPersonagem()->x);
        }
        else
        {
            proprietario->getPersonagem()->x += proprietario->getVelocidade();
        }
    }

    if(proprietario->getPersonagem()->y - mundo.retornarVivos(indice)->getPersonagem()->y > 0)
    {
        if(proprietario->getPersonagem()->y - mundo.retornarVivos(indice)->getPersonagem()->y < 21)
        {
            proprietario->getPersonagem()->y += 21 - (proprietario->getPersonagem()->y - mundo.retornarVivos(indice)->getPersonagem()->y);
        }
        else
        {
            proprietario->getPersonagem()->y -= proprietario->getVelocidade();
        }
    }
    else if(proprietario->getPersonagem()->y - mundo.retornarVivos(indice)->getPersonagem()->y < 0)
    {
        if(proprietario->getPersonagem()->y - mundo.retornarVivos(indice)->getPersonagem()->y > -21)
        {
            proprietario->getPersonagem()->y -= -21 - (proprietario->getPersonagem()->y - mundo.retornarVivos(indice)->getPersonagem()->y);
        }
        else
        {
            proprietario->getPersonagem()->y += proprietario->getVelocidade();
        }
    }
    return true;
}