#include "cube.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);
	Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.01f, 1000.0f);

	Cube cube(1);

	while(true) {
		raz.Clear();
		
		cube.Rotate(Math::Vector3D(0, 0.01, 0));
		cube.Rotate(Math::Vector3D(0, 0, 0.01));
		cube.Draw(projection, raz);

		win.Render();
	}
	
	return 0;
}