#include "rasterizer.h"
#include "window.h"
#include "vertex.h"
#include "matrix.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);
	Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.01f, 10.0f);

	Vertex point1(-0.5f, -0.5f, 0.0f, 15);
	Vertex point2(0.0f, 0.5f, 0.0f, 15);
	Vertex point3(0.5f, -0.5f, 0.0f, 0);

	while(true) {
		win.Clear();
		raz.DrawTriangle(point1, point2, point3);
		win.Render();
	}
	
	return 0;
}