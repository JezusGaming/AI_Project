#include "Vector3.h"
#include <math.h>

//--------------------------------------------------------------------------------
// 
// Comments are the same for Vector4.cpp the only change are the amount of vectors
//  
//--------------------------------------------------------------------------------

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	return result;
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	return result;
}

Vector3 Vector3::operator/(const float& rhs)
{
	Vector3 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	return result;
}

Vector3 operator/(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	return result;
}


Vector3 Vector3::operator*(const float& rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	return result;
}

Vector3 operator*(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	return result;
}

float Vector3::Dot(Vector3& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

Vector3 Vector3::Cross(Vector3& rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y; 
	result.y = z * rhs.x - x * rhs.z; 
	result.z = x * rhs.y - y * rhs.x;
	return result;
}

float Vector3::Magnitude()
{
	float result;
	result = sqrtf(x * x + y * y + z * z);
	return result;
}

float Vector3::SqrtMagnitude()
{
	float result;
	result = ((x * x) + (y * y));
	return result;
}

void Vector3::Normalise()
{
	float Mag = Magnitude();
	x = x / Mag;
	y = y / Mag;
	z = z / Mag;
}

Vector3 Vector3::Normalised(Vector3& data)
{
	Vector3 result;
	float Mag = data.Magnitude();
	if (!Mag == 0)
	{
		result.x = x / Mag;
		result.y = y / Mag;
		result.z = z / Mag;
		return result;
	}
	return Vector3();
}

Vector3 Vector3::operator-()
{
	Vector3 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	return result;
}

Vector3 Vector3::operator+=(const Vector3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3::operator float*()
{
	return &x;
}

float & Vector3::operator[](const int rhs)
{
	if (rhs == 0)
	{
		return x;
	}
	if (rhs == 1)
	{
		return y;
	}
	if (rhs == 2)
	{
		return z;
	}
	else
		return x;
}
	
Vector3 Vector3::min(const Vector3 & rhs)
{
	Vector3 result;
	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z < rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	return result;
}
	
Vector3 Vector3::max(const Vector3 & rhs)
{
	Vector3 result;
	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z > rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	return result;
}

Vector3 Vector3::clamp(Vector3& min, Vector3& max)
{
	Vector3 result;
	result = this->min(min);
	result = result.max(max);
	return result;
}

Vector3 Vector3::lerp(Vector3 a, Vector3 b, float t)
{
	return (a + b) * t;
}

bool Vector3::operator<(const Vector3 & rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z);
}

bool Vector3::operator<=(const Vector3 & rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z);
}

bool Vector3::operator>(const Vector3 & rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z);
}

bool Vector3::operator>=(const Vector3 & rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z);
}

bool Vector3::operator==(const Vector3 & rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

bool Vector3::operator!=(const Vector3 & rhs)
{
	return (x != rhs.x && y != rhs.y && z != rhs.z);
}

float Vector3::distance(const Vector3 & p1, const Vector3 & p2)
{
	float diffx = p1.x - p2.x;
	float diffy = p1.y - p2.y;
	float diffz = p1.z - p2.z;
	return sqrtf((diffx * diffx) + (diffy * diffy) + (diffz * diffz));
}

Vector3 Vector3::quadraticBezier(Vector3 a, Vector3 b, Vector3 c, float t)
{
	Vector3 mid1 = lerp(a, b, t);

	Vector3 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

Vector3 Vector3::hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t)
{
	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

Vector3 Vector3::xxx()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::xxy()
{			   
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = y;
	return result;
}			   
Vector3 Vector3::xxz()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = z;
	return result;
}			   
Vector3 Vector3::xyx()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = x;
	return result;
}			   
Vector3 Vector3::xyy()
{	
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = y;
	return result;
}			   
Vector3 Vector3::xyz()
{	
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}			   
Vector3 Vector3::xzx()
{	
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = x;
	return result;
}			   
Vector3 Vector3::xzy()
{	
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = y;
	return result;
}			   
Vector3 Vector3::xzz()
{	
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = z;
	return result;
}			   
					 
Vector3 Vector3::yxx()
{	
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = x;
	return result;
}			   
Vector3 Vector3::yxy()
{	
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = y;
	return result;
}			  
Vector3 Vector3::yxz()
{	
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = z;
	return result;
}			   
Vector3 Vector3::yyx()
{	
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = x;
	return result;
}			   
Vector3 Vector3::yyy()
{	
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = y;
	return result;
}			   
Vector3 Vector3::yyz()
{	
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = z;
	return result;
}			   
Vector3 Vector3::yzx()
{	
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = x;
	return result;
}			   
Vector3 Vector3::yzy()
{	
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = y;
	return result;
}			   
Vector3 Vector3::yzz()
{	
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = z;
	return result;
}			   
				 
Vector3 Vector3::zxx()
{	
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = x;
	return result;
}	
Vector3 Vector3::zxy()
{	
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = y;
	return result;
}			   
Vector3 Vector3::zxz()
{	
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = z;
	return result;
}			   
Vector3 Vector3::zyx()
{	
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = x;
	return result;
}			   
Vector3 Vector3::zyy()
{	
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = y;
	return result;
}			   
Vector3 Vector3::zyz()
{	
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = z;
	return result;
}			   
Vector3 Vector3::zzx()
{	
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = x;
	return result;
}			   
Vector3 Vector3::zzy()
{	
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = y;
	return result;
}			   
Vector3 Vector3::zzz()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = z;
	return result;
}

