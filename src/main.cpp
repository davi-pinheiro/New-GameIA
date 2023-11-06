#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "janela.h"
#include "personagem.h"
#include "tempo.h"
#include "camera.h"
#include "normalWorld.h"
#include "worlds.h"
#include "caveWorld.h"

using std::cout;
using std::endl;
using std::rand;
using std::cerr;
using std::vector;

const int MAPAH = 3240;
const int MAPAW = 3240;

const int ALTURA = 700;
const int LARGURA = 700;

int main(int argc, char const *argv[])
{
    Worlds mundos;
    Camera camera(MAPAW, MAPAH, LARGURA, ALTURA);
    Tempo tempo(180);
    Personagem* personagem = new Personagem(3000, 50, 5, 3, 350, NONE, 20, 20, MAPAW/2, MAPAH/2, PLAYER);

    NormalWorld nw;
    mundos.adicionarMundo(&nw);
    nw.generateAreas(MAPAH, 3);
    nw.updateAreas(camera);
    nw.generateEntities();

    cout << nw.tamanhoVectorVivos() << endl;
    cout << mundos.getMundo(0)->tamanhoVectorVivos() << endl;
    cout << endl;

    CaveWorld cw;
    mundos.adicionarMundo(&cw);
    cw.generateAreas(MAPAH, 3);
    cw.updateAreas(camera);
    cw.generateEntities();

    SDL_Init(SDL_INIT_VIDEO);

    Janela janela(MAPAH, MAPAW, ALTURA, LARGURA);

    for(int i = 0; i < mundos.tamanhoMundos(); i++)
    {
        if(mundos.getMundo(i)->isAtivo() == true)
        {
            janela.setMundo(mundos.getMundo(i));
        }
    }

    cout << janela.getMundo()->tamanhoVectorVivos() << endl;

    SDL_ShowWindow(janela.getJanela());
    SDL_Event* evento = new SDL_Event;

    while (!SDL_QuitRequested())
    {
        while (SDL_PollEvent(evento))
        {
            personagem->controle(evento, camera);
            if(evento->type == SDL_KEYDOWN){
    
                switch(evento->key.keysym.sym)
                {
                    case SDLK_c:
                        janela.getMundo()->setProximoMundo(CAVE);
                        mundos.mudarMundo(janela);
                        break;
                    case SDLK_n:
                        janela.getMundo()->setProximoMundo(NORMAL);
                        mundos.mudarMundo(janela);
                        break;
                }
            }
    
        }
        /*if(mundos.checkMundos())
        {
            mundos.mudarMundo(janela);
        }*/
        janela.getMundo()->updateAreas(camera);

        SDL_SetRenderTarget(janela.getRenderizador(), janela.getTextura());

        janela.backgroundColor(tempo);
        janela.renderizarCollectibles(nw);
        janela.renderizarMonsters();
        janela.renderizarCharacter(personagem);
        
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
