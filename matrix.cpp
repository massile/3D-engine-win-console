#include "matrix.h"

namespace Math {
	void Matrix4x4::Set(int i, int j, float x) {
		data[i*4 + j] = x;
	}

	float Matrix4x4::Get(int i, int j) const {
		return data[i*4 + j];
	}
	
	Matrix4x4 Matrix4x4::Identity() {
		return Matrix4x4(new float[16] {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1,
		});
	}

	Matrix4x4 Matrix4x4::Translation(const Vector3D& position) {
		return Matrix4x4(new float[16] {
			1.0f, 0.0f, 0.0f, position.x,
			0.0f, 1.0f, 0.0f, position.y,
			0.0f, 0.0f, 1.0f, position.z,
			0.0f, 0.0f, 0.0f, 1.0f,
		});
	}

	Matrix4x4 Matrix4x4::RotationZ(double angle) {
		return Matrix4x4(new float[16] {
			cos(angle), -sin(angle), 0, 0,
			sin(angle), cos(angle),  0, 0,
			0,          0,           1, 0,
			0,          0,           0, 1,
		});
	}

	Matrix4x4 Matrix4x4::RotationY(double angle) {
		return Matrix4x4(new float[16] {
		  cos(angle),	0, sin(angle), 0,
		  0,	        1, 0,          0,
		  -sin(angle),	0, cos(angle), 0,
		  0,	        0, 0,          1,
		});
	}

	Matrix4x4 Matrix4x4::RotationX(double angle) {
		return Matrix4x4(new float[16] {
			1, 0,          0,           0,
			0, cos(angle), -sin(angle), 0,
			0, sin(angle), cos(angle),  0,
			0, 0,          0,           1,
		});
	}

	Matrix4x4 Matrix4x4::Scale(float factor) {
		return Matrix4x4(new float[16] {
			factor, 0,      0,      0,
			0,      factor, 0,      0,
			0,      0,      factor, 0,
			0,      0,      0,      1,
		});
	}

	Matrix4x4 Matrix4x4::Perspective(float fov, float near, float far) {
		float cot = cotan(fov / 2.0f);
		float invNF = 1.0f / (near - far);
		return Matrix4x4(new float[16] {
			cot * 1.5f, 0,   0,                    0,
			0,   cot, 0,                    0,
			0,   0,   (near + far) * invNF, 2.0f * far * near * invNF,
			0,   0,   -1, 1,
		});	
	}

	Matrix4x4 operator*(float a, const Matrix4x4& mat) {
		Matrix4x4 m;
		for(int i = 0; i < 16; i++) {
			m.data[i] = a * mat.data[i];
		}
		return m;
	}

	Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b) {
		Matrix4x4 m;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				float sum = 0.0f;
				for(int k = 0; k < 4; k++) {
					sum += a.Get(i, k) * b.Get(k, j);
				}
				m.Set(i, j, sum);
			}
		}
		return m;
	}

	Matrix4x4 operator+(const Matrix4x4& a, const Matrix4x4& b) {
		Matrix4x4 m;
		for(int i = 0; i < 16; i++) {
			m.data[i] = a.data[i] + b.data[i];
		}
		return m;
	}

	Matrix4x4 operator-(const Matrix4x4& a, const Matrix4x4& b) {
		Matrix4x4 m;
		for(int i = 0; i < 16; i++) {
			m.data[i] = a.data[i] - b.data[i];
		}
		return m;
	}

	Vector3D operator*(const Matrix4x4& a, const Vector3D& b) {
		Vector3D v;
		float x = a.Get(0, 0) * b.x + a.Get(0, 1) * b.y + a.Get(0, 2) * b.z + a.Get(0, 3);
		float y = a.Get(1, 0) * b.x + a.Get(1, 1) * b.y + a.Get(1, 2) * b.z + a.Get(1, 3);
		float z = a.Get(2, 0) * b.x + a.Get(2, 1) * b.y + a.Get(2, 2) * b.z + a.Get(2, 3);
		float w = a.Get(3, 0) * b.x + a.Get(3, 1) * b.y + a.Get(3, 2) * b.z + a.Get(3, 3);

		v.x = x / w;
		v.y = y / w;
		v.z = z / w;
		return v;
	}
}