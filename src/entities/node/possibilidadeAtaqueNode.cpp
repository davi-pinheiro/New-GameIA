#include <iostream>
#include "possibilidadeAtaqueNode.h"
#include "attackConditionNode.h"
#include "atacarNode.h"

using std::cout;
using std::cerr;
using std::endl;

PossibilidadeAtaqueNode::PossibilidadeAtaqueNode(BackMap mundo, TipoNode tipoNode, Vivo* proprietario) : RootNode(mundo, tipoNode, proprietario)
{
    //this->tipoNode = SEQUENCE;

    AttackConditionNode* condicao_ataque = new AttackConditionNode(mundo, NONE_TIPONODE, proprietario);
    AtacarNode* ataque = new AtacarNode(mundo, NONE_TIPONODE, proprietario);

    nodes.push_back(condicao_ataque);
    nodes.push_back(ataque);
}
bool PossibilidadeAtaqueNode::mainAction()
{
    cout << "Possibilidade de Ataque" << endl;
    return this->mainAction();
}