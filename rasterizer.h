#pragma once

#include "window.h"

class Rasterizer {
private:
	Window* window;
public:
	Rasterizer(Window* win);
	void DrawLine(short x0, short y0, short x1, short y1, short color = 255);
};