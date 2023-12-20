// definições para botão

#include "button.h"

Button::Button(void* data, int x, int y, int width, int height) {
	this->data = data;

	this->x = x;
	this->y = y;

	this->width = width;
	this->height = height;
}
