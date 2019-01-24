#include <stdio.h>
#include "Model.h"

class ObjModel : public Model {
public:
	ObjModel(const char* filename) {
		FILE* fp = fopen(filename, "r");

		int numPositions, numNormals;
		fscanf(fp, "np %d\n", &numPositions);
		fscanf(fp, "nn %d\n", &numNormals);
		fscanf(fp, "nf %d\n", &numVertices);

		Math::Vector3D* positions = new Math::Vector3D[numPositions];
		Math::Vector3D* normals = new Math::Vector3D[numNormals];
		vertices = new Vertex[numVertices];

		for (int i = 0; i < numPositions; i++) {
			Math::Vector3D v;
			fscanf(fp, "v %f %f %f\n", &v.x, &v.y, &v.z);
			positions[i] = v;
		}
		for (int i = 0; i < numNormals; i++) {
			Math::Vector3D v;
			fscanf(fp, "vn %f %f %f\n", &v.x, &v.y, &v.z);
			normals[i] = v;
		}
		for (int i = 0; i < numVertices; i += 3) {
			int p0, p1, p2, n0, n1, n2;
			fscanf(fp, "f %d//%d %d//%d %d//%d\n", &p0, &n0, &p1, &n1, &p2, &n2);
			vertices[  i  ] = Vertex(positions[p0 - 1], normals[n0 - 1]);
			vertices[i + 1] = Vertex(positions[p1 - 1], normals[n1 - 1]);
			vertices[i + 2] = Vertex(positions[p2 - 1], normals[n2 - 1]);
		}

		fclose(fp);
	}
};