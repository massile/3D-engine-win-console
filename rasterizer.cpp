#include "rasterizer.h"
#include "utils.h"
#include "math.h"

Rasterizer::Rasterizer(Window* win) : 
	window(win),
	depthBuffer(new float[win->GetDimension() * win->GetDimension()]) {}

void Rasterizer::DrawLine(const Vertex& pt1, const Vertex& pt2) {
	Math::Vector2D u = toScreenSpace(pt1.position);
	Math::Vector2D v = toScreenSpace(pt2.position);
	DrawLine(u.x, u.y, v.x, v.y, pt1.color, pt2.color);	
}

void Rasterizer::Clear() {
	window->Clear();
	short l = window->GetDimension() * window->GetDimension();
	for(int i=0; i < l; i++) {
		depthBuffer[i] = -10000;
	}
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

	short dimension = window->GetDimension();

	for (int x = x0; x <= x1; x++) {
		double t = double(x - x1) / double(x0 - x1);
		short color = t * color0 + (1 - t) * color1;
		int y = t * y0 + (1 - t) * y1;

		if(x < 0 || x >= dimension || y < 0 || y >= dimension) continue;

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

void Rasterizer::DrawFilledTriangle(const Vertex& pt1, const Vertex& pt2, const Vertex& pt3) {
	Math::Vector3D p1 = toScreenSpace(pt1.position);
	Math::Vector3D p2 = toScreenSpace(pt2.position);
	Math::Vector3D p3 = toScreenSpace(pt3.position);
	
	Math::Rectangle bbox = Math::BoundingBox(p1, p2, p3);
	short dimension = window->GetDimension();

	Math::Vector2D G;
	for (G.x = bbox.left; G.x < bbox.right; G.x++) {
		for (G.y = bbox.bottom; G.y < bbox.top; G.y++) {
			if(G.x < 0 || G.x >= dimension || G.y < 0 || G.y >= dimension) continue;

			Math::Vector3D bary = Math::Barycenter(p1, p2, p3, G);
			if (bary.x < 0 || bary.y < 0 || bary.z < 0) continue;

			short color = bary.x * pt1.color + bary.y * pt2.color + bary.z * pt3.color + 0.5;
			float z = bary.x * p1.z + bary.y * p2.z + bary.z * p3.z;
			short index = G.x + G.y * dimension;
			if (z > depthBuffer[index]) {
				depthBuffer[index] = z;
				window->DrawPixel(G.x, G.y, color);	
			}				
		}
	}
}

Math::Vector3D Rasterizer::toScreenSpace(const Math::Vector3D& pt) const {
	float w = window->GetDimension() / 2.0f;
	float x = 1.0f + pt.x;
	float y = 1.0f - pt.y;
	float z = 1.0f + pt.z;
	return w * Math::Vector3D(x, y, z);
}
