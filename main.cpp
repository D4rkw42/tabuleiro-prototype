#include <iostream>
#include <chrono>
#include <cstdlib>

#include <SDL2/SDL.h>

#include "system.h"

#include "event-handler.h"
#include "app.h"

using namespace std::chrono;

//

#define EPOCH_TIME duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() // definição do epoch time

#define FPS 30 // FPS do aplicativo

//

SDL_Event* event = new SDL_Event; // variável auxiliar para eventos

//

long int lastEpoch = EPOCH_TIME; // guarda o epoch da última execução
int deltatime = 0; // tempo decorrido

int render_count = 0;

int main(int argc, char** argv) {
	bool init_success = initialize(); // iniciando

	if (!init_success) return EXIT_FAILURE;

	while(true) {
		// manipulação de tempo

		deltatime = EPOCH_TIME - lastEpoch;
		lastEpoch = EPOCH_TIME;

		//

		SDL_PollEvent(event); // atualiza registro de eventos

		if (event->type == SDL_QUIT) { // carregando evento
			break;
		} else {
			handleEvents(event);
		}

		update(deltatime);

		render_count+= deltatime;

		if (render_count >= 1000 / FPS) {
			render_count = 0;

			draw();
		}

		SDL_Delay(10); // delay global
	}

	quit(); // finalizando

	return 0;
}
