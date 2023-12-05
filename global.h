// variáveis globais

#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>

#include <SDL2/SDL.h>

#include "assets/piece.h"

// definições

// SDL

extern SDL_Window* window; // janela
extern SDL_Renderer* render; // renderizador

// definições de câmera

extern double cam_scale; // escala de visualização da câmera

extern double cam_x; // posição x da câmera
extern double cam_y; // posição y da câmera

extern double last_cam_x; // última posição x da câmera conhecida
extern double last_cam_y; // última posição y da câmera conhecida

// definições de ponteiro

extern int pointer_x; // posição x do ponteiro
extern int pointer_y; // posição y do ponteiro

// definições de efeito

extern bool enlighten_pointer_square; // se o quadrado onde está o ponteiro deve estar iluminado

// controle do mouse

extern bool mouseReleasedRight; // se o mouse direito não está clicado
extern bool mouseReleasedLeft; // se o mouse esquerdo não está clicado

extern int last_click_x_right; // última posição x de click down conhecida (direita)
extern int last_click_y_right; // última posição y de click down conhecida (direita)

// variáveis globais

extern std::vector<Piece> pieceList; // peças do jogo
extern Piece* pieceSellected; // peça selecionada

#endif
