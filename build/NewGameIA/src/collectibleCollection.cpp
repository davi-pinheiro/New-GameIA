#include "collectibleCollection.h"
#include <cstdlib>
#include "denteAlho.h"
#include <cmath>
#include <iostream>
#include <ctime>

CollectibleCollection::CollectibleCollection()
{
    collectibleCollection = new vector<Coletavel*>();
}

vector<Coletavel*>& CollectibleCollection::getCollectibleCollection()
{
    return *collectibleCollection;
}

void CollectibleCollection::generateCollectibles(int altura, int largura)
{
    int x = 0, y = 0;
    int distancia = 0;
    int quantidadeColetaveis = (int)round((largura * altura) / 40000);
    bool possible = false;
    srand(time(NULL));
    for (int i = 0; i < quantidadeColetaveis; i++)
    {
        do
        {
            x = rand() % (largura - 19);
            y = rand() % (altura - 19);
            for (int j = 0; j < (int) collectibleCollection->size(); j++)
            {
                distancia = sqrt(pow((*collectibleCollection)[j]->getColetavel()->x - x, 2) + pow((*collectibleCollection)[j]->getColetavel()->y - y, 2));
                if (distancia >= 30)
                {
                    if (j == (int)collectibleCollection->size() - 1)
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

        collectibleCollection->push_back(new DenteAlho(1, x, y, 10, 10));
        
        possible = true;
    }
}