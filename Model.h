#pragma once

#include "rasterizer.h"
#include "matrix.h"
#include "vector.h"

class Model {
protected:
	short numVertices;
	Vertex* vertices;
	Math::Matrix4x4 model;

	Math::Vector3D position = Math::Vector3D(0.0f, 0.0f, 0.0f);
	Math::Vector3D rotation = Math::Vector3D(0.0f, 0.0f, 0.0f);
public:
	Model(short numVertices);

	void Draw(Math::Matrix4x4& projection, Rasterizer& raz, const Math::Vector3D& lightPos);
	void Rotate(const Math::Vector3D& rotation);
	void Translate(const Math::Vector3D& translation);

private:
	short CalculateColor(const Math::Vector3D& lightPos, const Vertex& vertex);
};