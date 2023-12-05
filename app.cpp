// definições de operação do aplicativo

#include "app.h"

#include <SDL2/SDL.h>

#include "global.h"
#include "config.h"

#include "assets/definitions.h"
#include "assets/square.h"
#include "assets/piece.h"
#include "assets/health-bar.h"

#include <iostream>

void initApp(void) {
	for (int i = 1; i <= 10; i++)
		createNewPiece(pieceList, Piece_type::PLAYER, "william", (i - 15), 0);
}

void quitApp(void) {

}

//

void update(int deltatime) {
	
}

void draw(void) {
	int w_width, w_height; // larguras e alturas da janela

	SDL_GetWindowSize(window, &w_width, &w_height); // captura dimensões da janela

	double pointer_map_x = cam_x + (pointer_x - w_width / 2) * 1 / cam_scale;
	double pointer_map_y = cam_y + (pointer_y - w_height / 2) * 1 / cam_scale;

	//

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255); // preto
	SDL_RenderClear(render); // clear

	// desenhando a grade

	drawSquareGrid(render, Window_data{w_width, w_height}, Cam_data{cam_scale, cam_x, cam_y});

	// desenhando peças

	for (size_t i = 0; i < pieceList.size(); i++) { 
		pieceList[i].draw(render, Window_data{w_width, w_height}, Cam_data{cam_scale, cam_x, cam_y}); // peça
		drawHealthBar(render, pieceList[i], Window_data{w_width, w_height}, Cam_data{cam_scale, cam_x, cam_y}); // vida
	}

	// desenhando localização do ponteiro

	if (enlighten_pointer_square) {
		Square_data square = findSquare(pointer_map_x, pointer_map_y);

		fillSquare(render, square.x, square.y, Window_data{w_width, w_height}, Cam_data{cam_scale, cam_x, cam_y});
	}

	//

	SDL_RenderPresent(render);
}
