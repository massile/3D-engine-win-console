#pragma once

#include "utils.h"
#include "vector.h"

namespace Math {
	constexpr double const PI = 3.14159265358979;

	struct Rectangle {
		short left;
		short right;
		short top;
		short bottom;

		Rectangle(short left, short top, short right, short bottom)
			: left(left), top(top), right(right), bottom(bottom) {}
	};

	Rectangle BoundingBox(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3);
	Vector3D Barycenter(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3, const Vector2D& g); 


	template <typename T>
	Utils::Tuple<T> minMax(T a1, T a2, T a3) {
		if (a3 < a2) Utils::Swap(a2, a3);
		if (a3 < a1) Utils::Swap(a1, a3);
		if (a2 < a1) Utils::Swap(a2, a1);

		return Utils::Tuple<T>(a1, a3);
	}


	template <typename T>
	T abs(T x) {
		return x < 0 ? -x : x;
	}

	float clamp(float x);

	double cos(double x);
	double sin(double x);
	double cotan(double x);
	double sqrt(double x);
}