#include "efeito.h"

Efeito::Efeito(int duracaoEfeito)
{
    this->duracaoEfeito = duracaoEfeito;
}

time_t Efeito::getInicioEfeito(void)
{
    return inicioEfeito; 
}
int Efeito::getDuracaoEfeito(void)
{
    return duracaoEfeito; 
}
TipoEfeito Efeito::getTipoEfeito(void)
{
    return tipoEfeito; 
}
string Efeito::getDescricaoEfeito(void)
{
    return descricaoEfeito; 
}
string Efeito::getNomeEfeito(void)
{
    return nomeEfeito; 
}

void Efeito::setDuracaoEfeito(int de)
{
    duracaoEfeito = de;
}