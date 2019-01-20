#pragma once

#include "Model.h"

class Plane: public Model {
public:
	Plane(float size, short color = 15) : Model(6) {
		float dim = size / 2;
		vertices = new Vertex[6] {
			Vertex(-dim, 0,  dim, 0, 1, 0, color),
			Vertex(-dim, 0, -dim, 0, 1, 0, color),
			Vertex( dim, 0,  dim, 0, 1, 0, color),

			Vertex( dim, 0, -dim, 0, 1, 0, color),
			Vertex( dim, 0,  dim, 0, 1, 0, color),
			Vertex(-dim, 0, -dim, 0, 1, 0, color),
		};
	}
};