#include "Matrix2.h"
//--------------------------------------------------------------------------------
// 
// Comments are the same for Matrix4.cpp the only change is the matrix size
//  
//--------------------------------------------------------------------------------
Matrix2::Matrix2()
{
	m[0][0] = 1;	
	m[0][1] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
}

Matrix2::Matrix2(float xx, float xy, float yy, float yx)
{
	m[0][0] = xx;
	m[0][1] = xy;
	m[1][0] = yy;
	m[1][1] = yx;
}

Matrix2::~Matrix2()
{
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 result;
	result.x = m[0][0] * rhs.x + m[1][0] * rhs.y;
	result.y = m[0][1] * rhs.x + m[1][1] * rhs.y;
	return result;
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 result;
	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0];
	result.m[0][1] = m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1];

	result.m[1][0] = m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0];
	result.m[1][1] = m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1];
	return result;
}

void Matrix2::setRotate(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
}

void Matrix2::setScale(float x, float y)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[1][0] = 0;
	m[1][1] = y;
}

Vector2 Matrix2::getScale()
{
	Vector2 result;
	result.x = m[0][0];
	result.y = m[1][1];
	return result;
}

Vector2 & Matrix2::operator[](const int rhs)
{
	return *(Vector2*)m[rhs];
}

Matrix2::operator float*()
{
	return &m[0][0];
}

bool Matrix2::isIdentity()
{
	int count = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i == j && m[i][j] == 1)
				++count;
			else if (i != j && m[i][j] == 0)
				++count;
		}
	}
	if (count == 4)
	{
		return true;
	}

	return false;
}

float Matrix2::determinant()
{
	float a = m[0][0];
	float b = m[0][1];
	float c = m[1][0];
	float d = m[1][1];

	return (a * b - d * c);
}

void Matrix2::transpose()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			m[i][j] = m[j][i];
		}
	}
}

Matrix2 Matrix2::inverse()
{
	float a = m[0][0];
	float b = m[0][1];
	float c = m[1][0];
	float d = m[1][1];

	a = m[1][1] / determinant();
	b = -m[0][1] / determinant();
	c = -m[1][0] / determinant();
	d = m[0][0] / determinant();

	Matrix2 invMatrix(m[0][0], m[0][1], m[1][0], m[1][1]);
	return invMatrix;
}