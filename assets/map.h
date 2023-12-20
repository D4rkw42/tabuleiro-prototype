// definições de mapa

#ifndef MAP_H
#define MAP_H

#include <string>
#include <SDL2/SDL.h>

#include "assets/definitions.h"

typedef struct Map { // guarda dados de um mapa
	double scale; // escala de desenho
	std::string source;
} Map;

//

Map* loadMap(const char* name); // o nome do mapa a ser carregado
void renderMap(SDL_Renderer* render, Map* map, Window_data window_data, Cam_data cam_data); // renderiza um mapa

#endif
