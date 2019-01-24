#include "Model.h"

Model::Model(short numVertices) : numVertices(numVertices) {}

void Model::Draw(Math::Matrix4x4& projection, Rasterizer& raz, const Math::Vector3D& lightPos) {
	model = Math::Matrix4x4::Translation(position)
			 * Math::Matrix4x4::RotationX(rotation.x)
			 * Math::Matrix4x4::RotationY(rotation.y)
			 * Math::Matrix4x4::RotationZ(rotation.z);

	for(short i = 0; i < numVertices; i += 3) {
		Vertex pt1 = vertices[i];
		Vertex pt2 = vertices[i + 1];
		Vertex pt3 = vertices[i + 2];

		pt1.position = model * pt1.position;
		pt2.position = model * pt2.position;
		pt3.position = model * pt3.position;

		pt1.normal = model * pt1.normal;
		pt2.normal = model * pt2.normal;
		pt3.normal = model * pt3.normal;

		pt1.color = CalculateColor(lightPos, pt1);
		pt2.color = CalculateColor(lightPos, pt2);
		pt3.color = CalculateColor(lightPos, pt3);

		pt1.position = projection * pt1.position;
		pt2.position = projection * pt2.position;
		pt3.position = projection * pt3.position;
		
		raz.DrawFilledTriangle(pt1, pt2, pt3);
	}
}

short Model::CalculateColor(const Math::Vector3D& lightPos, const Vertex& vertex) {
	Math::Vector3D lightDir = Math::normalize(lightPos - vertex.position);
	float distance = Math::length(lightPos - vertex.position);

	float intensity = 10 * (lightDir * vertex.normal) / distance;
	if (intensity < 0) intensity = 0.0f;

	float finalColor = vertex.color * intensity + 3;

	return finalColor > 15 ? 15 : finalColor;
}

void Model::Rotate(const Math::Vector3D& rotation) {
	this->rotation = this->rotation + rotation;
}

void Model::Translate(const Math::Vector3D& translation) {
	this->position = this->position + translation;
}
