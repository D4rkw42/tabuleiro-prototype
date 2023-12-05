// definições gráficas para barra de vida

#include "health-bar.h"

#include "config.h"

void drawHealthBar(SDL_Renderer* render, Piece piece, Window_data window_data, Cam_data cam_data) {
	double hp_percentage = piece.health / piece.max_health; // porcentagem atual de vida

	SDL_Rect rect;

	// calculando valor real

	rect.w = SQUARE_SIZE * HEALTH_BAR_WIDTH * hp_percentage; // definindo tamanho
	rect.h = HEALTH_BAR_HEIGHT;

	rect.x = piece.x * SQUARE_SIZE - rect.w / 2;
	rect.y = piece.y * SQUARE_SIZE - rect.h / 2;

	rect.y-= SQUARE_SIZE * 0.76;

	// calculando valor virtual

	rect.x = (rect.x - cam_data.x) * cam_data.scale;
	rect.y = (rect.y - cam_data.y) * cam_data.scale;

	rect.x+= window_data.width / 2;
	rect.y+= window_data.height / 2;

	rect.w*= cam_data.scale;
	rect.h*= cam_data.scale;

	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(render, 100, 255, 100, HEALTH_BAR_OPACITY * 255);

	SDL_RenderFillRect(render, &rect);
}
