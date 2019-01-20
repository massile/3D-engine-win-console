#include "Model.h"

Model::Model(short numVertices) : numVertices(numVertices) {}

void Model::Draw(Math::Matrix4x4& projection, Rasterizer& raz) {
	model = Math::Matrix4x4::Translation(position)
			 * Math::Matrix4x4::RotationX(rotation.x)
			 * Math::Matrix4x4::RotationY(rotation.y)
			 * Math::Matrix4x4::RotationZ(rotation.z);

	for(short i = 0; i < numVertices; i += 3) {
		Vertex pt1 = vertices[i];
		Vertex pt2 = vertices[i + 1];
		Vertex pt3 = vertices[i + 2];

		pt1.position = projection * model * pt1.position;
		pt2.position = projection * model * pt2.position;
		pt3.position = projection * model * pt3.position;
		
		raz.DrawFilledTriangle(pt1, pt2, pt3);
	}
}

void Model::Rotate(const Math::Vector3D& rotation) {
	this->rotation = this->rotation + rotation;
}

void Model::Translate(const Math::Vector3D& translation) {
	this->position = this->position + translation;
}
