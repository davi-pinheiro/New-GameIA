#include "normalWorld.h"

NormalWorld::NormalWorld(int tamanhoMapa, int proporcaoMapa, Camera& camera, Personagem* personagem)
{
    vivos.push_back(personagem);
    ativo = true;
    tipoMundo = NORMAL;
    background.setRgba(255,255,255,255);

    generateAreas(tamanhoMapa, proporcaoMapa);
    updateAreas(camera);
    generateEntities();
}