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

using std::vector;

class Janela
{
private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    SDL_Texture* textura;
    Rgba background;
    int altura;
    int largura;

public:
    Janela(int mapaAltura, int mapaLargura, int telaAltura, int telaLargura);

    int getAltura();
    int getLargura();
    SDL_Renderer* getRenderizador();
    SDL_Window* getJanela();
    SDL_Texture* getTextura();

    void setAltura(int altura);
    void setLargura(int largura);

    void backgroundColor(Tempo& tempo);
    void frontgroundColor(Rgba rgba);

    void renderizarMonsters(vector<Vivo*>& colecao, Camera& camera);
    void renderizarAllies(vector<Vivo*>& colecao, Camera& camera);
    void renderizarCollectibles(vector<Coletavel*>& colecao, Camera& camera);

    void renderizarCharacter(Personagem* personagem);

    void renderizar(Vivo* colecao);
    void renderizar(Coletavel* colecao);

    ~Janela();


};

#endif