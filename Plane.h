#pragma once

#include "Model.h"

class Plane: public Model {
public:
	Plane(float size) : Model(6) {
		float dim = size / 2;
		vertices = new Vertex[6] {
			Vertex(-dim, 0, dim, 7),
			Vertex(-dim, 0, -dim, 7),
			Vertex(dim, 0, dim, 7),

			Vertex(dim, 0, -dim, 7),
			Vertex(dim, 0, dim, 7),
			Vertex(-dim, 0, -dim, 7),
		};
	}
};