#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <list>
#include <stack>
#include <vector>
#include "noPathfinder.h"
#include "subArea.h"
#include "backMap.h"

using std::list;
using std::stack;
using std::vector;

class Pathfinder
{
    private:
        SDL_Rect origem;
        BackMap mapa;
        stack<NoPathfinder> caminho;
        vector<NoPathfinder> abertos;
        vector<NoPathfinder> fechados;
    public:
        void createPathFinder(SDL_Rect& npcOrigem, SDL_Rect& npcDestino, BackMap mapa);

        void calcular_f(NoPathfinder* ponteiro);

        void create_nodes(NoPathfinder* ponteiro, NoPathfinder destino, BackMap mapa);

        void close_node(NoPathfinder* ponteiro);

        stack<NoPathfinder> getCaminho();


};

#endif