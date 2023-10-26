#include "tempo.h"
#include <iostream>

Tempo::Tempo(int comparador)
{
    tempoInicial = time(NULL);
    estadoDia = MORNING;
    passou = true;
    this->comparador = comparador;
}


time_t Tempo::getTempoInicial()
{
    return tempoInicial;
}

StateDay Tempo::getEstadoDia()
{
    return estadoDia;
}

bool Tempo::getPassou()
{
    return passou;
}

int Tempo::getComparador()
{
    return comparador;
}


void Tempo::setEstadoDia(StateDay estadoDia)
{
    this->estadoDia = estadoDia;
}

void Tempo::setComparador(int comparador)
{
    this->comparador = comparador;
}


int Tempo::getTempoNow()
{
    time_t tempoAgora = time(NULL);
    return (int)difftime(tempoAgora, tempoInicial);
}

void Tempo::changeStateDay()
{
    if((getTempoNow() % comparador == 0))
    {
        if(passou == false)
        {
            passou = true;
            switch (estadoDia)
            {
            case MORNING:
                estadoDia = AFTERNOON;
                break;
            case AFTERNOON:
                estadoDia = EVENING;
                break;
            case EVENING:
                estadoDia = DAWN;
                break;
            case DAWN:
                estadoDia = MORNING;
                break;
            
            default:
                break;
            }
        }
    }
    else
    {
        passou = false;
    }
}
