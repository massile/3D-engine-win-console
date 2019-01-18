#include "window.h"
#include "math.h"
#include "matrix.h"
#include "rasterizer.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);

	Math::Vector3D pt1(-0.5f, -0.5f, 0.0f);
	Math::Vector3D pt2(0.0f, 0.5f, 0.0f);
	Math::Vector3D pt3(0.5f, -0.5f, 0.0f);

	float alpha = 0;
	float factor = 0;
	
	while(true) {
		win.Clear();
	
		Math::Matrix4x4 model = Math::Matrix4x4::Scale(factor) * Math::Matrix4x4::RotationZ(-alpha);

		Math::Vector3D pt10 = model * pt1;
		Math::Vector3D pt20 = model * pt2;
		Math::Vector3D pt30 = model * pt3;
		alpha += 0.01f;
		factor = Math::cos(alpha);

		raz.DrawTriangle(pt10, pt20, pt30);
		win.Render();
	}
	
	return 0;
}