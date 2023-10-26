#ifndef MONSTERCOLLECTION_H
#define MONSTERCOLLECTION_H

#include <vector>
#include <SDL2/SDL.h>
#include "state.h"
#include "vivo.h"
#include "rgba.h"
#include "janela.h"

using std::vector;

class MonsterCollection
{
private:
    vector<Vivo*> monsterCollection;
public:
    vector<Vivo*>& getMonsterCollection();
    void generateMonsters(int altura, int largura);
    void setInimigos(vector<Vivo*> inimigos);
    
};


#endif