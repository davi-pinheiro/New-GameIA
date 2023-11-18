#include "attackConditionNode.h"

AttackConditionNode::AttackConditionNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario) : RootNode(mundo, tipoNode, proprietario)
{

}
bool AttackConditionNode::mainAction()
{
    int distancia;
    for(int i = 0; i < mundo.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(proprietario->getPersonagem()->x - mundo.retornarVivos(i)->getPersonagem()->x, 2) + pow(proprietario->getPersonagem()->y - mundo.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia < 21)
        {
            if(mundo.retornarVivos(i)->getTipoMonstro() == PLAYER)
            {
                return true;
            }
        }
    }
    return false;
}