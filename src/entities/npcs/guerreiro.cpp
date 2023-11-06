#include <iostream>
#include <cstdlib>
#include <cmath>
#include "guerreiro.h"
#include "state.h"

Guerreiro::Guerreiro(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro) : Vivo(id, vidaMaxima, velocidade, forca, raioVisao, estado, h, w, x, y, tipoMonstro)
{
    this->rgba = Rgba(0, 0, 255, 0);
}
void Guerreiro::machine(BackMap backMap)
{
    
}