#pragma once

#include "rasterizer.h"
#include "matrix.h"

class Cube {
private:
	short* indices;
	Math::Vector3D* vertices;
	Math::Matrix4x4 model;

	Math::Vector3D position = Math::Vector3D(0, 0, 0);
	Math::Vector3D rotation = Math::Vector3D(0, 0, 0);

public:
	Cube();
	void Draw(Math::Matrix4x4& projection, Rasterizer& raz);
	void Rotate(Math::Vector3D& rotation);
	void Translate(Math::Vector3D& translation);
};