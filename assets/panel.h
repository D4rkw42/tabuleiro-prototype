// definições do painel de controle

#ifndef PANEL_H
#define PANEL_H

#include <SDL2/SDL.h>

#include "assets/definitions.h"
#include "assets/piece.h"

#include "assets/inputs/button.h"

// bnt data

typedef struct {
	Piece*& panel_pieceSellected;
	int hp_change_dir;
} Bnt_changeHealth_data;


typedef struct {

} Bnt_loadMap_data;


typedef struct {

} Bnt_mapOff_data;


// botões de controle

class Bnt_changeHealth: public Button { // controle da vida
	public:
		Bnt_changeHealth(void* data): Button(data) {};
		virtual ~Bnt_changeHealth() {};

		void draw(SDL_Renderer* render, Window_data window_data);
		void onClick(int dir);

};

class Bnt_loadMap: public Button { // controle de mapa
	public:
		Bnt_loadMap(void* data): Button(data) {};

		void draw(SDL_Renderer* render, Window_data window_data);
		void onClick(int dir);

};

class Bnt_mapOff: public Button { // controle de mapa
	public:
		Bnt_mapOff(void* data): Button(data) {};

		void draw(SDL_Renderer* render, Window_data window_data);
		void onClick(int dir);
		
};

#endif
