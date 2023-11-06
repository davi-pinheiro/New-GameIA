#include "personagem.h"

Personagem::Personagem(int id, int vidaMaxima, int velocidade, int forca, int raioVisao, State estado, int h, int w, int x, int y, TipoMonstro tipoMonstro) : Vivo(id, vidaMaxima, velocidade, forca, raioVisao, estado, h, w, x, y, tipoMonstro)
{
    this->rgba = Rgba(255, 0, 0, 0);
}

void Personagem::controle(SDL_Event* evento, Camera& camera)
{
    if(evento->type == SDL_KEYDOWN)
    {
        switch(evento->key.keysym.sym)
        {
        case SDLK_w:
            if(getPersonagem()->y - camera.getCamera()->y == 200)
            {
                camera.getCamera()->y -=10;
                if(camera.getCamera()->y < 0)
                {
                    camera.getCamera()->y +=10;
                }
            }
            getPersonagem()->y -= 10;
            if(getPersonagem()->y < 0)
            {
                getPersonagem()->y = 0;
            }
            break;
        case SDLK_a:
            if(getPersonagem()->x - camera.getCamera()->x == 200)
            {
                camera.getCamera()->x -=10;
                if(camera.getCamera()->x < 0)
                {
                    camera.getCamera()->x +=10;
                }
            
            }
            getPersonagem()->x -= 10;
            if(getPersonagem()->x < 0)
            {
                getPersonagem()->x = 0;
            }
            break;
        case SDLK_s:
            if(camera.getCamera()->y + camera.getCamera()->h - getPersonagem()->y == 200)
            {
                camera.getCamera()->y += 10;
                if(camera.getCamera()->y + camera.getCamera()->h > 3240)
                {
                    camera.getCamera()->y -=10;
                }
            }
            getPersonagem()->y += 10;
            if(getPersonagem()->y > 3220)
            {
                getPersonagem()->y = 3220;
            }
            break;
        case SDLK_d:
            if(camera.getCamera()->x + camera.getCamera()->w - getPersonagem()->x == 200)
            {
                camera.getCamera()->x +=10;
                if(camera.getCamera()->x + camera.getCamera()->w >3240)
                {
                    camera.getCamera()->x -=10;
                }
            }
            getPersonagem()->x += 10;
            if(getPersonagem()->x > 3220)
            {
                getPersonagem()->x = 3220;
            }
            break;
        }
    }
}

void Personagem::machine(void)
{

}