#include "Cube.h"

Cube::Cube(float size) {
	float dim = size / 2;

	vertices = new Vertex[36] {
		Vertex(-dim, -dim, dim, 5),
		Vertex(-dim, dim, dim, 5),
		Vertex(dim, -dim, dim, 5),

		Vertex(dim, -dim, dim, 5),
		Vertex(dim, dim, dim, 5),
		Vertex(-dim, dim, dim, 5),

		Vertex(-dim, -dim, -dim, 10),
		Vertex(-dim, dim, -dim, 10),
		Vertex(dim, -dim, -dim, 10),

		Vertex(dim, -dim, -dim, 10),
		Vertex(dim, dim, -dim, 10),
		Vertex(-dim, dim, -dim, 10),

		Vertex(dim, -dim, -dim, 15),
		Vertex(dim, dim, -dim, 15),
		Vertex(dim, -dim, dim, 15),

		Vertex(dim, dim, -dim, 15),
		Vertex(dim, -dim, dim, 15),
		Vertex(dim, dim, dim, 15),

		Vertex(-dim, -dim, -dim, 15),
		Vertex(-dim, dim, -dim, 15),
		Vertex(-dim, -dim, dim, 15),

		Vertex(-dim, dim, -dim, 15),
		Vertex(-dim, -dim, dim, 15),
		Vertex(-dim, dim, dim, 15),

		Vertex(-dim, -dim, -dim, 8),
		Vertex(dim, -dim, dim, 8),
		Vertex(-dim, -dim, dim, 8),
		
		Vertex(-dim, -dim, -dim, 8),
		Vertex(dim, -dim, dim, 8),
		Vertex(dim, -dim, -dim, 8),

		Vertex(-dim, dim, -dim, 8),
		Vertex(dim, dim, dim, 8),
		Vertex(-dim, dim, dim, 8),

		Vertex(-dim, dim, -dim, 8),
		Vertex(dim, dim, dim, 8),
		Vertex(dim, dim, -dim, 8),
	};
}

void Cube::Draw(Math::Matrix4x4& projection, Rasterizer& raz) {
	model = Math::Matrix4x4::Translation(position)
			 * Math::Matrix4x4::RotationX(rotation.x)
			 * Math::Matrix4x4::RotationY(rotation.y)
			 * Math::Matrix4x4::RotationZ(rotation.z);

	for(short i = 0; i < 36; i += 3) {
		Vertex pt1 = vertices[i];
		Vertex pt2 = vertices[i + 1];
		Vertex pt3 = vertices[i + 2];

		pt1.position = projection * model * pt1.position;
		pt2.position = projection * model * pt2.position;
		pt3.position = projection * model * pt3.position;
		
		raz.DrawFilledTriangle(pt1, pt2, pt3);
	}
}

void Cube::Rotate(const Math::Vector3D& rotation) {
	this->rotation = this->rotation + rotation;
}

void Cube::Translate(const Math::Vector3D& translation) {
	this->position = this->position + translation;
}
