#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "vivo.h"
#include "state.h"

class Personagem : public Vivo
{
private:
    /* data */
public:
    Personagem(int id, int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado);

    void machine(void);
};


#endif