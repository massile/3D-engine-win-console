#include <iostream>
#include "math.h"

namespace Math {
	float cos(float x) {
		if (abs(x) < 0.01) {
			float x2 = x*x;
			return 1 + x2 * (x2 / 24 - 0.5);
		}
		float halfCos = cos(x/2);
		return 2 * halfCos * halfCos - 1;
	}

	float sin(float x) {
		return cos(x - PI/2);
	}

	float cotan(float x) {
		return cos(x) / sin(x);
	}

	float sqrt(float x) {
		float r = x;
		for (short i = 0; i < 50; i++) {
			r = (r + x / r) * 0.5f;
		}
		return r;
	}

	Rectangle BoundingBox(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3) {
		Utils::Tuple<float> leftRight = Math::minMax(v1.x, v2.x, v3.x);
		Utils::Tuple<float> bottomTop = Math::minMax(v1.y, v2.y, v3.y);
		return Rectangle(leftRight.first, bottomTop.second + 1, leftRight.second + 1, bottomTop.first);
	}

	Vector3D Barycenter(const Vector2D& a, const Vector2D& b, const Vector2D& c, const Vector2D& g) {
		float detT = (b.y - c.y) * (a.x - c.x) + (c.x - b.x) * (a.y - c.y);

		float l1 = ((b.y - c.y) * (g.x - c.x) + (c.x - b.x) * (g.y - c.y)) / detT;
		float l2 = ((c.y - a.y) * (g.x - c.x) + (a.x - c.x) * (g.y - c.y)) / detT;

		return Vector3D(l1, l2, 1.0f - l1 - l2);
	}
}