#ifndef CONTROLE_H
#define CONTROLE_H

#include <SDL2/SDL.h>
#include "personagem.h"
#include "camera.h"

void controle(Personagem* player, SDL_Event* evento, Camera& camera);

#endif