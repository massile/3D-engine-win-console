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

	Vector2D operator-(const Vector2D& u, const Vector2D& v) {
		return Vector2D(u.x - v.x, u.y - v.y);
	}

	Vector3D operator*(float a, const Vector3D& vec) {
		return Vector3D(a * vec.x, a * vec.y, a * vec.z);
	}

	Vector2D operator/(const Vector2D& v, float a) {
		return Vector2D(v.x / a, v.y / a);
	}

	Vector3D operator^(const Vector3D& u, const Vector3D& v) {
		return Vector3D(
			u.y * v.z - u.z * v.y,
			u.z * v.x - u.x * v.z,
			u.x * v.y - u.y * v.x
		);
	}

	Vector3D operator+(const Vector3D& u, const Vector3D& v) {
		return Vector3D(u.x + v.x, u.y + v.y, u.z + v.z);
	}
	
	Vector3D operator+(float a, const Vector3D& v) {
		return Vector3D(a + v.x, a + v.y, a + v.z);
	}

	Vector3D operator-(const Vector3D& u, const Vector3D& v) {
		return Vector3D(u.x - v.x, u.y - v.y, u.z - v.z);
	}

	Vector3D operator/(const Vector3D& v, float a) {
		return Vector3D(v.x / a, v.y / a, v.z / a);
	}
}