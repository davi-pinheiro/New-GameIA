#ifndef NOPATHFINDER_H
#define NOPATHFINDER_H

#include <vector>
#include "subArea.h"
#include "backMap.h"

class NoPathfinder
{
private:
    int x;
    int y;
    int custoReal;
    int custoRelativo;
    NoPathfinder* noPai;

public:
    NoPathfinder(SubArea *subArea);

    int getX();
    int getY();
    int getCustoReal();
    int getCustoRelativo();

    void calcular_custo_relativo(NoPathfinder destino);
    void setCustoReal(int custoReal);

    void addNoPai(NoPathfinder noPai);
    NoPathfinder* getNoPai();
};

#endif