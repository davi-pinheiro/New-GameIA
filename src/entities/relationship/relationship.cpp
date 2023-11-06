#include "relationship.h"

Relationship::Relationship(vector<TipoMonstro> inimigo, vector<TipoMonstro> agressivo, vector<TipoMonstro> neutro, vector<TipoMonstro> amigo)
{
    this->inimigo = inimigo;
    this->agressivo = agressivo;
    this->neutro = neutro;
    this->amigo = amigo;
}

TipoMonstro Relationship::getInimigo(int indice)
{
    return inimigo[indice];
}
TipoMonstro Relationship::getAgressivo(int indice)
{
    return agressivo[indice];
}
TipoMonstro Relationship::getNeutro(int indice)
{
    return neutro[indice];
}
TipoMonstro Relationship::getAmigo(int indice)
{
    return amigo[indice];
}