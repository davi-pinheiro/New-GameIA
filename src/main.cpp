#include <iostream>
#include <SDL2/SDL.h>
#include "controle.h"
#include "vivo.h"
#include "janela.h"
#include "rgba.h"
#include "vampiro.h"
#include "monsterCollection.h"
#include "collectibleCollection.h"
#include "allyCollection.h"
#include "personagem.h"
#include "tempo.h"
#include "camera.h"
#include "denteAlho.h"


using std::rand;
using std::cerr;
using std::vector;

const int MAPAH = 3240;
const int MAPAW = 3240;

const int ALTURA = 700;
const int LARGURA = 700;

int main(int argc, char const *argv[])
{
    
    Camera camera(MAPAW, MAPAH, LARGURA, ALTURA);
    Tempo tempo(15);

    CollectibleCollection* colecaoCollectible = new CollectibleCollection;
    colecaoCollectible->generateCollectibles(MAPAH, MAPAW);

    MonsterCollection* colecaoMonster = new MonsterCollection;
    colecaoMonster->generateMonsters(MAPAH, MAPAW);

    AllyCollection* colecaoAlly = new AllyCollection;
    colecaoAlly->generateAllies(MAPAH, MAPAW);
    
    Personagem* personagem = new Personagem(50, 5, 3, false, 20, 20, MAPAW/2, MAPAH/2, NONE);
    colecaoAlly->getAllyCollection().push_back(personagem);
    
    colecaoMonster->setInimigos(colecaoAlly->getAllyCollection());
    //
    colecaoAlly->setInimigos(colecaoMonster->getMonsterCollection());
    //
    SDL_Init(SDL_INIT_VIDEO);

    Janela janela(MAPAH, MAPAW, ALTURA, LARGURA);
    SDL_ShowWindow(janela.getJanela());
    //Rgba rgba(0, 0, 0, 0);
    SDL_Event* evento = new SDL_Event;

    while (!SDL_QuitRequested())
    {
        while (SDL_PollEvent(evento))
        {
            controle(personagem, evento, camera);
        }
            
        SDL_SetRenderTarget(janela.getRenderizador(), janela.getTextura());
        janela.backgroundColor(tempo);
        
        janela.renderizarCollectibles(colecaoCollectible->getCollectibleCollection(), camera);
        janela.renderizarCharacter(personagem);
        janela.renderizarMonsters(colecaoMonster->getMonsterCollection(), camera);
        janela.renderizarAllies(colecaoAlly->getAllyCollection(), camera);
        
        SDL_SetRenderTarget(janela.getRenderizador(), NULL);
        SDL_RenderCopy(janela.getRenderizador(), janela.getTextura(),camera.getCamera(), camera.getFilme());

        SDL_RenderPresent(janela.getRenderizador());
        SDL_Delay(100);

        if(SDL_QuitRequested())
        {
            break;
        }
    }
    
    janela.~Janela();
    

    return 0;
}
