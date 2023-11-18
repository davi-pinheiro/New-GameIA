#include "behaviorTree.h"

BehaviorTree::BehaviorTree(BackMap mundo, Vivo* proprietario)
{
    noRaiz = new RootNode (mundo, SELECTION, proprietario);
    ponteiro = noRaiz;
    this->proprietario = proprietario;
}