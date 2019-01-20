#include "cube.h"
#include "plane.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);
	
	Plane plane(3);
	Cube cube(1);
	cube.Translate(Math::Vector3D(0, 0.5, 0));

	float angle = 0.2f;
	float beta = 0.0f;

	Math::Vector3D lightPos(10, 5, 2);

	while(true) {
		raz.Clear();
		
		Math::Matrix4x4 view = Math::Matrix4x4::Translation(Math::Vector3D(0, 0, 5)) 
			* Math::Matrix4x4::RotationX(Math::PI)
			* Math::Matrix4x4::RotationY(beta)
			* Math::Matrix4x4::RotationZ(angle)
			* Math::Matrix4x4::Translation(Math::Vector3D(0, -0.5f, 0));

		Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.1f, 100.0f) * view;

		cube.Draw(projection, raz, lightPos);
		plane.Draw(projection, raz, lightPos);

		beta += 0.005f;
		win.Render();
	}
	
	return 0;
}