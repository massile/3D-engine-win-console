#pragma once

namespace Math {
	constexpr double const PI = 3.14159265358979;

	template <typename T>
	T abs(T x) {
		return x < 0 ? -x : x;
	}

	double cos(double x);
	double sin(double x);
}