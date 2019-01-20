#include "cube.h"
#include "plane.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);
	Cube cube(1);
	Plane plane(2);
	float angle = 0.0f;
	float beta = 0.0f;

	cube.Translate(Math::Vector3D(0, 0.5, 0));

	while(true) {
		raz.Clear();
		
		Math::Matrix4x4 view = Math::Matrix4x4::Translation(Math::Vector3D(0, 0, 3)) 
			* Math::Matrix4x4::RotationX(Math::PI)
			* Math::Matrix4x4::RotationY(beta)
			* Math::Matrix4x4::RotationZ(angle)
			* Math::Matrix4x4::Translation(Math::Vector3D(0, -0.5f, 0));

		Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.1f, 100.0f) * view;

		cube.Draw(projection, raz);
		plane.Draw(projection, raz);

		angle += 0.005f;
		beta += 0.005f;
		win.Render();
	}
	
	return 0;
}