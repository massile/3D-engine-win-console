#include <iostream>
#include "math.h"

namespace Math {
	double cos(double x) {
		if (abs(x) < 0.01) {
			double x2 = x*x;
			return 1 + x2 * (x2 / 24 - 0.5);
		}
		double halfCos = cos(x/2);
		return 2 * halfCos * halfCos - 1;
	}

	double sin(double x) {
		return cos(x - PI/2);
	}

	double cotan(double x) {
		return cos(x) / sin(x);
	}

	float clamp(float x) {
		return x > 14 ? 15 : x + 1;
	}

	Rectangle BoundingBox(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3) {
		Utils::Tuple<float> leftRight = Math::minMax(v1.x, v2.x, v3.x);
		Utils::Tuple<float> bottomTop = Math::minMax(v1.y, v2.y, v3.y);
		return Rectangle(leftRight.first, bottomTop.second, leftRight.second, bottomTop.first);
	}

	Vector3D Barycenter(const Vector2D& a, const Vector2D& b, const Vector2D& c, const Vector2D& g) {
		double detT = (b.y - c.y) * (a.x - c.x) + (c.x - b.x) * (a.y - c.y);

		double l1 = ((b.y - c.y) * (g.x - c.x) + (c.x - b.x) * (g.y - c.y)) / detT;
		double l2 = ((c.y - a.y) * (g.x - c.x) + (a.x - c.x) * (g.y - c.y)) / detT;

		return Vector3D(l1, l2, 1.0f - l1 - l2);
	}
}