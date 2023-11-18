#include "noPathfinder.h"

NoPathfinder::NoPathfinder(SubArea* subArea)
{
    x = subArea->getX();
    y = subArea->getY();
}

int NoPathfinder::getX()
{
    return x;
}
int NoPathfinder::getY()
{
    return y;
}
int NoPathfinder::getCustoReal()
{
    return custoReal;
}
int NoPathfinder::getCustoRelativo()
{
    return custoRelativo;

}

void NoPathfinder::calcular_custo_relativo(NoPathfinder destino)
{
    int heuristica = ((destino.getX() - x) + (destino.getY() - y)) / 30;
    if(heuristica < 0)
    {
        heuristica = - heuristica;
    }
    custoRelativo = heuristica;
}

void NoPathfinder::setCustoReal(int custoReal)
{
    this->custoReal = custoReal;
}

void NoPathfinder::addNoPai(NoPathfinder noPai)
{
    this->noPai = &noPai;
}

NoPathfinder* NoPathfinder::getNoPai()
{
    return noPai;
}

