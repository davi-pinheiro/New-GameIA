#include "vivo.h"

Vivo::Vivo(int id, int vidaMaxima, int velocidade, int forca, bool isEnemy , int h, int w, int x, int y, Rgba rgba, State estado){
    this->id = id;
    this->vidaMaxima = vidaMaxima;
    this->vida = vidaMaxima;
    this->velocidade = velocidade;
    this->forca = forca;
    this->isEnemy = isEnemy;
    this->estado = estado;

    personagem.h = h;
    personagem.w = w;
    personagem.x = x;
    personagem.y = y;

    this->rgba = rgba;
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

bool Vivo::getIsEnemy(void){
    return isEnemy;
}

vector<Vivo*> Vivo::getInimigos(void)
{
    return inimigos;
}

State Vivo::getEstado()
{
    return estado;
}

void Vivo::setId(int id)
{
    this->id = id;
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

void Vivo::setIsEnemy(bool isEnemy)
{
    this->isEnemy = isEnemy;
}

void Vivo::setInimigos(vector<Vivo*> inimigos)
{
    this->inimigos = inimigos;
}

void Vivo::setEstado(State estado)
{
    this->estado = estado;
}


SDL_Rect* Vivo::getPersonagem(void)
{
    return &personagem;
}

Rgba Vivo::getRgba(void)
{
    return rgba;
}

void Vivo::machine(void)
{
    
}

