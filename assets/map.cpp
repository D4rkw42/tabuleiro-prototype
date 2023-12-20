// definições de mapa

#include "map.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <SDL2/SDL_Image.h>

using namespace nlohmann;

using std::ifstream;
using std::string;

Map* loadMap(const char* name) {
	const char* data_root = "assets/resources/maps.json"; // root de acesso para mapas

	ifstream file(data_root); // abrindo maps.json

	json data = json::parse(file)[name]; // capturando dados do mapa

	//

	Map* map = new Map;

	string img_source = data["source"].dump();

	map->scale = data["scale"];
	map->source = string("source/images/maps/") + img_source.substr(1, img_source.length() - 2);

	return map;
}

void renderMap(SDL_Renderer* render, Map* map, Window_data window_data, Cam_data cam_data) {
	SDL_Surface* map_surface = IMG_Load(map->source.c_str()); // surface da imagem
	SDL_Texture* map_img = SDL_CreateTextureFromSurface(render, map_surface); // gerando surface

	int img_width, img_height;

	SDL_QueryTexture(map_img, NULL, NULL, &img_width, &img_height);

	SDL_Rect draw_rect; // retangulo de dimensionamento

	// calculando valores reais

	draw_rect.w = img_width * map->scale;
	draw_rect.h = img_height * map->scale;

	draw_rect.x = -draw_rect.w / 2;
	draw_rect.y = -draw_rect.h / 2;

	// calculando valores virtuais

	draw_rect.w*= cam_data.scale;
	draw_rect.h*= cam_data.scale;

	draw_rect.x = (draw_rect.x - cam_data.x) * cam_data.scale;
	draw_rect.y = (draw_rect.y - cam_data.y) * cam_data.scale;

	draw_rect.x+= window_data.width / 2;
	draw_rect.y+= window_data.height / 2;

	SDL_RenderCopy(render, map_img, NULL, &draw_rect);

	//

	SDL_FreeSurface(map_surface);
	SDL_DestroyTexture(map_img);
}
