#include "nextToEnemyNode.h"

NextToEnemyNode::NextToEnemyNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario) : RootNode(mundo, tipoNode, proprietario)
{

}
bool NextToEnemyNode::mainAction()
{
    int distancia;
    for(int i = 0; i < mundo.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(proprietario->getPersonagem()->x - mundo.retornarVivos(i)->getPersonagem()->x, 2) + pow(proprietario->getPersonagem()->y - mundo.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia < proprietario->getRaioVisao())
        {
            if(mundo.retornarVivos(i)->getTipoMonstro() == PLAYER)
            {
                return true;
            }
        }
    }
    return false;
}