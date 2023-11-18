#include <cmath>
#include <iostream>
#include "pathfinder.h"

using std::cout;
using std::endl;

void Pathfinder::createPathFinder(SDL_Rect& npcOrigem, SDL_Rect& npcDestino, BackMap mapa)
{
    NoPathfinder inicio(mapa.retornarSubArea(npcOrigem.x, npcOrigem.y));
    NoPathfinder fim(mapa.retornarSubArea(npcDestino.x, npcDestino.y));
    NoPathfinder* ponteiro = &inicio;

    inicio.calcular_custo_relativo(fim);
    inicio.setCustoReal(0);

    cout << inicio.getCustoReal() << " " << inicio.getCustoRelativo() << endl;

    abertos.push_back(inicio);

    while(ponteiro != &fim)
    {
        //SDL_Delay(500);
        calcular_f(ponteiro);
        cout << ponteiro->getX() << " " << ponteiro->getY() << endl;
        if(ponteiro->getX() != fim.getX() || ponteiro->getY() != fim.getY())
        {
            close_node(ponteiro);
            create_nodes(ponteiro, fim, mapa);
        }
        else
        {
            cout << "Entrou no else" << endl;
            while(ponteiro->getNoPai() != NULL)
            {
                SDL_Delay(500);
                cout << "Entrou no segundo while" << endl;
                caminho.push(*ponteiro);
                cout << caminho.size() << endl;
                ponteiro = ponteiro->getNoPai();
            }
            ponteiro = &fim;
            break;
        }
    }
}

void Pathfinder::calcular_f(NoPathfinder* ponteiro)
{
    int f = abertos[0].getCustoRelativo() + abertos[0].getCustoReal();
    *ponteiro = abertos[0];
    cout << "!" << abertos[0].getCustoRelativo() + abertos[0].getCustoReal() << "!" << endl;
    for(int i = 1; i < (int)abertos.size(); i++)
    {
        cout << "!" << abertos[i].getCustoRelativo() + abertos[i].getCustoReal() << "!" << endl;
        if(f > abertos[i].getCustoRelativo() + abertos[i].getCustoReal())
        {
            *ponteiro = abertos[i];
            f = abertos[i].getCustoRelativo() + abertos[i].getCustoReal();
        }
    }
}

void Pathfinder::create_nodes(NoPathfinder* ponteiro, NoPathfinder destino, BackMap mapa)
{
    bool ok1 = true, ok2 = true;
    if((mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY()) != NULL) && !(mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->isBarreira()))
    {
        for(int i = 0; i < (int)fechados.size(); i++)
        {
            if((fechados[i].getX() != mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->getX()) ||
            (fechados[i].getY() != mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->getY()))
            {
                if(i == (int)fechados.size() - 1)
                {
                    ok1 = true;
                }
            }
            else
            {
                ok1 = false;
                break;
            }
        }
        if(ok1)
        {
            for(int i = 0; i < (int)abertos.size(); i++)
            {
                if((abertos[i].getX() != mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->getX()) ||
                (abertos[i].getY() != mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->getY()))
                {
                    if(i == (int)abertos.size() - 1)
                    {
                        ok2 = true;
                    }
                }
                else
                {
                    ok2 = false;
                    break;
                }
            }
        }
        if(ok1 && ok2)
        {
            NoPathfinder esquerda(mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY()));
            esquerda.calcular_custo_relativo(destino);
            esquerda.setCustoReal(ponteiro->getCustoReal() + 1);
            esquerda.addNoPai(*ponteiro);
            abertos.push_back(esquerda);
        }
        //cout << esquerda.getCustoReal() << endl;
    }
    if((mapa.retornarSubArea(ponteiro->getX() + 30, ponteiro->getY()) != NULL) && !(mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->isBarreira()))
    {
        for(int i = 0; i < (int)fechados.size(); i++)
        {
            if((fechados[i].getX() != mapa.retornarSubArea(ponteiro->getX() + 30, ponteiro->getY())->getX()) ||
            (fechados[i].getY() != mapa.retornarSubArea(ponteiro->getX() + 30, ponteiro->getY())->getY()))
            {
                if(i == (int)fechados.size() - 1)
                {
                    ok1 = true;
                }
            }
            else
            {
                ok1 = false;
                break;
            }
        }
        if(ok1)
        {
            for(int i = 0; i < (int)abertos.size(); i++)
            {
                if((abertos[i].getX() != mapa.retornarSubArea(ponteiro->getX() + 30, ponteiro->getY())->getX()) ||
                (abertos[i].getY() != mapa.retornarSubArea(ponteiro->getX() + 30, ponteiro->getY())->getY()))
                {
                    if(i == (int)abertos.size() - 1)
                    {
                        ok2 = true;
                    }
                }
                else
                {
                    ok2 = false;
                    break;
                }
            }
        }
        if(ok1 && ok2)
        {
            NoPathfinder direita(mapa.retornarSubArea(ponteiro->getX() + 30, ponteiro->getY()));
            direita.calcular_custo_relativo(destino);
            direita.setCustoReal(ponteiro->getCustoReal() + 1);
            direita.addNoPai(*ponteiro);
            abertos.push_back(direita);
        }
        //cout << direita.getCustoReal() << endl;
    }
    if((mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() - 30) != NULL) && !(mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->isBarreira()))
    {
        for(int i = 0; i < (int)fechados.size(); i++)
        {
            if((fechados[i].getX() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() - 30)->getX()) ||
            (fechados[i].getY() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() - 30)->getY()))
            {
                if(i == (int)fechados.size() - 1)
                {
                    ok1 = true;
                }
            }
            else
            {
                ok1 = false;
                break;
            }
        }
        if(ok1)
        {
            for(int i = 0; i < (int)abertos.size(); i++)
            {
                if((abertos[i].getX() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() - 30)->getX()) ||
                (abertos[i].getY() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() - 30)->getY()))
                {
                    if(i == (int)abertos.size() - 1)
                    {
                        ok2 = true;
                    }
                }
                else
                {
                    ok2 = false;
                    break;
                }
            }
        }
        if(ok1 && ok2)
        {
            NoPathfinder cima(mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() - 30));
            cima.calcular_custo_relativo(destino);
            cima.setCustoReal(ponteiro->getCustoReal() + 1);
            cima.addNoPai(*ponteiro);
            abertos.push_back(cima);
        }
        //cout << cima.getCustoReal() << endl;
    }
    if((mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() + 30) != NULL) && !(mapa.retornarSubArea(ponteiro->getX() - 30, ponteiro->getY())->isBarreira()))
    {
        for(int i = 0; i < (int)fechados.size(); i++)
        {
            if((fechados[i].getX() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() + 30)->getX()) ||
            (fechados[i].getY() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() + 30)->getY()))
            {
                if(i == (int)fechados.size() - 1)
                {
                    ok1 = true;
                }
            }
            else
            {
                ok1 = false;
                break;
            }
        }
        if(ok1)
        {
            for(int i = 0; i < (int)abertos.size(); i++)
            {
                if((abertos[i].getX() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() + 30)->getX()) ||
                (abertos[i].getY() != mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() + 30)->getY()))
                {
                    if(i == (int)abertos.size() - 1)
                    {
                        ok2 = true;
                    }
                }
                else
                {
                    ok2 = false;
                    break;
                }
            }
        }
        if(ok1 && ok2)
        {
            NoPathfinder baixo(mapa.retornarSubArea(ponteiro->getX(), ponteiro->getY() + 30));
            baixo.calcular_custo_relativo(destino);
            baixo.setCustoReal(ponteiro->getCustoReal() + 1);
            baixo.addNoPai(*ponteiro);
            abertos.push_back(baixo);
        }
        //cout << baixo.getCustoReal() << endl;
    }
}

void Pathfinder::close_node(NoPathfinder* ponteiro)
{
    
    fechados.push_back(*ponteiro);
    //cout << fechados.size() << endl;
    cout << "--------------------------------------------------" << endl;

    for(int i = 0; i < (int)abertos.size(); i++)
    {
        cout << abertos[i].getX() << " " << abertos[i].getY() << endl;
    }

    cout << "##################################################" << endl;

    for(int i = 0; i < (int)abertos.size(); i++)
    {
        if(ponteiro->getX() == abertos[i].getX() && ponteiro->getY() == abertos[i].getY())
        {
            abertos.erase(abertos.begin() + i);
            i = abertos.size();
        }
    }

    for(int i = 0; i < (int)abertos.size(); i++)
    {
        cout << abertos[i].getX() << " " << abertos[i].getY() << endl;
    }

    cout << "--------------------------------------------------" << endl;
    
}

stack<NoPathfinder> Pathfinder::getCaminho()
{
    return caminho;
}