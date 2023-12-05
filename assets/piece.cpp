// declaração para as peças do jogo

#include "piece.h"

#include <fstream>
#include <cmath>
#include <nlohmann/json.hpp>
#include <SDL2/SDL_Image.h>

#include <iostream>

#include "config.h"

#include "assets/maths.h"

using namespace nlohmann;
using namespace std;

Piece::Piece(Piece_type type, const char* name, double x, double y) {
	const char* data_root = "assets/pieces.json"; // root de acesso de dados
	const char* target; // alvo para tipo

	string img_source = "source/images/"; // root de acesso de imagens

	// catalogando subpastas

	if (type == Piece_type::PLAYER)
		target = "players";
	else if (type == Piece_type::CHARACTER)
		target = "charaters";

	ifstream file(data_root); // capturando arquivo de dados
	json data = json::parse(file)[target][name]; // capturando dados

	// salvando dados

	this->max_health = data["max-health"];
	this->walk_dist = data["walk-dist"];

	this->health = this->max_health;

	this->x = x;
	this->y = y;

	this->transparent = false;

	string img_source_info = data["img-source"].dump(); // dado do objeto json
	string img_final_source = img_source + img_source_info.substr(1, img_source_info.length() - 2); // capturando root completa

	this->image_source = img_final_source;
}

//

void Piece::draw(SDL_Renderer* render, Window_data window_data, Cam_data cam_data) {
	int img_width;

	SDL_Surface* image_surface = IMG_Load(this->image_source.c_str()); // capturando surface
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, image_surface); // criando texture

	SDL_QueryTexture(texture, NULL, NULL, &img_width, NULL); // capturando img width

	double scale = (double)SQUARE_SIZE / img_width;

	// desenhando

	SDL_Rect rect;

	// calculando valor real

	rect.w = img_width * scale;
	rect.h = img_width * scale;

	rect.x = floor(this->x * SQUARE_SIZE) - rect.w / 2;
	rect.y = floor(this->y * SQUARE_SIZE) - rect.h / 2;

	// calculando valor virtual

	rect.x = (rect.x - cam_data.x) * cam_data.scale;
	rect.y = (rect.y - cam_data.y) * cam_data.scale;

	rect.x+= window_data.width / 2;
	rect.y+= window_data.height / 2;

	rect.w*= cam_data.scale;
	rect.h*= cam_data.scale;

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture, this->transparent? 0.5 * 255 : 255);
	SDL_RenderCopy(render, texture, NULL, &rect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image_surface);
}

//

void createNewPiece(std::vector<Piece>& list, Piece_type type, const char* name, double x, double y) {
	Piece piece(type, name, x, y);
	list.push_back(piece);
}

void displayPieceRange(SDL_Renderer* render, Piece* target, Square_data square, Window_data window_data, Cam_data cam_data) {
	int distX = abs(target->x - square.x);
	int distY = abs(target->y - square.y);

	int dist = distance(target->x, target->y, square.x, square.y);

	double stepX, stepY;

	if (dist > 0) {
		stepX = (double)distX / dist; // step de desenho X
		stepY = (double)distY / dist; // step de desenho Y
	} else {
		stepX = 0;
		stepY = 0;
	}

	int dirX = (target->x > square.x)? -1 : 1;
	int dirY = (target->y > square.y)? -1 : 1;

	for (int i = 1; i < dist; i++) {
		Color color;

		int pos_x = target->x + ceil(stepX * dirX * i);
		int pos_y = target->y + ceil(stepY * dirY * i);

		if (target->x == pos_x && target->y == pos_y)
			continue;

		if (distance(target->x, target->y, pos_x, pos_y) > target->walk_dist)
			color = Color{255, 150, 150, 200};
		else
			color = Color{150, 255, 150, 200};

		fillSquare(render, pos_x, pos_y, color, window_data, cam_data);

	}
}
