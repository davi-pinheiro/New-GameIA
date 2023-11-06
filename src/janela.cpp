#include <iostream>
#include "backMap.h"
#include "janela.h"
#include "vampiro.h"
#include "guerreiro.h"
#include "denteAlho.h"

using std::cout;
using std::endl;

Janela::Janela(int mapaAltura, int mapaLargura, int telaAltura, int telaLargura)
{    
    janela = SDL_CreateWindow("GameIA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, telaLargura, telaAltura, SDL_WINDOW_HIDDEN);

    renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

    textura = SDL_CreateTexture(renderizador, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, mapaLargura, mapaAltura);
}

int Janela::getAltura()
{
    return altura;
}

int Janela::getLargura()
{
    return largura;
}

SDL_Renderer* Janela::getRenderizador()
{
    return renderizador;
}

SDL_Window* Janela::getJanela()
{
    return janela;
}

SDL_Texture* Janela::getTextura()
{
    return textura;
}

BackMap* Janela::getMundo(void)
{
    return mundo;
}

void Janela::setMundo(BackMap* mundo)
{
    this->mundo = mundo;
}

void Janela::setAltura(int altura)
{
    this->altura = altura;
}

void Janela::setLargura(int largura)
{
    this->largura = largura;
}


void Janela::backgroundColor(Tempo& tempo)
{
    /*tempo.changeStateDay();
    switch (tempo.getEstadoDia())
    {
    case MORNING:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(195,195,195,195);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(225,225,225,225);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(255,255,255,255);
        }
            
        break;
    case AFTERNOON:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(255,255,255,255);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(225,225,225,225);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(195,195,195,195);
        }
        break;
    case EVENING:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(195,195,195,195);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(165,165,165,165);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(135,135,135,135);
        }
        break;
    case DAWN:
        if(tempo.getTempoNow() % tempo.getComparador() <= (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(135,135,135,135);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= 2 * (tempo.getComparador() / 3) - 1)
        {
            background.setRgba(165,165,165,165);
        }
        else if(tempo.getTempoNow() % tempo.getComparador() > 2 * (tempo.getComparador() / 3) - 1 && tempo.getTempoNow() % tempo.getComparador() <= tempo.getComparador() - 1)
        {
            background.setRgba(195,195,195,195);
        }
        break;
    
    default:
        break;
    }*/

    frontgroundColor(mundo->getBackground());
    SDL_RenderClear(renderizador);

    int color = 255 - mundo->getBackground().getR();
    Rgba newColor(color, color, color, 255);

    frontgroundColor(newColor);
    SDL_RenderDrawLine(renderizador, 0, 1079, 3240, 1079);
    SDL_RenderDrawLine(renderizador, 0, 2159, 3240, 2159);
    SDL_RenderDrawLine(renderizador, 1079, 0, 1079, 3240);
    SDL_RenderDrawLine(renderizador, 2159, 0, 2159, 3240);
}

void Janela::frontgroundColor(Rgba rgba)
{
    SDL_SetRenderDrawColor(renderizador, rgba.getR(), rgba.getG(), rgba.getB(), rgba.getA());
}

void Janela::renderizarCharacter(Personagem* personagem)
{
    frontgroundColor(personagem->getRgba());
    SDL_RenderFillRect(renderizador, personagem->getPersonagem());
    frontgroundColor(Rgba(0,0,0,0));
    SDL_RenderDrawRect(renderizador, personagem->getPersonagem());
}

void Janela::renderizarMonsters()
{
    cout << mundo->tamanhoVectorVivos() << endl;
    for(int i = 0; i < mundo->tamanhoVectorAreas(); i++)
    {
        cout << "Primeiro for" << endl;
        if(mundo->retornarAreas(i)->isAtivo())
        {
            cout << "Primeiro if" << endl;
            for(int j = 0; j < mundo->tamanhoVectorVivos(); j++)
            {
                cout << "Segundo for" << endl;
                if((mundo->retornarVivos(j)->getPersonagem()->x >= mundo->retornarAreas(i)->getX())&&
                (mundo->retornarVivos(j)->getPersonagem()->x <  mundo->retornarAreas(i)->getX() + mundo->retornarAreas(i)->getW()))
                {
                    cout << "Segundo if" << endl;
                    if((mundo->retornarVivos(j)->getPersonagem()->y >= mundo->retornarAreas(i)->getY())&&
                    (mundo->retornarVivos(j)->getPersonagem()->y <  mundo->retornarAreas(i)->getY() + mundo->retornarAreas(i)->getH()))
                    {
                        switch (mundo->retornarVivos(j)->getTipoMonstro())
                        {
                        case VAMPIRO:
                            ((Vampiro*)mundo->retornarVivos(j))->machine(*mundo);
                            break;
                        case GUERREIRO:
                            ((Guerreiro*)mundo->retornarVivos(j))->machine(*mundo);
                        
                        default:
                            break;
                        }
                        //((Vampiro*)mundo->retornarVivos(j))->machine();
                        renderizar(mundo->retornarVivos(j));
                    }
                }
            }
        }
    }
}
void Janela::renderizarCollectibles(BackMap &backMap)
{
    for(int i = 0; i < mundo->tamanhoVectorAreas(); i++)
    {
        if(mundo->retornarAreas(i)->isAtivo())
        {
            for(int j = 0; j < mundo->tamanhoVectorColetaveis(); j++)
            {
                if((mundo->retornarColetaveis(j)->getColetavel()->x >= mundo->retornarAreas(i)->getX())&&
                (mundo->retornarColetaveis(j)->getColetavel()->x <  mundo->retornarAreas(i)->getX() + mundo->retornarAreas(i)->getW()))
                {
                    if((mundo->retornarColetaveis(j)->getColetavel()->y >= mundo->retornarAreas(i)->getY())&&
                    (mundo->retornarColetaveis(j)->getColetavel()->y <  mundo->retornarAreas(i)->getY() + mundo->retornarAreas(i)->getH()))
                    {
                        renderizar(mundo->retornarColetaveis(j));
                    }
                }
            }
        }
    }
}

Janela::~Janela()
{
    SDL_DestroyTexture(textura);
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();
}

void Janela::renderizar(Vivo* vivo)
{
    frontgroundColor(vivo->getRgba());
    SDL_RenderFillRect(renderizador, vivo->getPersonagem());
}

void Janela::renderizar(Coletavel* coletavel)
{
    frontgroundColor(coletavel->getRgba());
    SDL_RenderFillRect(renderizador, coletavel->getColetavel());
}