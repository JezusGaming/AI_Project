#include "Matrix3.h"
//--------------------------------------------------------------------------------
// 
// Comments are the same for Matrix4.cpp the only change is the matrix size
//  
//--------------------------------------------------------------------------------
Matrix3::Matrix3()
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}

Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz)
{
	m[0][0] = xx;
	m[0][1] = xy;
	m[0][2] = xz;
	m[1][0] = yx;
	m[1][1] = yy;
	m[1][2] = yz;
	m[2][0] = zx;
	m[2][1] = zy;
	m[2][2] = zz;
}

Matrix3::~Matrix3()
{
}

Vector3 Matrix3::operator*(const Vector3& rhs)
{
	Vector3 result;
	result.x = m[0][0] * rhs.x + m[1][0] * rhs.y + m[2][0] * rhs.z;
	result.y = m[0][1] * rhs.x + m[1][1] * rhs.y + m[2][1] * rhs.z;
	result.z = m[0][2] * rhs.x + m[1][2] * rhs.y + m[2][2] * rhs.z;
	return result;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	Matrix3 result;
	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[1][0] * rhs.m[0][1] + m[2][0] * rhs.m[0][2];
	result.m[0][1] = m[0][1] * rhs.m[0][0] + m[1][1] * rhs.m[0][1] + m[2][1] * rhs.m[0][2];
	result.m[0][2] = m[0][2] * rhs.m[0][0] + m[1][2] * rhs.m[0][1] + m[2][2] * rhs.m[0][2];

	result.m[1][0] = m[0][0] * rhs.m[1][0] + m[1][0] * rhs.m[1][1] + m[2][0] * rhs.m[1][2];
	result.m[1][1] = m[0][1] * rhs.m[1][0] + m[1][1] * rhs.m[1][1] + m[2][1] * rhs.m[1][2];
	result.m[1][2] = m[0][2] * rhs.m[1][0] + m[1][2] * rhs.m[1][1] + m[2][2] * rhs.m[1][2];

	result.m[2][0] = m[0][0] * rhs.m[2][0] + m[1][0] * rhs.m[2][1] + m[2][0] * rhs.m[2][2];
	result.m[2][1] = m[0][1] * rhs.m[2][0] + m[1][1] * rhs.m[2][1] + m[2][1] * rhs.m[2][2];
	result.m[2][2] = m[0][2] * rhs.m[2][0] + m[1][2] * rhs.m[2][1] + m[2][2] * rhs.m[2][2];

	return result;
}

void Matrix3::setRotateX(const float a)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cosf(a);
	m[1][2] = sinf(a);
	m[2][0] = 0;
	m[2][1] = -sinf(a);
	m[2][2] = cosf(a);
}

void Matrix3::setRotateY(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = 0;
	m[0][2] = -sinf(a);
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = sinf(a);
	m[2][1] = 0;
	m[2][2] = cosf(a);
}

void Matrix3::setRotateZ(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[0][2] = 0;
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}

void Matrix3::setPos(float x, float y)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = x;
	m[2][1] = y;
	m[2][2] = 1;
}

void Matrix3::setPos(const Vector2 & rhs)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = rhs.x;
	m[2][1] = rhs.y;
	m[2][2] = 1;
}

Vector2 Matrix3::getPos()
{
	Vector2	result;
	result.x = m[2][0];
	result.y = m[2][1];
	return result;
}

void Matrix3::setScale(float x, float y, float z)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
}

Vector2 Matrix3::getScale()
{
	Vector2 result;
	result.x = m[0][0];
	result.y = m[1][1];
	return result;
}

Vector3 & Matrix3::operator[](const int rhs)
{
	return *(Vector3*)m[rhs];
}

Matrix3::operator float*()
{
	return &m[0][0];
}

bool Matrix3::isIdentity()
{
	int count = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j && m[i][j] == 1)
				++count;
			else if (i != j && m[i][j] == 0)
				++count;
		}
	}
	if (count == 9)
	{
		return true;
	}

	return false;
}

float Matrix3::determinant()
{
	float a = m[0][0];
	float b = m[0][1];
	float c = m[0][2];
	float d = m[1][0];
	float e = m[1][1];
	float f = m[1][2];
	float g = m[2][0];
	float h = m[2][1];
	float i = m[2][2];

	float answerA = a * (e * i - f * h);
	float answerB = b * (d * i  - f * g);
	float answerC = c * (d * h - e * g);

	return answerA - answerB + answerC;

}

void Matrix3::transpose()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] = m[j][i];
		}
	}
}
