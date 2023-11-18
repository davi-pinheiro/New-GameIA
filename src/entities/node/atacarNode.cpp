#include "atacarNode.h"

AtacarNode::AtacarNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario) : RootNode(mundo, tipoNode, proprietario)
{
    
}
bool AtacarNode::mainAction()
{
    int distancia, indice;
    for(int i = 0; i < mundo.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(proprietario->getPersonagem()->x - mundo.retornarVivos(i)->getPersonagem()->x, 2) + pow(proprietario->getPersonagem()->y - mundo.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia <= 21)
        {
            if(mundo.retornarVivos(i)->getTipoMonstro() == PLAYER)
            {
                indice = i;
            }
        }
    }

    mundo.retornarVivos(indice)->setVida(mundo.retornarVivos(indice)->getVida() - proprietario->getForca());

    if(mundo.retornarVivos(indice)->getVida() <= 0)
    {
        delete mundo.retornarVivos(indice);
        mundo.deleteVivo(indice);
    }
    return true;
}