#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "tipoMonstro.h"
#include "backMap.h"
#include "denteAlho.h"
#include "subArea.h"
#include "vampiro.h"
#include "guerreiro.h"

using std::rand;
using std::cout;
using std::endl;

BackMap::BackMap(void)
{
    ativo = true;
    proximoMundo = ANY_WORLD;
    background.setRgba(255,255,255,255);
}

Area* BackMap::retornarAreas(int indice)
{
    return areas[indice];
}
Vivo* BackMap::retornarVivos(int indice)
{
    return vivos[indice];
}
Coletavel* BackMap::retornarColetaveis(int indice)
{
    return coletaveis[indice];
}

int BackMap::tamanhoVectorAreas(void)
{
    return (int) areas.size();
}
int BackMap::tamanhoVectorVivos(void)
{
    return (int) vivos.size();
}
int BackMap::tamanhoVectorColetaveis(void)
{
    return (int) coletaveis.size();
}

void BackMap::generateAreas(int tamanhoMapa, int proporcaoArea)
{
    this->tamanhoMapa = tamanhoMapa;
    int tamanhoArea = tamanhoMapa / proporcaoArea;
    int tamanhoSubArea = 30;
    int numeroSubAreas = tamanhoArea / 30;

    for(int i = 0; i < proporcaoArea; i++)
    {
        for (int j = 0; j < proporcaoArea; j++)
        {
            Area* area = new Area(tamanhoArea * j, tamanhoArea * i, tamanhoArea, tamanhoArea, false);
            for(int k = 0; k < numeroSubAreas; k++)
            {
                for (int l = 0; l < numeroSubAreas; l++)
                {
                    SubArea* subArea = new SubArea(tamanhoSubArea * l, tamanhoSubArea * k, 30, 30, 50, 25);
                    area->adicionarSubArea(subArea);
                }
            }
            areas.push_back(area);
        }
    }
}
void BackMap::generateEntities()
{
    int porcentagemColetaveis = (pow(tamanhoMapa, 2) / pow(10, 2)) * 1 / 200;
    int porcentagemInimigos = (pow(tamanhoMapa, 2) / pow(20, 2)) * 1 / 200;
    int porcentagemAliados = (pow(tamanhoMapa, 2) / pow(20, 2)) * 1 / 400;
    
    int x, y, id;
    int distancia = 0;
    bool possible = false;

    srand(time(NULL));
    for(int i = 0; i < porcentagemColetaveis; i++)
    {
        do
        {
            x = rand() % (tamanhoMapa - 9);
            y = rand() % (tamanhoMapa - 9);
            for (int j = 0; j < (int) coletaveis.size(); j++)
            {
                distancia = sqrt(pow(coletaveis[j]->getColetavel()->x - x, 2) + pow(coletaveis[j]->getColetavel()->y - y, 2));
                if (distancia >= 15)
                {
                    if (j == (int)coletaveis.size() - 1)
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

        coletaveis.push_back(new DenteAlho(1, x, y, 10, 10));
        
        possible = true;
    }
    possible = false;
    for (int i = 0; i < porcentagemInimigos; i++)
    {
        do
        {
            x = rand() % (tamanhoMapa - 19);
            y = rand() % (tamanhoMapa - 19);
            for (int j = 0; j < (int)vivos.size(); j++)
            {
                distancia = sqrt(pow(vivos[j]->getPersonagem()->x - x, 2) + pow(vivos[j]->getPersonagem()->y - y, 2));
                if (distancia >= 30)
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

        Vampiro* dracula = new Vampiro(id, 50, 5, 3, 135, VAGAR, 20, 20, x, y, VAMPIRO);
        vivos.push_back(dracula);
        
        possible = true;
    }
    possible = false;
    for (int i = 0; i < porcentagemAliados; i++)
    {
        do
        {
            x = rand() % (tamanhoMapa - 19);
            y = rand() % (tamanhoMapa - 19);
            for (int j = 0; j < (int)vivos.size(); j++)
            {
                distancia = sqrt(pow(vivos[j]->getPersonagem()->x - x, 2) + pow(vivos[j]->getPersonagem()->y - y, 2));
                if (distancia >= 30)
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

        Guerreiro* cavaleiro = new Guerreiro(id, 50, 5, 3, 67, VAGAR, 20, 20, x, y, GUERREIRO);
        vivos.push_back(cavaleiro);
        
        possible = true;
    }
}
void BackMap::updateAreas(Camera &camera)
{
    for(int i = 0; i < (int)areas.size(); i++)
    {
        if((camera.getXCamera() >= areas[i]->getX()) &&
        (camera.getXCamera() < areas[i]->getX() + areas[i]->getW()))
        {
            if((camera.getYCamera() >= areas[i]->getY()) &&
            (camera.getYCamera() < areas[i]->getY() + areas[i]->getH()))
            {
                areas[i]->setAtivo(true);
            }
            else if((camera.getYCamera() + camera.getHeightCamera() >= areas[i]->getY()) &&
            (camera.getYCamera() + camera.getHeightCamera() < areas[i]->getY() + areas[i]->getH()))
            {
                areas[i]->setAtivo(true);
            }
            else
            {
                areas[i]->setAtivo(false);
            }
        }
        else if((camera.getXCamera() + camera.getWidthCamera() >= areas[i]->getX()) &&
        (camera.getXCamera() + camera.getWidthCamera() < areas[i]->getX() + areas[i]->getW()))
        {
            if((camera.getYCamera() >= areas[i]->getY()) &&
            (camera.getYCamera() < areas[i]->getY() + areas[i]->getH()))
            {
                areas[i]->setAtivo(true);
            }
            else if((camera.getYCamera() + camera.getHeightCamera() >= areas[i]->getY()) &&
            (camera.getYCamera() + camera.getHeightCamera() < areas[i]->getY() + areas[i]->getH()))
            {
                areas[i]->setAtivo(true);
            }
            else
            {
                areas[i]->setAtivo(false);
            }
        }
        else
        {
            areas[i]->setAtivo(false);
        }
    }
}
void BackMap::deleteVivo(int indice)
{
    vivos.erase(vivos.begin() + indice);
}

bool BackMap::isAtivo()
{
    return ativo;
}

TipoMundo BackMap::getTipoMundo(void)
{
    return tipoMundo;
}

TipoMundo BackMap::getProximoMundo(void)
{
    return proximoMundo;
}

Rgba BackMap::getBackground()
{
    return background;
}

void BackMap::setAtivo(bool ativo)
{
    this->ativo = ativo;
}

void BackMap::setProximoMundo(TipoMundo tipoMundo)
{
    proximoMundo = tipoMundo;
}

