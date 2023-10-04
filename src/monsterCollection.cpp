#include <cstdlib>
#include "monsterCollection.h"
#include "vampiro.h"
#include <cmath>
#include <iostream>
#include <ctime>

using std::rand;
using std::srand;
using std::pow;

vector<Vivo*>& MonsterCollection::getMonsterCollection()
{
    return monsterCollection;
}

void MonsterCollection::generateMonsters(int altura, int largura)
{
    int x = 0, y = 0;
    int distancia = 0;
    int quantidadeInimigos = (int)round((largura * altura) / 40000);
    bool possible = false;
    srand(time(NULL));
    for (int i = 0; i < quantidadeInimigos; i++)
    {
        do
        {
            x = rand() % (largura - 19);
            y = rand() % (altura - 19);
            for (int j = 0; j < (int)monsterCollection.size(); j++)
            {
                distancia = sqrt(pow(monsterCollection[j]->getPersonagem()->x - x, 2) + pow(monsterCollection[j]->getPersonagem()->y - y, 2));
                if (distancia >= 30)
                {
                    if (j == (int)monsterCollection.size() - 1)
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

        Vampiro* dracula = new Vampiro(50, 5, 3, true, 20, 20, x, y, VAGAR);
        monsterCollection.push_back(dracula);
        
        possible = true;
    }
}

void MonsterCollection::setInimigos(vector<Vivo*> inimigos)
{
    for(int i = 0; i < (int)monsterCollection.size(); i++)
    {
        monsterCollection[i]->setInimigos(inimigos);
    }
}