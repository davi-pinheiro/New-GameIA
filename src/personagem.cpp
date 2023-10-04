#include "personagem.h"

Personagem::Personagem(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado) : Vivo(vidaMaxima, velocidade, forca, inimigo, h, w, x, y, rgba, estado)
{
    this->rgba = Rgba(255, 0, 0, 0);
}

void Personagem::machine(void)
{

}