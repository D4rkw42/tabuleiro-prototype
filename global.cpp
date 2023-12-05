// variáveis globais

#include "global.h"
#include "config.h"

// SDL

SDL_Window* window; // janela
SDL_Renderer* render; // renderizador

// definições de câmera

double cam_scale = GENERAL_SCALE; // escala de visualização da câmera

double cam_x = 0; // posição x da câmera
double cam_y = 0; // posição y da câmera

double last_cam_x = 0; // última posição x da câmera conhecida
double last_cam_y = 0; // última posição y da câmera conhecida

// definições de ponteiro

int pointer_x = 0; // posição x do ponteiro
int pointer_y = 0; // posição y do ponteiro

// definições de efeito

bool piece_moving = false; // se uma peça está sendo movida
bool enlighten_pointer_square = false; // se o quadrado onde está o ponteiro deve estar iluminado

// controle do mouse

bool mouseReleasedRight = true; // se o mouse não está clicado
bool mouseReleasedLeft = true; // se o mouse esquerdo não está clicado

int last_click_x_right = 0; // última posição x de click down conhecida (direita)
int last_click_y_right = 0; // última posição y de click down conhecida (direita)

// variáveis globais

std::vector<Piece> pieceList; // peças do jogo
Piece* pieceSellected = NULL; // peça selecionada
