#include "rasterizer.h"
#include "utils.h"
#include "math.h"

Rasterizer::Rasterizer(Window* win) : window(win) {}

void Rasterizer::DrawLine(const Vertex& pt1, const Vertex& pt2) {
	Math::Vector2D u = toScreenSpace(pt1.position);
	Math::Vector2D v = toScreenSpace(pt2.position);
	DrawLine(u.x, u.y, v.x, v.y, pt1.color, pt2.color);	
}

void Rasterizer::DrawLine(short x0, short y0, short x1, short y1, short color0, short color1) {
	bool steep = false;
	if (Math::abs(x1 - x0) < Math::abs(y1 - y0)) {
		Utils::Swap(x0, y0);
		Utils::Swap(x1, y1);
		steep = true;
	}

	if (x1 < x0) {
		Utils::Swap(x0, x1);
		Utils::Swap(y0, y1);
		Utils::Swap(color0, color1);
	}

	for (int x = x0; x <= x1; x++) {
		double t = double(x - x1) / double(x0 - x1);
		short color = t * color0 + (1 - t) * color1;
		int y = t * y0 + (1 - t) * y1;

		if (steep) {
			window->DrawPixel(y, x, color);			
		} else {
			window->DrawPixel(x, y, color);
		}

	}	
}

void Rasterizer::DrawTriangle(const Vertex& pt1, const Vertex& pt2, const Vertex& pt3) {
	DrawLine(pt1, pt2);
	DrawLine(pt2, pt3);
	DrawLine(pt3, pt1);
}

Math::Vector2D Rasterizer::toScreenSpace(const Math::Vector2D& pt) const {
	float w = window->GetDimension() / 2.0f;
	float x = 1.0f + pt.x;
	float y = 1.0f - pt.y;
	return w * Math::Vector2D(x, y);
}
