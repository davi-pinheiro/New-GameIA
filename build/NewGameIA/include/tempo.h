#ifndef TEMPO_H
#define TEMPO_H

#include <ctime>
#include "stateDay.h"

class Tempo
{
private:
    time_t tempoInicial;
    StateDay estadoDia;
    int comparador;
    bool passou;
    bool block;
public:
    Tempo(int comparador);

    time_t getTempoInicial();
    StateDay getEstadoDia();
    bool getPassou();
    int getComparador();

    void setEstadoDia(StateDay estadoDia);
    void setComparador(int comparador);

    int getTempoNow();
    void changeStateDay();

};

#endif