#include "cube.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);

	Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.01f, 10.0f);
	
	Cube cube;
	Math::Vector3D rotate(0.02f, 0.01f, 0);

	while(true) {
		win.Clear();
		
		Math::Vector3D translate(0, 0, 0.1f);
		
		cube.Rotate(rotate);
		cube.Translate(translate);
		cube.Draw(projection, raz);

		win.Render();
	}
	
	return 0;
}