#ifndef ROOTNODE_H
#define ROOTNODE_H

#include <vector>
#include "backMap.h"
#include "tipoNode.h"

using std::vector;

class RootNode
{
    protected:
    BackMap mundo;
    TipoNode tipoNode;
    Vivo* proprietario;
    vector<RootNode*> nodes;
    public:
    RootNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario);
    bool mainAction();
    bool sequenceNode();
    bool selectionNode();
    bool node_controller();
    RootNode* retornarNo(int indice);

    void addNodes(RootNode* node);
};
#endif