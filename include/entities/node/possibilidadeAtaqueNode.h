#ifndef POSSIBILIDADEATAQUENODE_H
#define POSSIBILIDADEATAQUENODE_H

#include "rootNode.h"

class PossibilidadeAtaqueNode : public RootNode
{
    public:
    PossibilidadeAtaqueNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
};

#endif