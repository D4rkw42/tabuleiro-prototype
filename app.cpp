// definições de operação do aplicativo

#include "app.h"

#include <SDL2/SDL.h>

#include "global.h"
#include "config.h"

#include "assets/definitions.h"
#include "assets/maths.h"

#include "assets/map.h"

#include "assets/square.h"
#include "assets/piece.h"
#include "assets/health-bar.h"
#include "assets/panel.h"

#include "assets/inputs/button.h"

#include <iostream>

void initApp(void) {
	for (int i = 1; i <= 3; i++)
		createNewPiece(pieceList, Piece_type::PLAYER, "william", (i - 6), 0);

	//mapSellected = loadMap("forest-3");

	// criação do painel

	// aumento/diminuição de vida

	createButton<Bnt_changeHealth, Bnt_changeHealth_data>(button_list, 20, 20, 50, 50, new Bnt_changeHealth_data{panel_pieceSellected, 1});
	createButton<Bnt_changeHealth, Bnt_changeHealth_data>(button_list, 90, 20, 50, 50, new Bnt_changeHealth_data{panel_pieceSellected, -1});
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

	Square_data square = findSquare(pointer_map_x, pointer_map_y);

	//

	Window_data window_data{w_width, w_height};
	Cam_data cam_data{cam_scale, cam_x, cam_y};

	//

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255); // preto
	SDL_RenderClear(render); // clear

	// desenhando mapa

	if (mapSellected != NULL)
		renderMap(render, mapSellected, window_data, cam_data);

	// desenhando peças

	for (size_t i = 0; i < pieceList.size(); i++)
		pieceList[i]->draw(render, window_data, cam_data); // peça

	// desenhando a grade

	if (piece_moving)
		drawSquareGrid(render, window_data, cam_data);

	// desenhando health bar

	if (!piece_moving) {
		for (size_t i = 0; i < pieceList.size(); i++)
			drawHealthBar(render, pieceList[i], window_data, cam_data); // vida
	}

	// desenhando localização do ponteiro

	static int alpha = 0;
	static int fadeDir = 1;

	if (enlighten_pointer_square) {
		Color color;

		alpha+= fadeDir * 15;

		if (alpha >= 200) // oscilação da cor
			fadeDir*= -1;
		else if (alpha <= 0) {
			alpha = 0;
			fadeDir*= -1;
		}

		if (distance(pieceSellected->x, pieceSellected->y, square.x, square.y) > pieceSellected->walk_dist)
			color = Color{255, 150, 150, alpha};
		else
			color = Color{150, 255, 150, alpha};

		fillSquare(render, square.x, square.y, color, window_data, cam_data);
	}

	// rastro de distância durante alocação de peças

	if (piece_moving)
		displayPieceRange(render, pieceSellected, square, window_data, cam_data);

	// renderização do painel

	for (Button* bnt : button_list) // botões
		bnt->draw(render, window_data);

	//

	SDL_RenderPresent(render);
}
