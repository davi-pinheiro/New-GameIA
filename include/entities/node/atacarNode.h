#ifndef ATACARNODE_H
#define ATACARNODE_H

#include "rootNode.h"

class AtacarNode : public RootNode
{
    public:
    AtacarNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
};

#endif