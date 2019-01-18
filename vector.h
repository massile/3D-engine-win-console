#pragma once

namespace Math {
	struct Vector2D {
		float x;
		float y;

		Vector2D() {}
		Vector2D(float x, float y): x(x), y(y) {}
	};

	Vector2D operator*(float a, const Vector2D& vec);
	Vector2D operator+(const Vector2D& u, const Vector2D& v);
	Vector2D operator+(float a, const Vector2D& v);

	struct Vector3D: public Vector2D {
		float z;

		Vector3D() : Vector2D() {}		
		Vector3D(float x, float y, float z): Vector2D(x, y), z(z) {}
	};

	Vector3D operator*(float a, const Vector3D& vec);
	Vector3D operator+(const Vector3D& u, const Vector3D& v);
	Vector3D operator+(float a, const Vector3D& v);


}