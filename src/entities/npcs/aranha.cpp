#include "aranha.h"
#include "possibilidadeAtaqueNode.h"
#include "possibilidadePerseguirNode.h"

Aranha::Aranha(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro, BackMap mundo) : Vivo(id, vidaMaxima, velocidade, forca, raioVisao, estado, h, w, x, y, tipoMonstro)
{
    this->rgba = Rgba(00,67,00,255);
    
    this->rootNode = new RootNode(mundo, SELECTION, this);

    PossibilidadeAtaqueNode* possibilidade_ataque = new PossibilidadeAtaqueNode(mundo, SEQUENCE, this);
    PossibilidadePerseguirNode* possibilidade_perseguir = new PossibilidadePerseguirNode(mundo, SEQUENCE, this);

    rootNode->addNodes(possibilidade_ataque);
    rootNode->addNodes(possibilidade_perseguir);
}

void Aranha::execute_tree()
{
    rootNode->node_controller();
}