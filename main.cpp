#include "ObjModel.h"
#include "plane.h"

int main() {

	int dim = 180;

	Window win(dim, 4);
	Rasterizer raz(&win);

	ObjModel monkey("monkey.obj");
	ObjModel sphere("sphere.obj");

	sphere.Translate(Math::Vector3D(-3, 0, -3));

	float angle = -0.2f;
	float beta = -Math::PI/2;

	while(true) {
		raz.Clear();
		
		Math::Matrix4x4 view = Math::Matrix4x4::Translation(Math::Vector3D(0, 0, 6))
			* Math::Matrix4x4::RotationX(Math::PI + Math::PI/6)
			* Math::Matrix4x4::RotationY(angle);

		Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.1f, 100.0f) * view;
		Math::Vector3D lightPos(5 * Math::cos(beta), 15, 5 * Math::sin(beta));

		monkey.Draw(projection, raz, lightPos);
		sphere.Draw(projection, raz, lightPos);

		angle -= 0.03f;
		//beta -= 0.05f;
		win.Render();
	}

	return 0;
}