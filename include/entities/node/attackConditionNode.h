#ifndef ATTACKCONDITIONNODE_H
#define ATTACKCONDITIONNODE_H

#include "rootNode.h"

class AttackConditionNode : public RootNode
{
    public:
    AttackConditionNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
};

#endif