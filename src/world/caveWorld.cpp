#include <cstdlib>
#include <vector>
#include <iostream>
#include "caveWorld.h"
#include "pathfinder.h"
#include "aranha.h"

using std::rand;
using std::cout;
using std::endl;
using std::vector;

CaveWorld::CaveWorld(int tamanhoMapa, int proporcaoMapa, Camera& camera, Personagem* personagem)
{
    vivos.push_back(personagem);
    ativo = false;
    tipoMundo = CAVE;
    background.setRgba(33,33,33,255);

    cout << retornarVivos(0)->getTipoMonstro() << endl;
    
    
    generateAreas(tamanhoMapa, proporcaoMapa);

    for(int i = 0; i < tamanhoVectorAreas(); i++)
    {
        for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
        {
            areas[i]->retornarSubArea(j)->setBarreira(true);
        }
    }

    generateLabyrinth();
    updateAreas(camera);
    generateEntities();
}

void CaveWorld::generateLabyrinth(void)
{
    srand(time(NULL));
    int numero = rand() % 1296;

    int xi, xf, yi, yf, aux;
    for (int i = 0; i < 100; i++)
    {
        xi = rand() % tamanhoMapa;
        yi = rand() % tamanhoMapa;
        xf = rand() % tamanhoMapa;
        yf = rand() % tamanhoMapa;

        if(xi > xf)
        {
            aux = xi;
            xi = xf;
            xf = aux;
        }
        if(yi > yf)
        {
            aux = yi;
            yi = yf;
            yf = aux;
        }

        while (xi < xf)
        {
            retornarSubArea(xi, yi)->setBarreira(false);
            xi += 30;
        }
        while (yi < yf)
        {
            retornarSubArea(xi, yi)->setBarreira(false);
            yi += 30;

        }
    }

    for(int i = 0; i < (int) areas.size(); i++)
    {
        switch(i)
        {
            case 0:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j >= 0 && j < 36)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
                else if(j % 36 == 0)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
            case 1:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j >= 0 && j < 36)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
            case 2:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j >= 0 && j < 36)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
                else if(j % 36 == 35)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
            case 3:
            //int numero = rand() % 1296;
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j % 36 == 0)
                {
                    if(j == numero)
                    {
                        areas[i]->retornarSubArea(j)->setBarreira(false);
                    }
                    else
                    {
                        areas[i]->retornarSubArea(j)->setBarreira(true);
                    }
                    
                }
            }
            break;
            case 5:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j % 36 == 35)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
            case 6:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j >= 1260 && j < 1296)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
                else if(j % 36 == 0)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
            case 7:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j >= 1260 && j < 1296)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
            case 8:
            for(int j = 0; j < areas[i]->tamanhoSubAreas(); j++)
            {
                if(j >= 1260 && j < 1296)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
                else if(j % 36 == 35)
                {
                    areas[i]->retornarSubArea(j)->setBarreira(true);
                }
            }
            break;
        }
    }

    
}

void CaveWorld::generateEntities()
{
    int porcentagemInimigos = (pow(tamanhoMapa, 2) / pow(20, 2)) * 1 / 200;
    
    int x, y, id;
    int distancia = 0, distanciaB = 0;
    bool possible = false;

    srand(time(NULL));
    for (int i = 0; i < porcentagemInimigos; i++)
    {
        do
        {
            x = rand() % (tamanhoMapa - 9);
            y = rand() % (tamanhoMapa - 9);
            for (int j = 0; j < (int)vivos.size(); j++)
            {

                distancia = sqrt(pow(vivos[j]->getPersonagem()->x - x, 2) + pow(vivos[j]->getPersonagem()->y - y, 2));
                distanciaB = sqrt(pow(vivos[j]->getPersonagem()->x - retornarSubArea(x, y)->getX(), 2) + pow(vivos[j]->getPersonagem()->y - retornarSubArea(x, y)->getY(), 2));
                if (distancia >= 30 && distanciaB > 30)
                {
                    if (j == (int)vivos.size() - 1)
                    {
                        possible = false;
                    }
                }
                else
                {
                    break;
                }
            }
        }while (possible);

        do{
            id = rand() % 2000;
            for(int i = 0; i < (int)vivos.size(); i++)
            {
                if(id == vivos[i]->getId())
                {
                    break;
                }
                else
                {
                    if(i == (int)vivos.size() - 1)
                    {
                        possible = false;
                    }
                }
            }

        }while(possible);

        Aranha* spider = new Aranha(id, 10, 10, 2, 30, VAGAR, 10, 10, x, y, ARANHA, *this);
        vivos.push_back(spider);
        
        possible = true;
    }
    possible = false;
}

/*void CaveWorld::generateLabyrinth(void)
{
    
    Pathfinder pf;
    vector<SDL_Rect> pontos;
    for(int i = 0; i < 2; i++)
    {
        int x = rand() % 3240;
        int y = rand() % 3240;

        SDL_Rect ponto;
        ponto.x = x;
        ponto.y = y;
        ponto.w = 0;
        ponto.h = 0;

        pontos.push_back(ponto);
        
        if(pontos. size() % 2 == 0)
        {
            //cout << "Entrei" << endl;
            pf.createPathFinder(pontos[i - 1], pontos[i], *this);
            cout << "Entrei" << endl;
            for(int i = 0; i < (int)pf.getCaminho().size(); i++)
            {
                cout << "Finalmente Entrei" << endl;
                SDL_Delay(1000);
                //cout << pf.getCaminho().size() << endl;
                retornarSubArea(pf.getCaminho().top().getX(), pf.getCaminho().top().getY())->setBarreira(false);
                //pf.getCaminho().top();
                pf.getCaminho().pop();
            }
            
        }
    }
    
}*/