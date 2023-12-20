// definições do painel de controle

#include "panel.h"

#include <SDL2/SDL_Image.h>

#include <iostream>

void Bnt_changeHealth::onClick(int dir) {

};

void Bnt_changeHealth::draw(SDL_Renderer* render, Window_data window_data) {
	Bnt_changeHealth_data* data = (Bnt_changeHealth_data*)this->data;

	SDL_Surface* img_surface = IMG_Load((data->hp_change_dir == 1)? "source/images/icons/plus_bnt.png" : "source/images/icons/minus_bnt.png");
	SDL_Texture* bnt_image = SDL_CreateTextureFromSurface(render, img_surface);

	SDL_Rect rect;

	rect.w = this->width;
	rect.h = rect.w;

	rect.x = rect.w + this->x;
	rect.y = window_data.height - (rect.h + this->y);

	rect.x-= rect.w / 2;
	rect.y-= rect.h / 2;

	SDL_RenderCopy(render, bnt_image, NULL, &rect);

	SDL_FreeSurface(img_surface);
	SDL_DestroyTexture(bnt_image);
};

//

void Bnt_loadMap::onClick(int dir) {

};

void Bnt_loadMap::draw(SDL_Renderer* render, Window_data window_data) {

};

//

void Bnt_mapOff::onClick(int dir) {

};

void Bnt_mapOff::draw(SDL_Renderer* render, Window_data window_data) {

};
