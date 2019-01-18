#include "rasterizer.h"
#include "utils.h"
#include "math.h"

Rasterizer::Rasterizer(Window* win) : window(win) {}

void Rasterizer::DrawLine(const Math::Vector2D& pt1, const Math::Vector2D& pt2, short color) {
	Math::Vector2D u = toScreenSpace(pt1);
	Math::Vector2D v = toScreenSpace(pt2);
	DrawLine(u.x, u.y, v.x, v.y, color);
}

void Rasterizer::DrawLine(short x0, short y0, short x1, short y1, short color) {
	bool steep = false;
	if (Math::abs(x1 - x0) < Math::abs(y1 - y0)) {
		Utils::Swap(x0, y0);
		Utils::Swap(x1, y1);
		steep = true;
	}

	if (x1 < x0) {
		Utils::Swap(x0, x1);
		Utils::Swap(y0, y1);
	}

	for (int x = x0; x <= x1; x++) {
		double t = double(x - x1) / double(x0 - x1);
		int y = t * y0 + (1 - t) * y1;

		if (steep) {
			window->DrawPixel(y, x, color);			
		} else {
			window->DrawPixel(x, y, color);
		}
	}
}

void Rasterizer::DrawTriangle(const Math::Vector2D& pt1, const Math::Vector2D& pt2, const Math::Vector2D& pt3, short color) {
	DrawLine(pt1, pt2, color);
	DrawLine(pt2, pt3, color);
	DrawLine(pt3, pt1, color);
}
