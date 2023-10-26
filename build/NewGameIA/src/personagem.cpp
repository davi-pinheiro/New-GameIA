#include "personagem.h"

Personagem::Personagem(int id, int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado) : Vivo(id, vidaMaxima, velocidade, forca, inimigo, h, w, x, y, rgba, estado)
{
    this->rgba = Rgba(255, 0, 0, 0);
}

void Personagem::machine(void)
{

}