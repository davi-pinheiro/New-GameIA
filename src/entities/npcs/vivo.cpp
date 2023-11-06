#include "vivo.h"

Vivo::Vivo(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro){
    this->id = id;
    this->vidaMaxima = vidaMaxima;
    this->vida = vidaMaxima;
    this->velocidade = velocidade;
    this->forca = forca;
    this->raioVisao = raioVisao;
    this->estado = estado;

    personagem.h = h;
    personagem.w = w;
    personagem.x = x;
    personagem.y = y;

    this->tipoMonstro = tipoMonstro;
}



int Vivo::getId(void)
{
    return id;
}

int Vivo::getVidaMaxima(void){
    return vidaMaxima;
}

int Vivo::getVida(void){
    return vida;
}

int Vivo::getVelocidade(void){
    return velocidade;
}

int Vivo::getForca(void){
    return forca;
}

int Vivo::getRaioVisao(void)
{
    return raioVisao;
}

Rgba Vivo::getRgba(void)
{
    return rgba;
}

State Vivo::getEstado(void)
{
    return estado;
}

SDL_Rect* Vivo::getPersonagem(void)
{
    return &personagem;
}

TipoMonstro Vivo::getTipoMonstro(void)
{
    return tipoMonstro;
}



void Vivo::setVidaMaxima(int vidaMaxima){
    vida = (int) (vida * vidaMaxima) / this->vidaMaxima;
    this->vidaMaxima = vidaMaxima;
}

void Vivo::setVida(int vida){
    this->vida = vida;
}

void Vivo::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

void Vivo::setForca(int forca){
    this->forca = forca;
}

void Vivo::setRaioVisao(int raioVisao)
{
    this->raioVisao = raioVisao;
}

void Vivo::setEstado(State estado)
{
    this->estado = estado;
}

void Vivo::setTipoMonstro(TipoMonstro tipoMonstro)
{
    this->tipoMonstro = tipoMonstro;
}