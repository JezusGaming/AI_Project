#include "Vector4.h"
#include <math.h>

//--------------------------------------------------------------------------------
//
// All these comments apply for vector3 and vector2 cpp files as all functions are
// doing the same thing
//  
//--------------------------------------------------------------------------------

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()
{
}

//----------------------------------------------------------------------------
// Overloads the + operator to Add Vectors together
//
// Param:
//      rhs: is the other value being added
//
// Return:
//       Returns the result of added Vectors
//----------------------------------------------------------------------------
Vector4 Vector4::operator+(const Vector4& rhs)
{
	// creates a Vector which holds the answer of adding 
	// one vectors x, y, z, w to the other and returns the answer
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;
	return result;
}
//----------------------------------------------------------------------------
// Overloads the - operator to subtract Vectors together
//
// Param:
//      rhs: is the other value being subtracted
//
// Return:
//       Returns the result of subtracting Vectors
//----------------------------------------------------------------------------
Vector4 Vector4::operator-(const Vector4& rhs)
{
	// creates a Vector which holds the answer of subtracting
	// one vectors x, y, z, w to the other and returns the answer
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;
	return result;
}
//----------------------------------------------------------------------------
// Overloads the / operator to divide Vectors together
//
// Param:
//      rhs: is the other value being divided
//
// Return:
//       Returns the result of devided Vectors
//----------------------------------------------------------------------------
Vector4 Vector4::operator/(const float& rhs)
{
	// creates a Vector which holds the answer of divideing
	// one vectors x, y, z, w to the other and returns the answer
	Vector4 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	result.w = w / rhs;
	return result;
}
//----------------------------------------------------------------------------
// Overloads the / operator to divide float & Vector together
//
// Param:
//      rhs: is the right hand side vector being divided
//      lhs: is the left hand side float being divided
// Return:
//       Returns the result of devided values
//----------------------------------------------------------------------------
Vector4 operator/(const float lhs, const Vector4& rhs)
{
	// creates a Vector which holds the answer of divideing
	// float by a vector and returns the answer
	Vector4 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	result.w = lhs / rhs.w;
	return result;
}
//----------------------------------------------------------------------------
// Overloads the * operator to multiply float and Vector together
//
// Param:
//      rhs: is the other value being multiplied
//
// Return:
//       Returns the result of multiplyed values
//----------------------------------------------------------------------------
Vector4 Vector4::operator*(const float& rhs)
{
	// creates a Vector which holds the answer of multiplying
	// a float by a vector and returns the answer
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;
	return result;
}
//----------------------------------------------------------------------------
// Overloads the * operator to multiply float & Vector together
//
// Param:
//      rhs: is the right hand side vector being multiplied
//      lhs: is the left hand side float being multiplied
// Return:
//       Returns the result of devided values
//----------------------------------------------------------------------------
Vector4 operator*(const float lhs, const Vector4& rhs)
{
	// creates a Vector which holds the answer of multiplying
	// float by a vector and returns the answer
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;
	return result;
}
//----------------------------------------------------------------------------
// calculates the Dot Product of two vectors.
//
// Param:
//      rhs: is the other vector being used
//
// Return:
//       Returns the Dot Product
//----------------------------------------------------------------------------
float Vector4::Dot(Vector4& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}
//----------------------------------------------------------------------------
// calculates the cross Product of two vectors.
//
// Param:
//      rhs: is the other vector being used
//
// Return:
//       Returns the cross Product
//----------------------------------------------------------------------------
Vector4 Vector4::Cross(Vector4& rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;
	return result;
}
//----------------------------------------------------------------------------
// calculates the magnitude of vectors.
//
// Return:
//       Returns the length of this vector
//----------------------------------------------------------------------------
float Vector4::Magnitude()
{
	float result;
	result = sqrtf(x * x + y * y + z * z + w * w);
	return result;
}
//----------------------------------------------------------------------------
// calculates the magnitude of vectors.
//
// Calculating the squared magnitude instead of the magnitude is much faster
//
// Return:
//       Returns the length of this vector
//----------------------------------------------------------------------------
float Vector4::SqrtMagnitude()
{
	float result;
	result = (x * x + y * y + z * z + w * w);
	return result;
}
//----------------------------------------------------------------------------
// Makes this vector have a magnitude of 1.
//
// Note that this function will change the current vector
//
// Return:
//       Returns the vector normalised but it will be changed
//----------------------------------------------------------------------------
void Vector4::Normalise()
{
	float Mag = Magnitude();
	x = x / Mag;
	y = y / Mag;
	z = z / Mag;
	w = w / Mag;
}
//----------------------------------------------------------------------------
// Returns this vector with a magnitude of 1
//
// Note that the current vector is unchanged and a new normalized vector is returned
//
// Return:
//       Returns the vector normanlised unchanged
//----------------------------------------------------------------------------
Vector4 Vector4::Normalised(Vector4& data)
{
	Vector4 result;
	float Mag = data.Magnitude();
	if (!Mag == 0)
	{
		result.x = x / Mag;
		result.y = y / Mag;
		result.z = z / Mag;
		result.w = w / Mag;
		return result;
	}
	return Vector4();
}
//----------------------------------------------------------------------------
// Overloads the - operator to make a Vector negative
//
// Return:
//       Returns the negative result
//----------------------------------------------------------------------------
Vector4 Vector4::operator-()
{
	// sets x, y, z, w all negative
	Vector4 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	result.w = -w;
	return result;
}
//----------------------------------------------------------------------------
// Adds the value of an expression to the value of a variable and assigns
// the result to the variable.
//
// Param:
//      rhs: is the value being used
// Return:
//       Returns the result
//----------------------------------------------------------------------------
Vector4 Vector4::operator+=(const Vector4 & rhs)
{
	// adds rhsx to x and the same for y, z, and w
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

Vector4::operator float*()
{
	return &x;
}

float & Vector4::operator[](const int rhs)
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
	if (rhs == 3)
	{
		return w;
	}
	else
		return x;
}
//----------------------------------------------------------------------------
// Checks which is smaller rhs or lhs and makes it the min
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the lower value makeing it the min
//----------------------------------------------------------------------------
Vector4 Vector4::min(const Vector4 & rhs)
{
	// it checks which is smaller x or rhsx if x is it makes x the min if not
	// it makes rhsx the min
	Vector4 result;
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

	if (w < rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}
//----------------------------------------------------------------------------
// Checks which is greater rhs or lhs and makes it the max
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the higher value makeing it the max
//----------------------------------------------------------------------------
Vector4 Vector4::max(const Vector4 & rhs)
{
	// it checks which is greater x or rhsx if x is it makes x the max if not
	// it makes rhsx the max
	Vector4 result;
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

	if (w > rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}
//----------------------------------------------------------------------------
// Clamps a value between a minimum float and maximum float value.
//
// Param:
//      min: is the smallest number, can be calculated from the min function
//		max: is the greatest number, can be calculated from the max function
// Return:
//       Returns a value between min and max
//----------------------------------------------------------------------------
Vector4 Vector4::clamp(Vector4& min, Vector4& max)
{
	//Clamps the value to be between min and max
	Vector4 result;
	result = this->min(min);
	result = result.max(max);
	return result;
}
//----------------------------------------------------------------------------
// Interpolates between the vectors a and b by the interpolant t.
//
// Param:
//      a: is one vector being used to lerp
//		b: is the other vector being used
//		t: is the amount being lerped
//
// Return:
//       When t = 0 returns a. When t = 1 returns b. When t = 0.5 returns the 
//		 point midway
//----------------------------------------------------------------------------
Vector4 Vector4::lerp(Vector4 a, Vector4 b, float t)
{
	// returns the answer of the equation
	return (a + b) * t;
}
//----------------------------------------------------------------------------
// Overloads the < operator to check which if rhs is greater then lhs
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the result true or false depending on the result
//----------------------------------------------------------------------------
bool Vector4::operator<(const Vector4 & rhs)
{
	// returns true or false depending if the statement is true
	return (x < rhs.x && y < rhs.y && z < rhs.z && w < rhs.w);
}
//----------------------------------------------------------------------------
// Overloads the <= operator to check if rhs is greater or equal to lhs
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the result true or false depending on the result
//----------------------------------------------------------------------------
bool Vector4::operator<=(const Vector4 & rhs)
{
	// returns true or false depending if the statement is true
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z && w <= rhs.w);
}
//----------------------------------------------------------------------------
// Overloads the > operator to check if lhs is greater then rhs
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the result true or false depending on the result
//----------------------------------------------------------------------------
bool Vector4::operator>(const Vector4 & rhs)
{
	// returns true or false depending if the statement is true
	return (x > rhs.x && y > rhs.y && z > rhs.z && w > rhs.w);
}
//----------------------------------------------------------------------------
// Overloads the >= operator to check if lhs is greater or equal to rhs
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the result true or false depending on the result
//----------------------------------------------------------------------------
bool Vector4::operator>=(const Vector4 & rhs)
{
	// returns true or false depending if the statement is true
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z && w >= rhs.w);
}
//----------------------------------------------------------------------------
// Overloads the == operator to check if rhs is equal to lhs
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the result true or false depending on the result
//----------------------------------------------------------------------------
bool Vector4::operator==(const Vector4 & rhs)
{
	// returns true or false depending if the statement is true
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}
//----------------------------------------------------------------------------
// Overloads the != operator to check if rhs is not equal to lhs
//
// Param:
//      rhs: is the other value being used
//
// Return:
//       Returns the result true or false depending on the result
//----------------------------------------------------------------------------
bool Vector4::operator!=(const Vector4 & rhs)
{
	// returns true or false depending if the statement is true
	return (x != rhs.x && y != rhs.y && z != rhs.z && w != rhs.w);
}
//----------------------------------------------------------------------------
// Gets the distance between one point and the other
//
// Param:
//      p1: is the first point
//		p2: is the second point
// Return:
//       Returns the distance between the points
//----------------------------------------------------------------------------
float Vector4::distance(const Vector4 & p1, const Vector4 & p2)
{
	float diffx = p1.x - p2.x;
	float diffy = p1.y - p2.y;
	float diffz = p1.z - p2.z;
	float diffw = p1.w - p2.w;
	return sqrtf((diffx * diffx) + (diffy * diffy) + (diffz * diffz) + (diffw * diffw));
}
//----------------------------------------------------------------------------
// creates a bezier curve
//
// Param:
//	    a: is one vector being used to lerp
//		b: is the other vector being used
//		t: is the amount being lerped
//
// Return:
//       Returns a curved line based on the lerp
//----------------------------------------------------------------------------
Vector4 Vector4::quadraticBezier(Vector4 a, Vector4 b, Vector4 c, float t)
{
	Vector4 mid1 = lerp(a, b, t);

	Vector4 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}
//----------------------------------------------------------------------------
// creates a hermiteCurve which can be controlled with tangents to curve
//
// Param:
//      p0: is the start point 
//		p1: is the end point of the line 
//		t0: controls the curve for p0
//		t1: controls the curve for p0
//		t: is the amount being lerped
// Return:
//       Returns a curved line based on the tangents and lerp
//----------------------------------------------------------------------------
Vector4 Vector4::hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t)
{
	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

//x

Vector4 Vector4::xwww()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::xwwx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::xwwy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::xwwz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::xwxw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::xwxx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::xwxy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::xwxz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::xwyw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::xwyx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::xwyy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::xwyz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::xwzw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::xwzx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::xwzy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::xwzz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::xxww()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::xxwx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::xxwy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::xxwz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::xxxw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::xxxx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::xxxy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::xxxz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::xxyw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::xxyx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::xxyy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::xxyz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::xxzw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::xxzx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::xxzy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::xxzz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::xyww()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::xywx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::xywy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::xywz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::xyxw()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::xyxx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::xyxy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::xyxz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::xyyw()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::xyyx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::xyyy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::xyyz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::xyzx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::xyzy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::xyzz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::xzww()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::xzwx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::xzwy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::xzwz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::xzxw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::xzxx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::xzxy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::xzxz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::xzyw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::xzyx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::xzyy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::xzyz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::xzzw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::xzzx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::xzzy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::xzzz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}
				
//y

Vector4 Vector4::ywww()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::ywwx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::ywwy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::ywwz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::ywxw()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::ywxx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::ywxy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::ywxz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::ywyw()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::ywyx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::ywyy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::ywyz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::ywzw()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::ywzx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::ywzy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::ywzz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::yxww()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::yxwx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::yxwy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::yxwz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::yxxw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::yxxx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::yxxy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::yxxz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::yxyw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::yxyx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::yxyy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::yxyz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::yxzw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::yxzx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::yxzy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::yxzz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::yyww()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::yywx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::yywy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::yywz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::yyxw()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::yyxx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::yyxy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::yyxz()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::yyyw()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::yyyx()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::yyyy()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::yyyz()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::yyzw()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::yyzx()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::yyzy()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::yyzz()	
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::yzww()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::yzwx()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::yzwy()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::yzwz()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::yzxw()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::yzxx()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::yzxy()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::yzxz()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::yzyw()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::yzyx()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::yzyy()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::yzyz()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::yzzw()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::yzzx()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::yzzy()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::yzzz()	
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}
			
//z

Vector4 Vector4::zwww()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::zwwx()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::zwwy()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::zwwz()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::zwxw()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::zwxx()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::zwxy()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::zwxz()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::zwyw()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::zwyx()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::zwyy()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::zwyz()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::zwzw()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::zwzx()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::zwzy()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::zwzz()	
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::zxww()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::zxwx()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::zxwy()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::zxwz()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::zxxw()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::zxxx()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::zxxy()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::zxxz()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::zxyw()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::zxyx()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::zxyy()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::zxyz()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::zxzw()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::zxzx()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::zxzy()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::zxzz()	
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::zyww()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::zywx()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::zywy()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::zywz()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::zyxw()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::zyxx()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::zyxy()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::zyxz()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::zyyw()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::zyyx()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::zyyy()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::zyyz()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::zyzw()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::zyzx()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::zyzy()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::zyzz()	
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::zzww()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::zzwx()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::zzwy()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::zzwz()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::zzxw()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::zzxx()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::zzxy()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::zzxz()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::zzyw()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::zzyx()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::zzyy()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::zzyz()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::zzzw()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::zzzx()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::zzzy()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::zzzz()	
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}
	
//w

Vector4 Vector4::wwww()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::wwwx()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::wwwy()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::wwwz()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::wwxw()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::wwxx()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::wwxy()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::wwxz()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::wwyw()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::wwyx()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::wwyy()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::wwyz()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::wwzw()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::wwzx()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::wwzy()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::wwzz()	
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::wxww()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::wxwx()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::wxwy()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::wxwz()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::wxxw()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::wxxx()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::wxxy()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::wxxz()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::wxyw()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::wxyx()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::wxyy()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::wxyz()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::wxzw()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::wxzx()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::wxzy()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::wxzz()	
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::wyww()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::wywx()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::wywy()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::wywz()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::wyxw()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::wyxx()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::wyxy()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::wyxz()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::wyyw()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::wyyx()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::wyyy()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::wyyz()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::wyzw()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::wyzx()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::wyzy()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::wyzz()	
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}
Vector4 Vector4::wzww()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}
Vector4 Vector4::wzwx()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}
Vector4 Vector4::wzwy()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}
Vector4 Vector4::wzwz()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}
Vector4 Vector4::wzxw()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}
Vector4 Vector4::wzxx()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}
Vector4 Vector4::wzxy()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}
Vector4 Vector4::wzxz()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}
Vector4 Vector4::wzyw()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}
Vector4 Vector4::wzyx()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}
Vector4 Vector4::wzyy()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}
Vector4 Vector4::wzyz()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}
Vector4 Vector4::wzzw()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}
Vector4 Vector4::wzzx()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}
Vector4 Vector4::wzzy()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}
Vector4 Vector4::wzzz()	
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}