#include <cstdlib>
#include "allyCollection.h"
#include "guerreiro.h"
#include <cmath>
#include <iostream>
#include <ctime>

using std::rand;
using std::srand;
using std::pow;

vector<Vivo*>& AllyCollection::getAllyCollection()
{
    return allyCollection;
}

void AllyCollection::generateAllies(int altura, int largura)
{
    int x = 0, y = 0;
    int distancia = 0;
    int quantidadeAliados = (int)round((largura * altura) / (40000 * 3));
    bool possible = false;
    srand(time(NULL));
    for (int i = 0; i < quantidadeAliados; i++)
    {
        do
        {
            x = rand() % (largura - 19);
            y = rand() % (altura - 19);
            for (int j = 0; j < (int)allyCollection.size(); j++)
            {
                distancia = sqrt(pow(allyCollection[j]->getPersonagem()->x - x, 2) + pow(allyCollection[j]->getPersonagem()->y - y, 2));
                if (distancia >= 30)
                {
                    if (j == (int)allyCollection.size() - 1)
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

        Guerreiro* cavaleiro = new Guerreiro(2, 50, 5, 3, false, 20, 20, x, y, VAGAR);
        allyCollection.push_back(cavaleiro);
        
        possible = true;
    }
}

void AllyCollection::setInimigos(vector<Vivo*> inimigos)
{
    for(int i = 0; i < (int)allyCollection.size(); i++)
    {
        allyCollection[i]->setInimigos(inimigos);
    }
}