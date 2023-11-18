#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include <vector>
#include "rootNode.h"
#include "backMap.h"
#include "vivo.h"

using std::vector;

class BehaviorTree
{
    private:
    RootNode* noRaiz;
    RootNode* ponteiro;
    Vivo* proprietario;
    public:
    BehaviorTree(BackMap mundo, Vivo* proprietario);
    void adicionarNo(RootNode no, RootNode* ponteiro);

};

#endif