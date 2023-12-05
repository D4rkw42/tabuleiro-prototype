// definições de desenho e busca de quadrados

#ifndef SQUARE_H
#define SQUARE_H

#include <SDL2/SDL.h>

#include "definitions.h"

typedef struct Square_data { // dados de posição de um quadrado
	int x, y;
} Square_data;

void drawSquareGrid(SDL_Renderer* render, Window_data window_data, Cam_data cam_data); // desenha toda a malha do app
void fillSquare(SDL_Renderer* render, int x, int y, Color color, Window_data window_data, Cam_data cam_data); // desenha um quadrado filled na posição especificada

Square_data findSquare(int x, int y); // localiza a posição do quadrado mais próximo da coordenada

#endif
