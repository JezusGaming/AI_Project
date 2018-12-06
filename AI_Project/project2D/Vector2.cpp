#include "Vector2.h"
#include <math.h>
//--------------------------------------------------------------------------------
// 
// Comments are the same for Vector4.cpp the only change are the amount of vectors
//  
//--------------------------------------------------------------------------------
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	return result;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	return result;
}

Vector2 Vector2::operator/(const float& rhs)
{
	Vector2 result;
	result.x = x / rhs;
	result.y = y / rhs;
	return result;
}

Vector2 operator/(const float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	return result;
}

Vector2 Vector2::operator*(const float& rhs)
{
	Vector2 result;
	result.x = x * rhs;
	result.y = y * rhs;
	return result;
}

Vector2 operator*(const float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	return result;
}

float Vector2::Dot(Vector2& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y;
	return result;
}

float Vector2::Magnitude()
{
	float result;
	result = sqrtf((x * x) + (y * y));
	return result;
}

float Vector2::SqrtMagnitude()
{
	float result;
	result = ((x * x) + (y * y));
	return result;
}

void Vector2::Normalise()
{
	float Mag = Magnitude();
	if (Mag != 0)
	{
		x = x / Mag;
		y = y / Mag;
	}
}

Vector2 Vector2::Normalised(Vector2& data)
{
	Vector2 result;
	float Mag = data.Magnitude();
	if (Mag != 0)
	{
		result.x = x / Mag;
		result.y = y / Mag;
		return result;
	}
	return result;
}

Vector2 Vector2::operator-()
{
	Vector2 result;
	result.x = -x;
	result.y = -y;
	return result;
}

Vector2 Vector2::operator+=(const Vector2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2::operator float*()
{
	return &x;
}

float& Vector2::operator[](const int rhs)
{
	if (rhs == 0)
	{
		return x;
	}
	if (rhs == 1)
	{
		return y;
	}
	else
		return x;
}

Vector2 Vector2::min(const Vector2 & rhs)
{
	
	
	Vector2 result;
	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y < rhs.y)
		result.y = y;
	else 
		result.y = rhs.y;

	return result;
}

Vector2 Vector2::max(const Vector2 & rhs)
{
	Vector2 result;
	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	return result;
}

Vector2 Vector2::clamp(Vector2& min, Vector2& max)
{
	Vector2 result;
	result = this->min(min);
	result = result.max(max);
	return result;
}

Vector2 Vector2::lerp(Vector2 a, Vector2 b, float t)
{
	return (a + b) * t;
}

bool Vector2::operator<(const Vector2 & rhs)
{
	return (x < rhs.x && y < rhs.y);
}

bool Vector2::operator<=(const Vector2 & rhs)
{
	return (x <= rhs.x && y <= rhs.y);
}

bool Vector2::operator>(const Vector2 & rhs)
{
	return (x > rhs.x && y > rhs.y);
}

bool Vector2::operator>=(const Vector2 & rhs)
{
	return (x >= rhs.x && y >= rhs.y);
}

bool Vector2::operator==(const Vector2 & rhs)
{
	return (x == rhs.x && y == rhs.y);
}

bool Vector2::operator!=(const Vector2 & rhs)
{
	return (x != rhs.x && y != rhs.y);
}

float Vector2::distance(const Vector2 & p1, const Vector2 & p2)
{
	float diffx = p1.x - p2.x;
	float diffy = p1.y - p2.y;
	return sqrtf((diffx * diffx) + (diffy * diffy));
}

Vector2 Vector2::quadraticBezier(Vector2 a, Vector2 b, Vector2 c, float t)
{
	Vector2 mid1 = lerp(a, b, t);

	Vector2 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

Vector2 Vector2::hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t)
{
	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

float Vector2::CalculateDist(Vector2 pos1, Vector2 pos2)
{
	// Calculates distance and makes a new Vector2 to store it in
	Vector2 dist = pos1 - pos2;
	// Returns the magnitude of the distance
	return dist.Magnitude();
}

Vector2 Vector2::xx()
{
	Vector2 result;
	result.x = x;
	result.y = x;
	return result;
}

Vector2 Vector2::yx()
{
	Vector2 result;
	result.x = y;
	result.y = x;
	return result;
}

Vector2 Vector2::yy()
{
	Vector2 result;
	result.x = y;
	result.y = y;
	return result;
}

