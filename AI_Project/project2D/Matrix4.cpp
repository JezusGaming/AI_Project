#include "Matrix4.h"
#include "VectorClass.h"
//--------------------------------------------------------------------------------
//
// All these comments apply for matrix3 and matrix2 cpp files as all functions are
// doing the same thing
//  
//--------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Deafault Constructor
//----------------------------------------------------------------------------
Matrix4::Matrix4()
{
	// it is being set to an identity matrix
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw, float zx, float zy, float zz, float zw, float wx, float wy, float wz, float ww)
{
	// vector positions are being assigned a spot in the matrix
	m[0][0] = xx;
	m[0][1] = xy;
	m[0][2] = xz;
	m[0][3] = xw;

	m[1][0] = yx;
	m[1][1] = yy;
	m[1][2] = yz;
	m[1][3] = yw;

	m[2][0] = zx;
	m[2][1] = zy;
	m[2][2] = zz;
	m[2][3] = zw;

	m[3][0] = wx;
	m[3][1] = wy;
	m[3][2] = wz;
	m[3][3] = ww;
}
//----------------------------------------------------------------------------
// Deafault Destructor
//----------------------------------------------------------------------------
Matrix4::~Matrix4()
{
}
//----------------------------------------------------------------------------
// Overloads the * operator to multiply a matrix and Vector together
//
// Param:
//      rhs: is the other value being multiplied
//
// Return:
//       Returns the result of multiplyed values
//----------------------------------------------------------------------------
Vector4 Matrix4::operator*(const Vector4& rhs)
{
	Vector4 result;
	result.x = m[0][0] * rhs.x + m[1][0] * rhs.y + m[2][0] * rhs.z + m[3][0] * rhs.w;
	result.y = m[0][1] * rhs.x + m[1][1] * rhs.y + m[2][1] * rhs.z + m[3][1] * rhs.w;
	result.z = m[0][2] * rhs.x + m[1][2] * rhs.y + m[2][2] * rhs.z + m[3][2] * rhs.w;
	result.w = m[0][3] * rhs.x + m[1][3] * rhs.y + m[2][3] * rhs.z + m[3][3] * rhs.w;
	return result;
}
//----------------------------------------------------------------------------
// Overloads the * operator to multiply a matrix and matrix together
//
// Param:
//      rhs: is the other value being multiplied
//
// Return:
//       Returns the result of multiplyed values
//----------------------------------------------------------------------------
Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	Matrix4 result;

	//col 1
	result.m[0][0] = (m[0][0] * rhs.m[0][0]) + (m[1][0] * rhs.m[0][1]) + (m[2][0] * rhs.m[0][2]) + (m[3][0] * rhs.m[0][3]);
	result.m[1][0] = (m[0][0] * rhs.m[1][0]) + (m[1][0] * rhs.m[1][1]) + (m[2][0] * rhs.m[1][2]) + (m[3][0] * rhs.m[1][3]);
	result.m[2][0] = (m[0][0] * rhs.m[2][0]) + (m[1][0] * rhs.m[2][1]) + (m[2][0] * rhs.m[2][2]) + (m[3][0] * rhs.m[2][3]);
	result.m[3][0] = (m[0][0] * rhs.m[3][0]) + (m[1][0] * rhs.m[3][1]) + (m[2][0] * rhs.m[3][2]) + (m[3][0] * rhs.m[3][3]);

	//col 2
	result.m[0][1] = (m[0][1] * rhs.m[0][0]) + (m[1][1] * rhs.m[0][1]) + (m[2][1] * rhs.m[0][2]) + (m[3][1] * rhs.m[0][3]);
	result.m[1][1] = (m[0][1] * rhs.m[1][0]) + (m[1][1] * rhs.m[1][1]) + (m[2][1] * rhs.m[1][2]) + (m[3][1] * rhs.m[1][3]);
	result.m[2][1] = (m[0][1] * rhs.m[2][0]) + (m[1][1] * rhs.m[2][1]) + (m[2][1] * rhs.m[2][2]) + (m[3][1] * rhs.m[2][3]);
	result.m[3][1] = (m[0][1] * rhs.m[3][0]) + (m[1][1] * rhs.m[3][1]) + (m[2][1] * rhs.m[3][2]) + (m[3][1] * rhs.m[3][3]);

	//col 3
	result.m[0][2] = (m[0][2] * rhs.m[0][0]) + (m[1][2] * rhs.m[0][1]) + (m[2][2] * rhs.m[0][2]) + (m[3][2] * rhs.m[0][3]);
	result.m[1][2] = (m[0][2] * rhs.m[1][0]) + (m[1][2] * rhs.m[1][1]) + (m[2][2] * rhs.m[1][2]) + (m[3][2] * rhs.m[1][3]);
	result.m[2][2] = (m[0][2] * rhs.m[2][0]) + (m[1][2] * rhs.m[2][1]) + (m[2][2] * rhs.m[2][2]) + (m[3][2] * rhs.m[2][3]);
	result.m[3][2] = (m[0][2] * rhs.m[3][0]) + (m[1][2] * rhs.m[3][1]) + (m[2][2] * rhs.m[3][2]) + (m[3][2] * rhs.m[3][3]);

	//col 4
	result.m[0][3] = (m[0][3] * rhs.m[0][0]) + (m[1][3] * rhs.m[0][1]) + (m[2][3] * rhs.m[0][2]) + (m[3][3] * rhs.m[0][3]);
	result.m[1][3] = (m[0][3] * rhs.m[1][0]) + (m[1][3] * rhs.m[1][1]) + (m[2][3] * rhs.m[1][2]) + (m[3][3] * rhs.m[1][3]);
	result.m[2][3] = (m[0][3] * rhs.m[2][0]) + (m[1][3] * rhs.m[2][1]) + (m[2][3] * rhs.m[2][2]) + (m[3][3] * rhs.m[2][3]);
	result.m[3][3] = (m[0][3] * rhs.m[3][0]) + (m[1][3] * rhs.m[3][1]) + (m[2][3] * rhs.m[3][2]) + (m[3][3] * rhs.m[3][3]);

	return result;
}
//----------------------------------------------------------------------------
// Rotates the on the xaxis
//
// Param:
//      a: amount it is being rotated
//
// Return:
//----------------------------------------------------------------------------
void Matrix4::setRotateX(const float a)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = cosf(a);
	m[1][2] = sinf(a);
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = -sinf(a);
	m[2][2] = cosf(a);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// Rotates the on the yaxis
//
// Param:
//      a: amount it is being rotated
//
// Return:
//----------------------------------------------------------------------------
void Matrix4::setRotateY(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = 0;
	m[0][2] = -sinf(a);
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = sinf(a);
	m[2][1] = 0;
	m[2][2] = cosf(a);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// Rotates the on the zaxis
//
// Param:
//      a: amount it is being rotated
//
// Return:
//----------------------------------------------------------------------------
void Matrix4::setRotateZ(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// stores the postion of an object
//
// Param:
//      x: location on the xaxis
//		y: location on the yaxis
//		z: location on the zaxis
// Return:
//----------------------------------------------------------------------------
void Matrix4::setPos(float x, float y, float z)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = x;
	m[3][1] = y;
	m[3][2] = z;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// stores the postion of an object based on a vector
//
// Param:
//      rhs: vector position geting stored
// Return:
//----------------------------------------------------------------------------
void Matrix4::setPos(const Vector4 & rhs)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = rhs.x;
	m[3][1] = rhs.y;
	m[3][2] = rhs.z;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// gets the position stored in the matrix
//
// Param:
//      
// Return:
//		Returns the objects position
//----------------------------------------------------------------------------
Vector3 Matrix4::getPos()
{
	Vector3	result;
	result.x = m[3][0];
	result.y = m[3][1];
	result.z = m[3][2];
	return result;
}
//----------------------------------------------------------------------------
// stores the scale of an object
//
// Param:
//      x: scale on the xaxis
//		y: scale on the yaxis
//		z: sclae on the zaxis
// Return:
//----------------------------------------------------------------------------
void Matrix4::setScale(float x, float y, float z)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}
//----------------------------------------------------------------------------
// gets the scale of the object
//
// Param:
//      
// Return:
//		Returns the objects scale
//----------------------------------------------------------------------------
Vector3 Matrix4::getScale()
{
	Vector3 result;
	result.x = m[0][0];
	result.y = m[1][1];
	result.z = m[2][2];
	return result;
}

Vector4 & Matrix4::operator[](const int rhs)
{
	return *(Vector4*)m[rhs];
}

Matrix4::operator float*()
{
	return &m[0][0];
}
//----------------------------------------------------------------------------
// checks if the matrix is an identity matrix
//
// Param:
//      
// Return:
//		Returns true or false depending if it is or is not an identity matrix
//----------------------------------------------------------------------------
bool Matrix4::isIdentity()
{
	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i == j && m[i][j] == 1)
				++count;
			else if (i != j && m[i][j] == 0)
				++count;
		}
	}
	if (count == 16)
	{
		return true;
	}
		
	return false;
}
//----------------------------------------------------------------------------
// calculates the determinant of the matrix
//
// Param:
//      
// Return:
//		Returns determinant of the matrix
//----------------------------------------------------------------------------
float Matrix4::determinant()
{
	float a = m[0][0];
	float b = m[0][1];
	float c = m[0][2];
	float d = m[0][3];
	float e = m[1][0];
	float f = m[1][1];
	float g = m[1][2];
	float h = m[1][3];
	float i = m[2][0];
	float j = m[2][1];
	float k = m[2][2];
	float l = m[2][3];
	float mm = m[3][0];
	float n = m[3][1];
	float o = m[3][2];
	float p = m[3][3];

	float resa = a *(f*k*p - f*l*o - g*j*p + g*l*n + h*j*o - h*k*n);
	float resb = b *(e*k*p - e*l*o - g*i*p + g*l*mm + h*i*o - h*k*mm);
	float resc = c *(e*j*p - e*l*n - f*i*p + f*l*mm + h*i*n - h*j*mm);
	float resd = d *(e*j*o - e*k*n - f*i*o + f*k*mm + g*i*n - g*j*mm);
	
	return resa - resb + resc - resd;
		
}
//----------------------------------------------------------------------------
// calculates the transpose of this matrix
//
// Param:
//      
// Return:
//		Returns the transpose of this matrix
//----------------------------------------------------------------------------
void Matrix4::transpose()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = m[j][i];
		}
	}
}
//----------------------------------------------------------------------------
// computes a transformation matrix that corresponds to a camera viewing the 
// target from the source
//
// Param:
//      from: a vector holding the source point
//		target: a vector holding the tagets point
//		up: a vector describing the up direction
//
// Return:
//	
//----------------------------------------------------------------------------
void Matrix4::lookAt(Vector3 from, const Vector3 target, Vector3 up)
{
	Vector3 zaxis = from - target;
	zaxis.Normalise();
	Vector3 xaxis = zaxis.Cross(up);
	xaxis.Normalise();
	Vector3 yaxis = xaxis.Cross(zaxis);
	yaxis.Normalise();

	(*this)[0] = CastTo<Vector4>(xaxis);
	(*this)[1] = CastTo<Vector4>(yaxis);
	(*this)[2] = CastTo<Vector4>(zaxis);
	(*this)[3] = CastTo<Vector4>(from);

	m[3][3] = 1;
}
