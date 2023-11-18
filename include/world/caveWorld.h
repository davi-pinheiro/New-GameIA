/*int tamanhoMapa;
bool ativo;
vector<Area*> areas;
vector<Vivo*> vivos;
vector<Coletavel*> coletaveis;
Rgba background;
TipoMundo tipoMundo;
TipoMundo proximoMundo;

class Cave
*/
#ifndef CAVEWORLD_H
#define CAVEWORLD_H

#include <vector>
#include "backMap.h"
#include "personagem.h"

using std::vector;

class CaveWorld : public BackMap
{
    private:

    public:
    CaveWorld(int tamanhoMapa, int proporcaoMapa, Camera& camera, Personagem* personagem);

    void generateLabyrinth(void);
    void generateEntities(void);
};

#endif