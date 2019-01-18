#pragma once

#include "vector.h"
#include "math.h"

namespace Math {

	struct Matrix4x4 {
		float* data;

		Matrix4x4(): data(new float[16]) {}
		Matrix4x4(float* data) : data(data) {}
	public:
		void Set(int i, int j, float x);
		float Get(int i, int j) const;

		static Matrix4x4 Identity();
		static Matrix4x4 Translation(const Vector3D& position);
		static Matrix4x4 RotationZ(double angle);
		static Matrix4x4 RotationY(double angle);
		static Matrix4x4 RotationX(double angle);
		static Matrix4x4 Scale(float factor);

		static Matrix4x4 Perspective(float fov, float far, float near);
	};

	Matrix4x4 operator*(float a, const Matrix4x4& mat);
	Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b);
	Matrix4x4 operator+(const Matrix4x4& a, const Matrix4x4& b);
	Matrix4x4 operator-(const Matrix4x4& a, const Matrix4x4& b);

	Vector3D operator*(const Matrix4x4& a, const Vector3D& b);
}
