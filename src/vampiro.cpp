#include "vampiro.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "state.h"

using std::sqrt;
using std::pow;
using std::rand;

Vampiro::Vampiro(int vidaMaxima, int velocidade, int forca, bool inimigo , int h, int w, int x, int y, State estado) : Vivo(vidaMaxima, velocidade, forca, inimigo, h, w, x, y, rgba, estado)
{
    this->rgba = Rgba(0, 0, 0, 0);
}

bool Vampiro::isNextToEnemy()
{
    int distancia;
    for(int i = 0; i < (int)inimigos.size(); i++)
    {
        distancia = round(sqrt(pow(getPersonagem()->x - inimigos[i]->getPersonagem()->x, 2) + pow(getPersonagem()->y - inimigos[i]->getPersonagem()->y, 2)));
        if(distancia < 135)
        {
            return true;
        }
    }
    return false;
}

//bool Vampiro::isAttackCondition()
//{
    
//}

void Vampiro::moveToPlayer()
{
    int minDistancia = 136, distancia, indice;
    for(int i = 0; i < (int)inimigos.size(); i++)
    {
        distancia = round(sqrt(pow(getPersonagem()->x - inimigos[i]->getPersonagem()->x, 2) + pow(getPersonagem()->y - inimigos[i]->getPersonagem()->y, 2)));
        if(distancia <= 135)
        {
            if(distancia < minDistancia)
            {
                minDistancia = distancia;
                indice = i;
            }
        }
    }

    if(getPersonagem()->x - inimigos[indice]->getPersonagem()->x > 0)
    {
        if(getPersonagem()->x - inimigos[indice]->getPersonagem()->x < 10)
        {
            getPersonagem()->x -= minDistancia;
        }
        else
        {
            getPersonagem()->x -= velocidade;
        }
    }
    else if(getPersonagem()->x - inimigos[indice]->getPersonagem()->x < 0)
    {
        if(getPersonagem()->x - inimigos[indice]->getPersonagem()->x > -10)
        {
            getPersonagem()->x += minDistancia;
        }
        else
        {
            getPersonagem()->x += velocidade;
        }
    }

    if(getPersonagem()->y - inimigos[indice]->getPersonagem()->y > 0)
    {
        if(getPersonagem()->y - inimigos[indice]->getPersonagem()->y < 10)
        {
            getPersonagem()->y -= minDistancia;
        }
        else
        {
            getPersonagem()->y -= velocidade;
        }
    }
    else if(getPersonagem()->y - inimigos[indice]->getPersonagem()->y < 0)
    {
        if(getPersonagem()->y - inimigos[indice]->getPersonagem()->y > -10)
        {
            getPersonagem()->y += minDistancia;
        }
        else
        {
            getPersonagem()->y += velocidade;
        }
    }
}

void Vampiro::machine()
{
    int escolha;
    escolha = rand() % 8;
    switch (estado)
    {
    case VAGAR:
        if(isNextToEnemy())
        {
            estado = ATACAR;
        }
        else
        {
            switch (escolha)
            {
            case 0:
                personagem.x += velocidade;
                break;
            case 1:
                personagem.x -= velocidade;
                break;
            case 2:
                personagem.y += velocidade;
                break;
            case 3:
                personagem.y -= velocidade;
                break;
            case 4:
                personagem.x += velocidade;
                personagem.y += velocidade;
                break;
            case 5:
                personagem.x -= velocidade;
                personagem.y += velocidade;
                break;
            case 6:
                personagem.x += velocidade;
                personagem.y -= velocidade;
                break;
            case 7:
                personagem.x -= velocidade;
                personagem.y -= velocidade;
                break;
            }
        }
        break;

    case ATACAR:
        if(isNextToEnemy())
        {
            moveToPlayer();
        }
        else
        {
            estado = VAGAR;
        }
        break;
    
    
    default:
        break;
    }
}