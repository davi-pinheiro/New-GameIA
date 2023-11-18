#ifndef MOVETOENEMYNODE_H
#define MOVETOENEMYNODE_H

#include "rootNode.h"

class MoveToEnemyNode : public RootNode
{
    public:
    MoveToEnemyNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
};

#endif