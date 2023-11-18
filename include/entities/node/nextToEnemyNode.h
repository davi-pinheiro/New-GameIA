#ifndef NEXTTOENEMYNODE_H
#define NEXTTOENEMYNODE_H

#include "rootNode.h"

class NextToEnemyNode : public RootNode
{
    public:
    NextToEnemyNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
};

#endif