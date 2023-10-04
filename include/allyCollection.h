#ifndef ALLYCOLLECTION_H
#define ALLYCOLLECTION_H

#include <vector>
#include <SDL2/SDL.h>
#include "vivo.h"
#include "rgba.h"
#include "janela.h"

using std::vector;

class AllyCollection
{
private:
    vector<Vivo*> allyCollection;
public:
    vector<Vivo*>& getAllyCollection();
    void generateAllies(int altura, int largura);
    void setInimigos(vector<Vivo*> inimigos);
};


#endif