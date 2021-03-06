#pragma once

#include "vector.h"

struct Vertex {
	Math::Vector3D position;
	Math::Vector3D normal;
	short color;
	
	Vertex() {} 

	Vertex(const Math::Vector3D& position, const Math::Vector3D& normal, short color = 15) : 
		position(position), 
		normal(normal),
		color(color) {}
		
	Vertex(float x, float y, float z, short color) : 
		position(Math::Vector3D(x, y, z)),
		color(color) {}

	Vertex(float x, float y, float z, float nx, float ny, float nz, short color) :
		 position(Math::Vector3D(x, y, z)), 
		 normal(Math::Vector3D(nx, ny, nz)), 
		 color(color) {}
};