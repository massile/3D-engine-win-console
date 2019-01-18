#include "Cube.h"

Cube::Cube() {
	vertices = new Math::Vector3D[8] {
		{ -0.5f, -0.5f, -0.5f },
		{  0.5f, -0.5f, -0.5f },
		{ -0.5f,  0.5f, -0.5f },
		{  0.5f,  0.5f, -0.5f },

		{ -0.5f, -0.5f, 0.5f },
		{  0.5f, -0.5f, 0.5f },
		{ -0.5f,  0.5f, 0.5f },
		{  0.5f,  0.5f, 0.5f },
	};

	indices = new short[36] {
		0, 1, 2,
		1, 2, 3,

		4, 5, 6,
		5, 6, 7,

		7, 5, 1,
		7, 3, 1,

		6, 7, 3,
		6, 2, 3,

		6, 2, 0,
		6, 4, 0,

		4, 0, 1,
		4, 5, 1,
	};
}

void Cube::Draw(Math::Matrix4x4& projection, Rasterizer& raz) {
	// Corresponds to the vertex shader
	Math::Vector3D transformedPts[8];
	for(int i = 0; i < 8; i++) {
		model = Math::Matrix4x4::Translation(position)
				* Math::Matrix4x4::RotationX(rotation.x) 
				* Math::Matrix4x4::RotationY(rotation.y)
				* Math::Matrix4x4::RotationZ(rotation.z);

		transformedPts[i] = projection * model * vertices[i];
	}
	for (int i = 0; i < 36; i += 3) {
		raz.DrawTriangle(
			transformedPts[indices[i]],
			transformedPts[indices[i+1]],
			transformedPts[indices[i+2]]
		);
	}
}

void Cube::Rotate(Math::Vector3D& rotation) {
	this->rotation = this->rotation + rotation;
}

void Cube::Translate(Math::Vector3D& translation) {
	this->position = this->position + translation;
}
