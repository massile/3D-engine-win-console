#include "rasterizer.h"

Rasterizer::Rasterizer(Window* win) : window(win) {}

void Rasterizer::DrawLine(short x0, short y0, short x1, short y1, short color) {
	for(float t=0.0f; t <= 1.0f; t += 0.001f) {
		short x = t * x0 + (1-t) * x1;
		short y = t * y0 + (1-t) * y1;
		window->DrawPixel(x, y, color);
	}
}
