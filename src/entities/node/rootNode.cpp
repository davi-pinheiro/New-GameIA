#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

#include "rootNode.h"

RootNode::RootNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario)
{
    this->mundo = mundo;
    this->tipoNode = tipoNode;
    this->proprietario = proprietario;
}

bool RootNode::mainAction()
{
    //return true;
}

bool RootNode::sequenceNode()
{
    int count = 0;
    for(int i = 0; i < (int)nodes.size(); i++)
    {
        if(nodes[i]->mainAction())
        {
            count++;
        }
        else
        {
            break;
        }
    }
    if(count == (int)nodes.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool RootNode::selectionNode()
{
    for(int i = 0; i < (int)nodes.size(); i++)
    {
        if(nodes[i]->mainAction())
        {
            return true;
        }
    }
    return false;
}

bool RootNode::node_controller()
{
    switch (tipoNode)
    {
    case SEQUENCE:
        return sequenceNode();
        break;
    case SELECTION:
        return selectionNode();
        break;
    case NONE_TIPONODE:
        return mainAction();
        break;
    
    default:
        break;
    }
    return false;
}

void RootNode::addNodes(RootNode* node)
{
    nodes.push_back(node);
}

RootNode* RootNode::retornarNo(int indice)
{
    return nodes[indice];
}