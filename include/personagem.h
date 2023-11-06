#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <SDL2/SDL.h>
#include "camera.h"
#include "vivo.h"
#include "state.h"

class Personagem : public Vivo
{
private:
    /* data */
public:
    Personagem(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro);

    void controle(SDL_Event* evento, Camera& camera);

    void machine(void);
};


#endif