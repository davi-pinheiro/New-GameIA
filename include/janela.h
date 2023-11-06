#ifndef JANELA_H
#define JANELA_H

#include <vector>
#include <SDL2/SDL.h>
#include "vivo.h"
#include "coletavel.h"
#include "rgba.h"
#include "tempo.h"
#include "personagem.h"
#include "camera.h"
#include "backMap.h"

using std::vector;

class Janela
{
private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    SDL_Texture* textura;
    BackMap* mundo;
    int altura;
    int largura;

public:
    Janela(int mapaAltura, int mapaLargura, int telaAltura, int telaLargura);

    int getAltura();
    int getLargura();
    SDL_Renderer* getRenderizador();
    SDL_Window* getJanela();
    SDL_Texture* getTextura();

    BackMap* getMundo(void);
    void setMundo(BackMap* mundo);

    void setAltura(int altura);
    void setLargura(int largura);

    void backgroundColor(Tempo& tempo);
    void frontgroundColor(Rgba rgba);

    void renderizarMonsters();
    void renderizarCollectibles(BackMap &backMap);
    void renderizarCharacter(Personagem* personagem);

    void renderizar(Vivo* colecao);
    void renderizar(Coletavel* colecao);

    ~Janela();


};

#endif