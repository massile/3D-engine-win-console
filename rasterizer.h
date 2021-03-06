#pragma once

#include "vertex.h"
#include "window.h"

class Rasterizer {
private:
	Window* window;
	float* depthBuffer;

public:
	Rasterizer(Window* win);

	void Clear();
	void DrawLine(const Vertex& pt1, const Vertex& pt2);	
	void DrawTriangle(const Vertex& pt1, const Vertex& pt2, const Vertex& pt3);
	void DrawFilledTriangle(const Vertex& pt1, const Vertex& pt2, const Vertex& pt3);

private:
	void DrawLine(short x0, short y0, short x1, short y1, short color0, short color1);
	Math::Vector3D toScreenSpace(const Math::Vector3D& pt) const;
};