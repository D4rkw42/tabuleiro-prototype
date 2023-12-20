// definições para botão

#ifndef BUTTON_H
#define BUTTON_H

#include <vector>
#include <SDL2/SDL.h>

#include "assets/definitions.h"

class Button {
	public:
		void* data;

		int x, y;
		int width, height;

		Button(void* data, int x, int y, int width, int height);
		virtual ~Button() {};

		virtual void onClick(int dir) {}; // dispara quando clicado
		virtual void draw(SDL_Renderer* render, Window_data window_data) {};

};

template <typename BntType, typename Bnt_dataType>
void createButton(std::vector<Button*>& bntList, int x, int y, int width, int height, Bnt_dataType* data) { // cria um novo botão
	BntType* button = new BntType((void*)data, x, y, width, height);
	bntList.push_back((Button*)button);
}

#endif
