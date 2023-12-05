// sistema de manipulação de eventos

#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>

void onMouseWheel(SDL_Event* event); // disparado quando se usa a roda do mouse
void onMouseMove(SDL_Event* event); // disparado quando o mouse se move
void onMouseClick(SDL_Event* event, int dir); // disparado quando o mouse clica

void handleEvents(SDL_Event* event); // carrega os eventos

#endif
