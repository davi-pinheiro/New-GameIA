#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <vector>
#include "tipoMonstro.h"

using std::vector;

class Relationship{
    private:
        vector<TipoMonstro> inimigo;
        vector<TipoMonstro> agressivo;
        vector<TipoMonstro> neutro;
        vector<TipoMonstro> amigo;

    public:
        Relationship(vector<TipoMonstro> inimigo, vector<TipoMonstro> agressivo, vector<TipoMonstro> neutro, vector<TipoMonstro> amigo);

        TipoMonstro getInimigo(int indice);
        TipoMonstro getAgressivo(int indice);
        TipoMonstro getNeutro(int indice);
        TipoMonstro getAmigo(int indice);
};

#endif