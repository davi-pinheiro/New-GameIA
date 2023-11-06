#include <iostream>
#include <cstdlib>
#include <cmath>
#include "backMap.h"
#include "vampiro.h"
#include "state.h"

using std::sqrt;
using std::pow;
using std::rand;
using std::cout;
using std::endl;

Vampiro::Vampiro(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro) : Vivo(id, vidaMaxima, velocidade, forca, raioVisao, estado, h, w, x, y, tipoMonstro)
{
    this->rgba = Rgba(0, 0, 0, 0);
}

bool Vampiro::isNextToEnemy(BackMap& backMap)
{
    int distancia;
    for(int i = 0; i < backMap.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(personagem.x - backMap.retornarVivos(i)->getPersonagem()->x, 2) + pow(personagem.y - backMap.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia < velocidade + 21)
        {
            if((backMap.retornarVivos(i)->getTipoMonstro() == GUERREIRO) || 
            (backMap.retornarVivos(i)->getTipoMonstro() == PLAYER))
            {
                return true;
            }
        }
    }
    return false;
}

bool Vampiro::isAttackCondition(BackMap& backMap)
{
    int distancia;
    for(int i = 0; i < backMap.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(personagem.x - backMap.retornarVivos(i)->getPersonagem()->x, 2) + pow(personagem.y - backMap.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia < 21)
        {
            if((backMap.retornarVivos(i)->getTipoMonstro() == GUERREIRO) || 
            (backMap.retornarVivos(i)->getTipoMonstro() == PLAYER))
            {
                return true;
            }
        }
    }
    return false;
}

void Vampiro::moveToPlayer(BackMap& backMap)
{
    int minDistancia = 136, distancia, indice;
    for(int i = 0; i < backMap.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(personagem.x - backMap.retornarVivos(i)->getPersonagem()->x, 2) + pow(personagem.y - backMap.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia <= raioVisao)
        {
            if(distancia < minDistancia)
            {
                if((backMap.retornarVivos(i)->getTipoMonstro() == GUERREIRO) || 
                (backMap.retornarVivos(i)->getTipoMonstro() == PLAYER))
                {
                    minDistancia = distancia;
                    indice = i;
                }
            }
        }
    }

    if(personagem.x - backMap.retornarVivos(indice)->getPersonagem()->x > 0)
    {
        if(personagem.x - backMap.retornarVivos(indice)->getPersonagem()->x < 21)
        {
            personagem.x += 21 - (personagem.x - backMap.retornarVivos(indice)->getPersonagem()->x);
        }
        else
        {
            personagem.x -= velocidade;
        }
    }
    else if(personagem.x - backMap.retornarVivos(indice)->getPersonagem()->x < 0)
    {
        if(personagem.x - backMap.retornarVivos(indice)->getPersonagem()->x > -21)
        {
            personagem.x -= -21 - (personagem.x - backMap.retornarVivos(indice)->getPersonagem()->x);
        }
        else
        {
            personagem.x += velocidade;
        }
    }

    if(personagem.y - backMap.retornarVivos(indice)->getPersonagem()->y > 0)
    {
        if(personagem.y - backMap.retornarVivos(indice)->getPersonagem()->y < 21)
        {
            personagem.y += 21 - (personagem.y - backMap.retornarVivos(indice)->getPersonagem()->y);
        }
        else
        {
            personagem.y -= velocidade;
        }
    }
    else if(personagem.y - backMap.retornarVivos(indice)->getPersonagem()->y < 0)
    {
        if(personagem.y - backMap.retornarVivos(indice)->getPersonagem()->y > -21)
        {
            personagem.y -= -21 - (personagem.y - backMap.retornarVivos(indice)->getPersonagem()->y);
        }
        else
        {
            personagem.y += velocidade;
        }
    }
}

void Vampiro::attack(BackMap& backMap)
{
    int distancia, indice;
    for(int i = 0; i < backMap.tamanhoVectorVivos(); i++)
    {
        distancia = round(sqrt(pow(personagem.x - backMap.retornarVivos(i)->getPersonagem()->x, 2) + pow(personagem.y - backMap.retornarVivos(i)->getPersonagem()->y, 2)));
        if(distancia <= 21)
        {
            if((backMap.retornarVivos(i)->getTipoMonstro() == GUERREIRO) || 
            (backMap.retornarVivos(i)->getTipoMonstro() == PLAYER))
            {
                indice = i;
            }
        }
    }

    backMap.retornarVivos(indice)->setVida(backMap.retornarVivos(indice)->getVida() - forca);

    if(backMap.retornarVivos(indice)->getVida() <= 0)
    {
        delete backMap.retornarVivos(indice);
        backMap.deleteVivo(indice);
    }
}

void Vampiro::machine(BackMap& backMap)
{
    int escolha;
    escolha = rand() % 8;
    switch (estado)
    {
    case VAGAR:
        if(isNextToEnemy(backMap))
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
        if(isNextToEnemy(backMap))
        {
            if(isAttackCondition(backMap))
            {
                attack(backMap);
            }
            else
            {
                moveToPlayer(backMap);
            }
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