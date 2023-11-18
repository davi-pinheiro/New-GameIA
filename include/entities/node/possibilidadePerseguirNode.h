#ifndef POSSIBILIDADEPERSEGUIRNODE_H
#define POSSIBILIDADEPERSEGUIRNODE_H

#include "rootNode.h"

class PossibilidadePerseguirNode : public RootNode
{
    public:
    PossibilidadePerseguirNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
};

#endif