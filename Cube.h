#pragma once

#include "model.h"

class Cube : public Model {
public:
	Cube(float size) : Model(36) {
		float dim = size / 2;
		vertices = new Vertex[36] {
			Vertex(-dim, -dim, dim, 5),
			Vertex(-dim, dim, dim, 5),
			Vertex(dim, -dim, dim, 5),

			Vertex(dim, -dim, dim, 5),
			Vertex(dim, dim, dim, 5),
			Vertex(-dim, dim, dim, 5),

			Vertex(-dim, -dim, -dim, 10),
			Vertex(-dim, dim, -dim, 10),
			Vertex(dim, -dim, -dim, 10),

			Vertex(dim, -dim, -dim, 10),
			Vertex(dim, dim, -dim, 10),
			Vertex(-dim, dim, -dim, 10),

			Vertex(dim, -dim, -dim, 15),
			Vertex(dim, dim, -dim, 15),
			Vertex(dim, -dim, dim, 15),

			Vertex(dim, dim, -dim, 15),
			Vertex(dim, -dim, dim, 15),
			Vertex(dim, dim, dim, 15),

			Vertex(-dim, -dim, -dim, 15),
			Vertex(-dim, dim, -dim, 15),
			Vertex(-dim, -dim, dim, 15),

			Vertex(-dim, dim, -dim, 15),
			Vertex(-dim, -dim, dim, 15),
			Vertex(-dim, dim, dim, 15),

			Vertex(-dim, -dim, -dim, 8),
			Vertex(dim, -dim, dim, 8),
			Vertex(-dim, -dim, dim, 8),
			
			Vertex(-dim, -dim, -dim, 8),
			Vertex(dim, -dim, dim, 8),
			Vertex(dim, -dim, -dim, 8),

			Vertex(-dim, dim, -dim, 8),
			Vertex(dim, dim, dim, 8),
			Vertex(-dim, dim, dim, 8),

			Vertex(-dim, dim, -dim, 8),
			Vertex(dim, dim, dim, 8),
			Vertex(dim, dim, -dim, 8),
		};
	}
};