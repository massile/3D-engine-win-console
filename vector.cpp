#include "vector.h"

namespace Math {
	Vector2D operator*(float a, const Vector2D& vec) {
		return Vector2D(a * vec.x, a * vec.y);
	}

	Vector2D operator+(const Vector2D& u, const Vector2D& v) {
		return Vector2D(u.x + v.x, u.y + v.y);
	}
	
	Vector2D operator+(float a, const Vector2D& v) {
		return Vector2D(a + v.x, a + v.y);
	}

	Vector3D operator*(float a, const Vector3D& vec) {
		return Vector3D(a * vec.x, a * vec.y, a * vec.z);
	}

	Vector3D operator+(const Vector3D& u, const Vector3D& v) {
		return Vector3D(u.x + v.x, u.y + v.y, u.z + v.z);
	}
	
	Vector3D operator+(float a, const Vector3D& v) {
		return Vector3D(a + v.x, a + v.y, a + v.z);
	}
}