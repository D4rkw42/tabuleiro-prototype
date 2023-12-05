// definições gráficas para barra de vida

#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SDL2/SDL.h>

#include "assets/definitions.h"
#include "assets/piece.h"

// dimensões e aparência

#define HEALTH_BAR_WIDTH 0.88 // (% em relação a SQUARE_SIZE)
#define HEALTH_BAR_HEIGHT 8 // (px)

#define HEALTH_BAR_OPACITY 0.5 // (%)

void drawHealthBar(SDL_Renderer* render, Piece piece, Window_data window_data, Cam_data cam_data); // desenha a barra de vida

#endif
