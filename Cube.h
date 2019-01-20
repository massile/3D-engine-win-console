#pragma once

#include "model.h"

class Cube : public Model {
public:
	Cube(float size, short color = 15) : Model(36) {
		float dim = size / 2;
		vertices = new Vertex[36] {
			Vertex(-dim, -dim, dim, 0.0f, 0.0f, 1.0f, color),
			Vertex(-dim,  dim, dim, 0.0f, 0.0f, 1.0f, color),
			Vertex( dim, -dim, dim, 0.0f, 0.0f, 1.0f, color),

			Vertex( dim, -dim, dim, 0.0f, 0.0f, 1.0f, color),
			Vertex( dim,  dim, dim, 0.0f, 0.0f, 1.0f, color),
			Vertex(-dim,  dim, dim, 0.0f, 0.0f, 1.0f, color),

			Vertex(-dim, -dim, -dim, 0.0f, 0.0f, -1.0f, color),
			Vertex(-dim,  dim, -dim, 0.0f, 0.0f, -1.0f, color),
			Vertex( dim, -dim, -dim, 0.0f, 0.0f, -1.0f, color),

			Vertex( dim, -dim, -dim, 0.0f, 0.0f, -1.0f, color),
			Vertex( dim,  dim, -dim, 0.0f, 0.0f, -1.0f, color),
			Vertex(-dim,  dim, -dim, 0.0f, 0.0f, -1.0f, color),

			Vertex(dim, -dim, -dim, 1.0f, 0.0f, 0.0f, color),
			Vertex(dim,  dim, -dim, 1.0f, 0.0f, 0.0f, color),
			Vertex(dim, -dim,  dim, 1.0f, 0.0f, 0.0f, color),

			Vertex(dim,  dim, -dim, 1.0f, 0.0f, 0.0f, color),
			Vertex(dim, -dim,  dim, 1.0f, 0.0f, 0.0f, color),
			Vertex(dim,  dim,  dim, 1.0f, 0.0f, 0.0f, color),

			Vertex(-dim, -dim, -dim, -1.0f, 0.0f, 0.0f, color),
			Vertex(-dim,  dim, -dim, -1.0f, 0.0f, 0.0f, color),
			Vertex(-dim, -dim,  dim, -1.0f, 0.0f, 0.0f, color),

			Vertex(-dim,  dim, -dim, -1.0f, 0.0f, 0.0f, color),
			Vertex(-dim, -dim,  dim, -1.0f, 0.0f, 0.0f, color),
			Vertex(-dim,  dim,  dim, -1.0f, 0.0f, 0.0f, color),

			Vertex(-dim, -dim, -dim, 0.0f, -1.0f, 0.0f, color),
			Vertex( dim, -dim,  dim, 0.0f, -1.0f, 0.0f, color),
			Vertex(-dim, -dim,  dim, 0.0f, -1.0f, 0.0f, color),
			
			Vertex(-dim, -dim, -dim, 0.0f, -1.0f, 0.0f, color),
			Vertex( dim, -dim,  dim, 0.0f, -1.0f, 0.0f, color),
			Vertex( dim, -dim, -dim, 0.0f, -1.0f, 0.0f, color),

			Vertex(-dim, dim, -dim, 0.0f, 1.0f, 0.0f, color),
			Vertex( dim, dim,  dim, 0.0f, 1.0f, 0.0f, color),
			Vertex(-dim, dim,  dim, 0.0f, 1.0f, 0.0f, color),

			Vertex(-dim, dim, -dim, 0.0f, 1.0f, 0.0f, color),
			Vertex( dim, dim,  dim, 0.0f, 1.0f, 0.0f, color),
			Vertex( dim, dim, -dim, 0.0f, 1.0f, 0.0f, color),
		};
	}
};