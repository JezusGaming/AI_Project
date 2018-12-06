//--------------------------------------------------------------------------------
// Class for Vector2
// Which is both static and dynamic libary and replaces __declspec with /*MathDLL*/
//--------------------------------------------------------------------------------
//#ifdef Static
//	#define /*MathDLL*/
//#else
//	#ifdef DLL
//		#define /*MathDLL*/ __declspec(dllexport)
//	#else 
//		#define /*MathDLL*/ __declspec(dllimport)
//	#endif
//#endif
#pragma once

class Vector2
{
public:

	//----------------------------------------------------------------------------
	// Deafault Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2();

	//----------------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2(float x, float y);

	//----------------------------------------------------------------------------
	// Deafault Destructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ ~Vector2();
	 

	//----------------------------------------------------------------------------
	// Overloads the + operator to Add Vectors together
	//
	// Param:
	//      rhs: is the other value being added
	//
	// Return:
	//       Returns the result of added Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator+(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the - operator to subtract Vectors together
	//
	// Param:
	//      rhs: is the other value being subtracted
	//
	// Return:
	//       Returns the result of subtracted Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator-(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply float and Vector together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator*(const float& rhs);

	//----------------------------------------------------------------------------
	// Overloads the / operator to divide float and Vector together
	//
	// Param:
	//      rhs: is the other value being divided
	//
	// Return:
	//       Returns the result of divided Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator/(const float& rhs);
	
	//----------------------------------------------------------------------------
	// calculates the Dot Product of two vectors.
	//
	// Param:
	//      rhs: is the other vector being used
	//
	// Return:
	//       Returns the Dot Product
	//----------------------------------------------------------------------------
	/*MathDLL*/ float Dot(Vector2& rhs);

	//----------------------------------------------------------------------------
	// calculates the magnitude of vectors.
	//
	// Return:
	//       Returns the length of this vector
	//----------------------------------------------------------------------------
	/*MathDLL*/ float Magnitude();

	//----------------------------------------------------------------------------
	// calculates the magnitude of vectors.
	//
	// Calculating the squared magnitude instead of the magnitude is much faster
	//
	// Return:
	//       Returns the length of this vector
	//----------------------------------------------------------------------------
	/*MathDLL*/ float SqrtMagnitude();

	//----------------------------------------------------------------------------
	// Makes this vector have a magnitude of 1.
	//
	// Note that this function will change the current vector
	//
	// Return:
	//       Returns the vector normalised but it will be changed
	//----------------------------------------------------------------------------
	/*MathDLL*/ void Normalise();

	//----------------------------------------------------------------------------
	// Returns this vector with a magnitude of 1
	//
	// Note that the current vector is unchanged and a new normalized vector is returned
	//
	// Return:
	//       Returns the vector normanlised unchanged
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 Normalised(Vector2& data);

	//----------------------------------------------------------------------------
	// Overloads the - operator to make a Vector negative
	//
	// Return:
	//       Returns the negative result
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator-();

	//----------------------------------------------------------------------------
	// Adds the value of an expression to the value of a variable and assigns
	// the result to the variable.
	//
	// Param:
	//      rhs: is the value being used
	// Return:
	//       Returns the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator+=(const Vector2& rhs);


	/*MathDLL*/ operator float*();


	/*MathDLL*/ float& operator[](const int rhs);

	//----------------------------------------------------------------------------
	// Checks which is smaller rhs or lhs and makes it the min
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the lower value makeing it the min
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 min(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Checks which is greater rhs or lhs and makes it the max
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the higher value makeing it the max
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 max(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Clamps a value between a minimum float and maximum float value.
	//
	// Param:
	//      min: is the smallest number, can be calculated from the min function
	//		max: is the greatest number, can be calculated from the max function
	// Return:
	//       Returns a value between min and max
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 clamp(Vector2& min, Vector2& max);

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
	/*MathDLL*/ Vector2 lerp(Vector2 a, Vector2 b, float t);

	//----------------------------------------------------------------------------
	// Overloads the < operator to check which if rhs is greater then lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator<(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the <= operator to check if rhs is greater or equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator<=(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the > operator to check if lhs is greater then rhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator>(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the >= operator to check if lhs is greater or equal to rhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator>=(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the == operator to check if rhs is equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator==(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the != operator to check if rhs is not equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator!=(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Gets the distance between one point and the other
	//
	// Param:
	//      p1: is the first point
	//		p2: is the second point
	// Return:
	//       Returns the distance between the points
	//----------------------------------------------------------------------------
	/*MathDLL*/ float distance(const Vector2& p1, const Vector2& p2);

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
	/*MathDLL*/ Vector2 quadraticBezier(Vector2 a, Vector2 b, Vector2 c, float t);

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
	/*MathDLL*/ Vector2 hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);

	float CalculateDist(Vector2 pos1, Vector2 pos2);
	 
	//------------------------------------------------------------------------
	// Swizzle
	// Changes what Vector4 x, y to another Vector4 x, y for example x = y
	// Return:
	//       Returns the swizzled vectors
	//------------------------------------------------------------------------
	/*MathDLL*/ Vector2 xx();
	/*MathDLL*/ Vector2 yx();
	/*MathDLL*/ Vector2 yy();
	 
	float x;
	float y;
};

//----------------------------------------------------------------------------
// Overloads the * operator to multiply float & Vector together
//
// Param:
//      rhs: is the right hand side vector being multiplied
//      lhs: is the left hand side float being multiplied
// Return:
//       Returns the result of multiplied values
//----------------------------------------------------------------------------
/*MathDLL*/ Vector2 operator*(const float lhs, const Vector2& rhs);

//----------------------------------------------------------------------------
// Overloads the / operator to divide float & Vector together
//
// Param:
//      rhs: is the right hand side vector being divided
//      lhs: is the left hand side float being divided
// Return:
//       Returns the result of devided values
//----------------------------------------------------------------------------
/*MathDLL*/ Vector2 operator/(const float lhs, const Vector2& rhs);
