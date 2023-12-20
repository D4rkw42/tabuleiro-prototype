// definições gráficas para barra de vida

#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SDL2/SDL.h>

#include "assets/definitions.h"
#include "assets/piece.h"

// dimensões e aparência

#define HEALTH_BAR_WIDTH 0.88 // (% em relação a SQUARE_SIZE)
#define HEALTH_BAR_HEIGHT 8 // (px)

#define HEALTH_BAR_OPACITY 0.6 // (%)

#define LIMIT_YELLOW_PERCENTAGE 0.6 // porcentagem em que o amarelo começa a aparecer
#define LIMIT_RED_PERCENTAGE 0.3 // porcentagem em que o vermelho começa a aparecer

Color makeGradient(Color from, Color to, double alpha, double percentage); // retorna a cor de um gradiente

void drawHealthBar(SDL_Renderer* render, Piece* piece, Window_data window_data, Cam_data cam_data); // desenha a barra de vida

#endif
