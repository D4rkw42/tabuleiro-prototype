// definições de desenho e busca de quadrados

#include "square.h"

#include <cmath>

#include "config.h"

#include <iostream>

void drawSquareGrid(SDL_Renderer* render, Window_data window_data, Cam_data cam_data) {
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255); // branco

	int initial_x = cam_data.x - window_data.width / 2 * 1 / cam_data.scale;
	int initial_y = cam_data.y - window_data.height / 2 * 1 / cam_data.scale;

	int final_x = cam_data.x + window_data.width / 2 * 1 / cam_data.scale;
	int final_y = cam_data.y + window_data.height / 2 * 1 / cam_data.scale;

	initial_x-= initial_x % SQUARE_SIZE;
	initial_y-= initial_y % SQUARE_SIZE;

	final_x+= final_x % SQUARE_SIZE + SQUARE_SIZE;
	final_y+= final_y % SQUARE_SIZE + SQUARE_SIZE;

	for (int x = initial_x; x <= final_x; x+= SQUARE_SIZE) {
		double pos_x = (x - SQUARE_SIZE / 2 - cam_data.x) * cam_data.scale;

		pos_x+= window_data.width / 2;

		SDL_RenderDrawLine(render, pos_x, 0, pos_x, window_data.height);
	}

	for (int y = initial_y; y <= final_y; y+= SQUARE_SIZE) {
		double pos_y = (y - SQUARE_SIZE / 2 - cam_data.y) * cam_data.scale;

		pos_y+= window_data.height / 2;

		SDL_RenderDrawLine(render, 0, pos_y, window_data.width, pos_y);
	}
}

void fillSquare(SDL_Renderer* render, int x, int y, Window_data window_data, Cam_data cam_data) {
	// calculando valores reais

	SDL_Rect rect;

	rect.x = floor(x * SQUARE_SIZE) - SQUARE_SIZE / 2;
	rect.y = floor(y * SQUARE_SIZE) - SQUARE_SIZE / 2;

	// calculando valores virtuais

	rect.x = (rect.x - cam_data.x) * cam_data.scale;
	rect.y = (rect.y - cam_data.y) * cam_data.scale;

	rect.x+= window_data.width / 2;
	rect.y+= window_data.height / 2;

	rect.w = SQUARE_SIZE * cam_data.scale;
	rect.h = SQUARE_SIZE * cam_data.scale;

	// desenhando

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderFillRect(render, &rect);
}

//

Square_data findSquare(int x, int y) {
	Square_data data;

	int x_before = (x > 0)? x - x % SQUARE_SIZE : (x - SQUARE_SIZE) + (-x % SQUARE_SIZE);
	int x_after = x_before + SQUARE_SIZE;

	int y_before = (y > 0)? y - y % SQUARE_SIZE : (y - SQUARE_SIZE) + (-y % SQUARE_SIZE);
	int y_after = y_before + SQUARE_SIZE;

	data.x = (abs(x - x_before) < abs(x - x_after))? x_before : x_after;
	data.y = (abs(y - y_before) < abs(y - y_after))? y_before : y_after;

	data.x/= SQUARE_SIZE;
	data.y/= SQUARE_SIZE;

	return data;
}
