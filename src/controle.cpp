#include <cmath>
#include "controle.h"

void controle(Personagem* player, SDL_Event* evento, Camera& camera)
{
    if(evento->type == SDL_KEYDOWN)
    {
        switch(evento->key.keysym.sym)
        {
        case SDLK_w:
            if(player->getPersonagem()->y - camera.getCamera()->y == 200)
            {
                camera.getCamera()->y -=10;
                if(camera.getCamera()->y < 0)
                {
                    camera.getCamera()->y +=10;
                }
            }
            player->getPersonagem()->y -= 10;
            if(player->getPersonagem()->y < 0)
            {
                player->getPersonagem()->y = 0;
            }
            break;
        case SDLK_a:
            if(player->getPersonagem()->x - camera.getCamera()->x == 200)
            {
                camera.getCamera()->x -=10;
                if(camera.getCamera()->x < 0)
                {
                    camera.getCamera()->x +=10;
                }
            
            }
            player->getPersonagem()->x -= 10;
            if(player->getPersonagem()->x < 0)
            {
                player->getPersonagem()->x = 0;
            }
            break;
        case SDLK_s:
            if(camera.getCamera()->y + camera.getCamera()->h - player->getPersonagem()->y == 200)
            {
                camera.getCamera()->y += 10;
                if(camera.getCamera()->y + camera.getCamera()->h > 3240)
                {
                    camera.getCamera()->y -=10;
                }
            }
            player->getPersonagem()->y += 10;
            if(player->getPersonagem()->y > 3220)
            {
                player->getPersonagem()->y = 3220;
            }
            break;
        case SDLK_d:
            if(camera.getCamera()->x + camera.getCamera()->w - player->getPersonagem()->x == 200)
            {
                camera.getCamera()->x +=10;
                if(camera.getCamera()->x + camera.getCamera()->w >3240)
                {
                    camera.getCamera()->x -=10;
                }
            }
            player->getPersonagem()->x += 10;
            if(player->getPersonagem()->x > 3220)
            {
                player->getPersonagem()->x = 3220;
            }
            break;
        }
    }
}