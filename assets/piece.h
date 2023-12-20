// declaração para as peças do jogo

#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>

#include "assets/definitions.h"
#include "assets/square.h"

#include "assets/inputs/button.h"

typedef enum class Piece_type { // o tipo de peça
	PLAYER, CHARACTER
} Piece_type;


//

class Piece {
	public:
		Piece_type type; // o tipo da peça

		int max_health; // quantidad de vida máxima
		int health; // quantidade de vida

		int walk_dist; // distância máxima de movimento
		bool transparent; // se deve ser transparente
		
		std::string image_source; // source da imagem da peça

		double x, y; // posição

		Piece(Piece_type type, const char* name, double x, double y);

		void init(void); // inicialização

		void draw(SDL_Renderer* render, Window_data window_data, Cam_data cam_data);

};

//

// cria uma nova peça
void createNewPiece(std::vector<Piece*>& list, Piece_type type, const char* name, double x, double y);

// mostra o rastro de range de uma peça

void displayPieceRange(SDL_Renderer* render, Piece* target, Square_data square, Window_data window_data, Cam_data cam_data);

#endif
