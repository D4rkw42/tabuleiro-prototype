// definições gráficas para barra de vida

#include "health-bar.h"

#include <cmath>

#include "config.h"

#include <iostream>

Color makeGradient(Color from, Color to, double alpha, double percentage) {
	Color gradient;

	double diff_r = abs(from.r - to.r);
	double diff_g = abs(from.g - to.g);
	double diff_b = abs(from.b - to.b);

	int dir_r = (to.r > from.r)? 1 : -1;
	int dir_g = (to.g > from.g)? 1 : -1;
	int dir_b = (to.b > from.b)? 1 : -1;

	gradient.r = from.r + diff_r * percentage * dir_r;
	gradient.g = from.g + diff_g * percentage * dir_g;
	gradient.b = from.b + diff_b * percentage * dir_b;

	gradient.a = alpha;

	return gradient;
}

//

void drawHealthBar(SDL_Renderer* render, Piece* piece, Window_data window_data, Cam_data cam_data) {
	double hp_percentage = (double)piece->health / piece->max_health; // porcentagem atual de vida

	SDL_Rect rect;

	// calculando valor real

	rect.w = SQUARE_SIZE * HEALTH_BAR_WIDTH * hp_percentage; // definindo tamanho
	rect.h = HEALTH_BAR_HEIGHT;

	rect.x = piece->x * SQUARE_SIZE - rect.w / 2;
	rect.y = piece->y * SQUARE_SIZE - rect.h / 2;

	rect.y-= SQUARE_SIZE * 0.76;

	// calculando valor virtual

	rect.x = (rect.x - cam_data.x) * cam_data.scale;
	rect.y = (rect.y - cam_data.y) * cam_data.scale;

	rect.x+= window_data.width / 2;
	rect.y+= window_data.height / 2;

	rect.w*= cam_data.scale;
	rect.h*= cam_data.scale;

	// definindo cor

	Color color;

	Color base_green = Color{64, 253, 17, 255};
	Color base_yellow = Color{255, 242, 0, 255};
	Color base_red = Color{255, 0, 0, 255};

	// selecionando gradiente

	if (piece->health <= piece->max_health * LIMIT_RED_PERCENTAGE)
		color = makeGradient(base_yellow, base_red, 255, 1 - (double)piece->health / (piece->max_health * LIMIT_RED_PERCENTAGE));
	else if (piece->health <= piece->max_health * LIMIT_YELLOW_PERCENTAGE)
		color = base_yellow;
	else
		color = base_green;

	//

	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, HEALTH_BAR_OPACITY * 255);
	SDL_RenderFillRect(render, &rect);
}
