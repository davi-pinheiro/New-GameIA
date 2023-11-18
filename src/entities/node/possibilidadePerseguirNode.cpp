#include "possibilidadePerseguirNode.h"
#include "nextToEnemyNode.h"
#include "moveToEnemyNode.h"

PossibilidadePerseguirNode::PossibilidadePerseguirNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario) : RootNode(mundo,tipoNode, proprietario)
{
    NextToEnemyNode* nextToEnemy = new NextToEnemyNode(mundo, NONE_TIPONODE, proprietario);
    MoveToEnemyNode* moveToEnemy = new MoveToEnemyNode(mundo, NONE_TIPONODE, proprietario);

    nodes.push_back(nextToEnemy);
    nodes.push_back(moveToEnemy);
}
bool PossibilidadePerseguirNode::mainAction()
{
    return node_controller();
}