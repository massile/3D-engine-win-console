#include "rasterizer.h"
#include "window.h"
#include "vertex.h"
#include "matrix.h"

int main() {
	int dim = 170;

	Window win(dim, 4);
	Rasterizer raz(&win);
	Math::Matrix4x4 projection = Math::Matrix4x4::Perspective(1.22f, 0.01f, 10.0f);

	Vertex* pointList = new Vertex[18] {
		Vertex(-0.5f, -0.5f, 0.5f, 10),
		Vertex(-0.5f, 0.5f, 0.5f, 15),
		Vertex(0.5f, -0.5f, 0.5f, 10),

		Vertex(0.5f, -0.5f, 0.5f, 10),
		Vertex(0.5f, 0.5f, 0.5f, 15),
		Vertex(-0.5f, 0.5f, 0.5f, 15),

		Vertex(-0.5f, -0.5f, -0.5f, 10),
		Vertex(-0.5f, 0.5f, -0.5f, 15),
		Vertex(0.5f, -0.5f, -0.5f, 10),

		Vertex(0.5f, -0.5f, -0.5f, 10),
		Vertex(0.5f, 0.5f, -0.5f, 15),
		Vertex(-0.5f, 0.5f, -0.5f, 15),


		Vertex(0.5f, -0.5f, -0.5f, 10),
		Vertex(0.5f, 0.5f, -0.5f, 15),
		Vertex(0.5f, -0.5f, 0.5f, 10),

		Vertex(0.5f, 0.5f, -0.5f, 15),
		Vertex(0.5f, -0.5f, 0.5f, 10),
		Vertex(0.5f, 0.5f, 0.5f, 15),
	};

	float angle = 0.0f;
	float beta = 0.0f;

	while(true) {
		win.Clear();

		Math::Matrix4x4 model =  Math::Matrix4x4::Translation(Math::Vector3D(0.0f, 0.0f, 10.0f))
								 * Math::Matrix4x4::RotationY(angle)
								 * Math::Matrix4x4::RotationX(beta);
		
		for(short i = 0; i < 18; i += 3) {
			Vertex pt1 = pointList[i];
			Vertex pt2 = pointList[i + 1];
			Vertex pt3 = pointList[i + 2];

			pt1.position = projection * model * pt1.position;
			pt2.position = projection * model * pt2.position;
			pt3.position = projection * model * pt3.position;
			
			raz.DrawFilledTriangle(pt1, pt2, pt3);
		}

		angle += 0.02f;
		beta += 0.05f;
		win.Render();
	}
	
	return 0;
}