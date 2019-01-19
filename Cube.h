#pragma once

#include "rasterizer.h"
#include "matrix.h"
#include "vector.h"

class Cube {
private:
	Vertex* vertices;
	Math::Matrix4x4 model;

	Math::Vector3D position = Math::Vector3D(0.0f, 0.0f, 0.0f);
	Math::Vector3D rotation = Math::Vector3D(0.0f, 0.0f, 0.0f);
public:
	Cube(float size);
	void Draw(Math::Matrix4x4& projection, Rasterizer& raz);
	void Rotate(const Math::Vector3D& rotation);
	void Translate(const Math::Vector3D& translation);
};