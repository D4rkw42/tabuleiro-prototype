// declaração para as peças do jogo

#include "piece.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <SDL2/SDL_Image.h>

#include <iostream>

#include "config.h"

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

	SDL_RenderCopy(render, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image_surface);
}

//

void createNewPiece(std::vector<Piece>& list, Piece_type type, const char* name, double x, double y) {
	Piece piece(type, name, x, y);
	list.push_back(piece);
}
