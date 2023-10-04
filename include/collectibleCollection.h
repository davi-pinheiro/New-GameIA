#ifndef COLLECTIBLECOLLECTION_H
#define COLLECTIBLECOLLECTION_H

#include <vector>
#include <SDL2/SDL.h>
#include "coletavel.h"
#include "rgba.h"
#include "janela.h"

using std::vector;

class CollectibleCollection
{
private:
    vector<Coletavel*>* collectibleCollection;
public:
    CollectibleCollection();
    vector<Coletavel*>& getCollectibleCollection();
    void generateCollectibles(int altura, int largura);
};


#endif