// controla os sistemas básicos

#include "system.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

#include "global.h"
#include "app.h"

bool initialize(void) {
	bool sdl_init_success = SDL_Init(SDL_INIT_VIDEO); // iniciando vídeo

	if (sdl_init_success) return false;

	window = SDL_CreateWindow("Tormenta20", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE); // criando janela

	if (!window) return false;

	//

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // criando renderizador

	// ativando transparências

	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND); // draw funcs

	// icone da janela

	SDL_Surface* icon_surface = IMG_Load("source/images/icon.png");

	SDL_SetWindowIcon(window, icon_surface);
	SDL_FreeSurface(icon_surface);

	//

	initApp(); // iniciando app

	return true;
}

void quit(void) {
	quitApp(); // finalizando app

	//

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);

	SDL_Quit();
}
