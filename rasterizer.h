#pragma once

#include "window.h"
#include "vector.h"

class Rasterizer {
private:
	Window* window;
public:
	Rasterizer(Window* win);
	void DrawLine(const Math::Vector2D& pt1, const Math::Vector2D& pt2, short color = 15);
	void DrawTriangle(const Math::Vector2D& pt1, const Math::Vector2D& pt2, const Math::Vector2D& pt3, short color = 15);

private:
	void DrawLine(short x0, short y0, short x1, short y1, short color = 15);
	Math::Vector2D toScreenSpace(const Math::Vector2D& pt) const {
		float w = window->GetDimension() / 2.0f;
		float x = 1.0f + pt.x;
		float y = 1.0f - pt.y;
		return w * Math::Vector2D(x, y);
	}
};