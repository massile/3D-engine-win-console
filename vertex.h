#pragma once

#include "vector.h"

struct Vertex {
	Math::Vector3D position;
	short color;

	Vertex(const Math::Vector3D& position, short color) : position(position), color(color) {}
	Vertex(float x, float y, float z, short color) : position(Math::Vector3D(x, y, z)), color(color) {}
};