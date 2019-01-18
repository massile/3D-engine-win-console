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
}