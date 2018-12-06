//--------------------------------------------------------------------------------
// Class for Vector3
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

class Vector3
{
public:
	//----------------------------------------------------------------------------
	// Deafault Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3();

	//----------------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3(float x, float y, float z);

	//----------------------------------------------------------------------------
	// Deafault Destructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ ~Vector3();

	//----------------------------------------------------------------------------
	// Overloads the + operator to Add Vectors together
	//
	// Param:
	//      rhs: is the other value being added
	//
	// Return:
	//       Returns the result of added Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator+(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the - operator to subtract Vectors together
	//
	// Param:
	//      rhs: is the other value being subtracted
	//
	// Return:
	//       Returns the result of subtracted Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator-(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply float and Vector together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator*(const float& rhs);

	//----------------------------------------------------------------------------
	// Overloads the / operator to divide float and Vector together
	//
	// Param:
	//      rhs: is the other value being divided
	//
	// Return:
	//       Returns the result of divided Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator/(const float& rhs);

	//----------------------------------------------------------------------------
	// calculates the Dot Product of two vectors.
	//
	// Param:
	//      rhs: is the other vector being used
	//
	// Return:
	//       Returns the Dot Product
	//----------------------------------------------------------------------------
	/*MathDLL*/ float Dot(Vector3& rhs);

	//----------------------------------------------------------------------------
	// calculates the cross Product of two vectors.
	//
	// Param:
	//      rhs: is the other vector being used
	//
	// Return:
	//       Returns the cross Product
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 Cross(Vector3& rhs);

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
	/*MathDLL*/ Vector3 Normalised(Vector3& data);

	//----------------------------------------------------------------------------
	// Overloads the - operator to make a Vector negative
	//
	// Return:
	//       Returns the negative result
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator-();

	//----------------------------------------------------------------------------
	// Adds the value of an expression to the value of a variable and assigns
	// the result to the variable.
	//
	// Param:
	//      rhs: is the value being used
	// Return:
	//       Returns the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator+=(const Vector3& rhs);


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
	/*MathDLL*/ Vector3 min(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Checks which is greater rhs or lhs and makes it the max
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the higher value makeing it the max
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 max(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Clamps a value between a minimum float and maximum float value.
	//
	// Param:
	//      min: is the smallest number, can be calculated from the min function
	//		max: is the greatest number, can be calculated from the max function
	// Return:
	//       Returns a value between min and max
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 clamp(Vector3& min, Vector3& max);

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
	/*MathDLL*/ Vector3 lerp(Vector3 a, Vector3 b, float t);

	//----------------------------------------------------------------------------
	// Overloads the < operator to check which if rhs is greater then lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator<(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the <= operator to check if rhs is greater or equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator<=(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the > operator to check if lhs is greater then rhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator>(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the >= operator to check if lhs is greater or equal to rhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator>=(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the == operator to check if rhs is equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator==(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the != operator to check if rhs is not equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator!=(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Gets the distance between one point and the other
	//
	// Param:
	//      p1: is the first point
	//		p2: is the second point
	// Return:
	//       Returns the distance between the points
	//----------------------------------------------------------------------------
	/*MathDLL*/ float distance(const Vector3& p1, const Vector3& p2);

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
	/*MathDLL*/ Vector3 quadraticBezier(Vector3 a, Vector3 b, Vector3 c, float t);

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
	/*MathDLL*/ Vector3 hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t);
	 
	//------------------------------------------------------------------------------------------------------------
	// Swizzle
	// Changes what Vector4 x, y, z to another Vector4 x, y, z for example x = y
	// Return:
	//       Returns the swizzled vectors
	//------------------------------------------------------------------------------------------------------------
	/*MathDLL*/ Vector3 xxx();
	/*MathDLL*/ Vector3 xxy();
	/*MathDLL*/ Vector3 xxz();	
	/*MathDLL*/ Vector3 xyx();
	/*MathDLL*/ Vector3 xyy();
	/*MathDLL*/ Vector3 xyz();
	/*MathDLL*/ Vector3 xzx();
	/*MathDLL*/ Vector3 xzy();
	/*MathDLL*/ Vector3 xzz();
	 
	/*MathDLL*/ Vector3 yxx();
	/*MathDLL*/ Vector3 yxy();
	/*MathDLL*/ Vector3 yxz();
	/*MathDLL*/ Vector3 yyx();
	/*MathDLL*/ Vector3 yyy();
	/*MathDLL*/ Vector3 yyz();
	/*MathDLL*/ Vector3 yzx();
	/*MathDLL*/ Vector3 yzy();
	/*MathDLL*/ Vector3 yzz();
	 
	/*MathDLL*/ Vector3 zxx();
	/*MathDLL*/ Vector3 zxy();
	/*MathDLL*/ Vector3 zxz();
	/*MathDLL*/ Vector3 zyx();
	/*MathDLL*/ Vector3 zyy();
	/*MathDLL*/ Vector3 zyz();
	/*MathDLL*/ Vector3 zzx();
	/*MathDLL*/ Vector3 zzy();
	/*MathDLL*/ Vector3 zzz();

	float x;
	float y;
	float z;
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
/*MathDLL*/ Vector3 operator*(const float lhs, const Vector3& rhs);

//----------------------------------------------------------------------------
// Overloads the / operator to divide float & Vector together
//
// Param:
//      rhs: is the right hand side vector being divided
//      lhs: is the left hand side float being divided
// Return:
//       Returns the result of devided values
//----------------------------------------------------------------------------
/*MathDLL*/ Vector3 operator/(const float lhs, const Vector3& rhs);


