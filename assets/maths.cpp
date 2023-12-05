// funções matemáticas

#include "maths.h"

#include <cmath>

int distance(int x1, int y1, int x2, int y2) {
	int distX = abs(x1 - x2);
	int distY = abs(y1 - y2);

	return floor(sqrt(distX * distX + distY * distY));
}
