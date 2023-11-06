#ifndef EFEITO_H
#define EFEITO_H

#include <ctime>
#include <string>
#include "tipoEfeito.h"

using std::string;

class Efeito
{
protected:
    time_t inicioEfeito;
    int duracaoEfeito;
    TipoEfeito tipoEfeito;
    string descricaoEfeito;
    string nomeEfeito;

public:
    Efeito(int duracaoEfeito);

    time_t getInicioEfeito(void);
    int getDuracaoEfeito(void);
    TipoEfeito getTipoEfeito(void);
    string getDescricaoEfeito(void);
    string getNomeEfeito(void);

    void setDuracaoEfeito(int de);
};

#endif
