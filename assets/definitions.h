// definições globais

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct Cam_data { // dados da câmera
	double scale;
	double x, y;
} Cam_data;

typedef struct Window_data { // dados da janela
	int width, height;
} Window_data;

typedef struct Pointer { // dados do ponteiro
	int x, y;
} Pointer;

typedef struct Color { // guarda dados de cores
	int r, g, b, a;
} Color;

#endif
