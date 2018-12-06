//--------------------------------------------------------------------------------
// Class for Vector4
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

class Vector4
{
public:
	//----------------------------------------------------------------------------
	// Deafault Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4();

	//----------------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4(float x, float y, float z, float w);

	//----------------------------------------------------------------------------
	// Deafault Destructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ ~Vector4();

	//----------------------------------------------------------------------------
	// Overloads the + operator to Add Vectors together
	//
	// Param:
	//      rhs: is the other value being added
	//
	// Return:
	//       Returns the result of added Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator+(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the - operator to subtract Vectors together
	//
	// Param:
	//      rhs: is the other value being subtracted
	//
	// Return:
	//       Returns the result of subtracted Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator-(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply float and Vector together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator*(const float& rhs);

	//----------------------------------------------------------------------------
	// Overloads the / operator to divide float and Vector together
	//
	// Param:
	//      rhs: is the other value being divided
	//
	// Return:
	//       Returns the result of divided Vectors
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator/(const float& rhs);

	//----------------------------------------------------------------------------
	// calculates the Dot Product of two vectors.
	//
	// Param:
	//      rhs: is the other vector being used
	//
	// Return:
	//       Returns the Dot Product
	//----------------------------------------------------------------------------
	/*MathDLL*/ float Dot(Vector4& rhs);

	//----------------------------------------------------------------------------
	// calculates the cross Product of two vectors.
	//
	// Param:
	//      rhs: is the other vector being used
	//
	// Return:
	//       Returns the cross Product
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 Cross(Vector4& rhs);

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
	/*MathDLL*/ Vector4 Normalised(Vector4& data);

	//----------------------------------------------------------------------------
	// Overloads the - operator to make a Vector negative
	//
	// Return:
	//       Returns the negative result
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator-();
	
	//----------------------------------------------------------------------------
	// Adds the value of an expression to the value of a variable and assigns
	// the result to the variable.
	//
	// Param:
	//      rhs: is the value being used
	// Return:
	//       Returns the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator+=(const Vector4& rhs);

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
	/*MathDLL*/ Vector4 min(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Checks which is greater rhs or lhs and makes it the max
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the higher value makeing it the max
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 max(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Clamps a value between a minimum float and maximum float value.
	//
	// Param:
	//      min: is the smallest number, can be calculated from the min function
	//		max: is the greatest number, can be calculated from the max function
	// Return:
	//       Returns a value between min and max
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 clamp(Vector4& min, Vector4& max);
	
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
	/*MathDLL*/ Vector4 lerp(Vector4 a, Vector4 b, float t);

	//----------------------------------------------------------------------------
	// Overloads the < operator to check which if rhs is greater then lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator<(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the <= operator to check if rhs is greater or equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator<=(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the > operator to check if lhs is greater then rhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator>(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the >= operator to check if lhs is greater or equal to rhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator>=(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the == operator to check if rhs is equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator==(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the != operator to check if rhs is not equal to lhs
	//
	// Param:
	//      rhs: is the other value being used
	//
	// Return:
	//       Returns the result true or false depending on the result
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool operator!=(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Gets the distance between one point and the other
	//
	// Param:
	//      p1: is the first point
	//		p2: is the second point
	// Return:
	//       Returns the distance between the points
	//----------------------------------------------------------------------------
	/*MathDLL*/ float distance(const Vector4& p1, const Vector4& p2);

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
	/*MathDLL*/ Vector4 quadraticBezier(Vector4 a, Vector4 b, Vector4 c, float t);

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
	/*MathDLL*/ Vector4 hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t);

	//------------------------------------------------------------------------------------------------------------
	// Swizzle
	// Changes what Vector4 x, y, z, w to another Vector4 x, y, z, w for example x = y
	// Return:
	//       Returns the swizzled vectors
	//------------------------------------------------------------------------------------------------------------
	/*MathDLL*/ Vector4 xwww();
	/*MathDLL*/ Vector4 xwwx();
	/*MathDLL*/ Vector4 xwwy();
	/*MathDLL*/ Vector4 xwwz();
	/*MathDLL*/ Vector4 xwxw();
	/*MathDLL*/ Vector4 xwxx();
	/*MathDLL*/ Vector4 xwxy();
	/*MathDLL*/ Vector4 xwxz();
	/*MathDLL*/ Vector4 xwyw();
	/*MathDLL*/ Vector4 xwyx();
	/*MathDLL*/ Vector4 xwyy();
	/*MathDLL*/ Vector4 xwyz();
	/*MathDLL*/ Vector4 xwzw();
	/*MathDLL*/ Vector4 xwzx();
	/*MathDLL*/ Vector4 xwzy();
	/*MathDLL*/ Vector4 xwzz();
	/*MathDLL*/ Vector4 xxww();
	/*MathDLL*/ Vector4 xxwx();
	/*MathDLL*/ Vector4 xxwy();
	/*MathDLL*/ Vector4 xxwz();
	/*MathDLL*/ Vector4 xxxw();
	/*MathDLL*/ Vector4 xxxx();
	/*MathDLL*/ Vector4 xxxy();
	/*MathDLL*/ Vector4 xxxz();
	/*MathDLL*/ Vector4 xxyw();
	/*MathDLL*/ Vector4 xxyx();
	/*MathDLL*/ Vector4 xxyy();
	/*MathDLL*/ Vector4 xxyz();
	/*MathDLL*/ Vector4 xxzw();
	/*MathDLL*/ Vector4 xxzx();
	/*MathDLL*/ Vector4 xxzy();
	/*MathDLL*/ Vector4 xxzz();
	/*MathDLL*/ Vector4 xyww();
	/*MathDLL*/ Vector4 xywx();
	/*MathDLL*/ Vector4 xywy();
	/*MathDLL*/ Vector4 xywz();
	/*MathDLL*/ Vector4 xyxw();
	/*MathDLL*/ Vector4 xyxx();
	/*MathDLL*/ Vector4 xyxy();
	/*MathDLL*/ Vector4 xyxz();
	/*MathDLL*/ Vector4 xyyw();
	/*MathDLL*/ Vector4 xyyx();
	/*MathDLL*/ Vector4 xyyy();
	/*MathDLL*/ Vector4 xyyz();
	/*MathDLL*/ Vector4 xyzx();
	/*MathDLL*/ Vector4 xyzy();
	/*MathDLL*/ Vector4 xyzz();
	/*MathDLL*/ Vector4 xzww();
	/*MathDLL*/ Vector4 xzwx();
	/*MathDLL*/ Vector4 xzwy();
	/*MathDLL*/ Vector4 xzwz();
	/*MathDLL*/ Vector4 xzxw();
	/*MathDLL*/ Vector4 xzxx();
	/*MathDLL*/ Vector4 xzxy();
	/*MathDLL*/ Vector4 xzxz();
	/*MathDLL*/ Vector4 xzyw();
	/*MathDLL*/ Vector4 xzyx();
	/*MathDLL*/ Vector4 xzyy();
	/*MathDLL*/ Vector4 xzyz();
	/*MathDLL*/ Vector4 xzzw();
	/*MathDLL*/ Vector4 xzzx();
	/*MathDLL*/ Vector4 xzzy();
	/*MathDLL*/ Vector4 xzzz();
	 
	/*MathDLL*/ Vector4 ywww();
	/*MathDLL*/ Vector4 ywwx();
	/*MathDLL*/ Vector4 ywwy();
	/*MathDLL*/ Vector4 ywwz();
	/*MathDLL*/ Vector4 ywxw();
	/*MathDLL*/ Vector4 ywxx();
	/*MathDLL*/ Vector4 ywxy();
	/*MathDLL*/ Vector4 ywxz();
	/*MathDLL*/ Vector4 ywyw();
	/*MathDLL*/ Vector4 ywyx();
	/*MathDLL*/ Vector4 ywyy();
	/*MathDLL*/ Vector4 ywyz();
	/*MathDLL*/ Vector4 ywzw();
	/*MathDLL*/ Vector4 ywzx();
	/*MathDLL*/ Vector4 ywzy();
	/*MathDLL*/ Vector4 ywzz();
	/*MathDLL*/ Vector4 yxww();
	/*MathDLL*/ Vector4 yxwx();
	/*MathDLL*/ Vector4 yxwy();
	/*MathDLL*/ Vector4 yxwz();
	/*MathDLL*/ Vector4 yxxw();
	/*MathDLL*/ Vector4 yxxx();
	/*MathDLL*/ Vector4 yxxy();
	/*MathDLL*/ Vector4 yxxz();
	/*MathDLL*/ Vector4 yxyw();
	/*MathDLL*/ Vector4 yxyx();
	/*MathDLL*/ Vector4 yxyy();
	/*MathDLL*/ Vector4 yxyz();
	/*MathDLL*/ Vector4 yxzw();
	/*MathDLL*/ Vector4 yxzx();
	/*MathDLL*/ Vector4 yxzy();
	/*MathDLL*/ Vector4 yxzz();
	/*MathDLL*/ Vector4 yyww();
	/*MathDLL*/ Vector4 yywx();
	/*MathDLL*/ Vector4 yywy();
	/*MathDLL*/ Vector4 yywz();
	/*MathDLL*/ Vector4 yyxw();
	/*MathDLL*/ Vector4 yyxx();
	/*MathDLL*/ Vector4 yyxy();
	/*MathDLL*/ Vector4 yyxz();
	/*MathDLL*/ Vector4 yyyw();
	/*MathDLL*/ Vector4 yyyx();
	/*MathDLL*/ Vector4 yyyy();
	/*MathDLL*/ Vector4 yyyz();
	/*MathDLL*/ Vector4 yyzw();
	/*MathDLL*/ Vector4 yyzx();
	/*MathDLL*/ Vector4 yyzy();
	/*MathDLL*/ Vector4 yyzz();
	/*MathDLL*/ Vector4 yzww();
	/*MathDLL*/ Vector4 yzwx();
	/*MathDLL*/ Vector4 yzwy();
	/*MathDLL*/ Vector4 yzwz();
	/*MathDLL*/ Vector4 yzxw();
	/*MathDLL*/ Vector4 yzxx();
	/*MathDLL*/ Vector4 yzxy();
	/*MathDLL*/ Vector4 yzxz();
	/*MathDLL*/ Vector4 yzyw();
	/*MathDLL*/ Vector4 yzyx();
	/*MathDLL*/ Vector4 yzyy();
	/*MathDLL*/ Vector4 yzyz();
	/*MathDLL*/ Vector4 yzzw();
	/*MathDLL*/ Vector4 yzzx();
	/*MathDLL*/ Vector4 yzzy();
	/*MathDLL*/ Vector4 yzzz();
	 
	/*MathDLL*/ Vector4 zwww();
	/*MathDLL*/ Vector4 zwwx();
	/*MathDLL*/ Vector4 zwwy();
	/*MathDLL*/ Vector4 zwwz();
	/*MathDLL*/ Vector4 zwxw();
	/*MathDLL*/ Vector4 zwxx();
	/*MathDLL*/ Vector4 zwxy();
	/*MathDLL*/ Vector4 zwxz();
	/*MathDLL*/ Vector4 zwyw();
	/*MathDLL*/ Vector4 zwyx();
	/*MathDLL*/ Vector4 zwyy();
	/*MathDLL*/ Vector4 zwyz();
	/*MathDLL*/ Vector4 zwzw();
	/*MathDLL*/ Vector4 zwzx();
	/*MathDLL*/ Vector4 zwzy();
	/*MathDLL*/ Vector4 zwzz();
	/*MathDLL*/ Vector4 zxww();
	/*MathDLL*/ Vector4 zxwx();
	/*MathDLL*/ Vector4 zxwy();
	/*MathDLL*/ Vector4 zxwz();
	/*MathDLL*/ Vector4 zxxw();
	/*MathDLL*/ Vector4 zxxx();
	/*MathDLL*/ Vector4 zxxy();
	/*MathDLL*/ Vector4 zxxz();
	/*MathDLL*/ Vector4 zxyw();
	/*MathDLL*/ Vector4 zxyx();
	/*MathDLL*/ Vector4 zxyy();
	/*MathDLL*/ Vector4 zxyz();
	/*MathDLL*/ Vector4 zxzw();
	/*MathDLL*/ Vector4 zxzx();
	/*MathDLL*/ Vector4 zxzy();
	/*MathDLL*/ Vector4 zxzz();
	/*MathDLL*/ Vector4 zyww();
	/*MathDLL*/ Vector4 zywx();
	/*MathDLL*/ Vector4 zywy();
	/*MathDLL*/ Vector4 zywz();
	/*MathDLL*/ Vector4 zyxw();
	/*MathDLL*/ Vector4 zyxx();
	/*MathDLL*/ Vector4 zyxy();
	/*MathDLL*/ Vector4 zyxz();
	/*MathDLL*/ Vector4 zyyw();
	/*MathDLL*/ Vector4 zyyx();
	/*MathDLL*/ Vector4 zyyy();
	/*MathDLL*/ Vector4 zyyz();
	/*MathDLL*/ Vector4 zyzw();
	/*MathDLL*/ Vector4 zyzx();
	/*MathDLL*/ Vector4 zyzy();
	/*MathDLL*/ Vector4 zyzz();
	/*MathDLL*/ Vector4 zzww();
	/*MathDLL*/ Vector4 zzwx();
	/*MathDLL*/ Vector4 zzwy();
	/*MathDLL*/ Vector4 zzwz();
	/*MathDLL*/ Vector4 zzxw();
	/*MathDLL*/ Vector4 zzxx();
	/*MathDLL*/ Vector4 zzxy();
	/*MathDLL*/ Vector4 zzxz();
	/*MathDLL*/ Vector4 zzyw();
	/*MathDLL*/ Vector4 zzyx();
	/*MathDLL*/ Vector4 zzyy();
	/*MathDLL*/ Vector4 zzyz();
	/*MathDLL*/ Vector4 zzzw();
	/*MathDLL*/ Vector4 zzzx();
	/*MathDLL*/ Vector4 zzzy();
	/*MathDLL*/ Vector4 zzzz();
	 
	/*MathDLL*/ Vector4 wwww();
	/*MathDLL*/ Vector4 wwwx();
	/*MathDLL*/ Vector4 wwwy();
	/*MathDLL*/ Vector4 wwwz();
	/*MathDLL*/ Vector4 wwxw();
	/*MathDLL*/ Vector4 wwxx();
	/*MathDLL*/ Vector4 wwxy();
	/*MathDLL*/ Vector4 wwxz();
	/*MathDLL*/ Vector4 wwyw();
	/*MathDLL*/ Vector4 wwyx();
	/*MathDLL*/ Vector4 wwyy();
	/*MathDLL*/ Vector4 wwyz();
	/*MathDLL*/ Vector4 wwzw();
	/*MathDLL*/ Vector4 wwzx();
	/*MathDLL*/ Vector4 wwzy();
	/*MathDLL*/ Vector4 wwzz();
	/*MathDLL*/ Vector4 wxww();
	/*MathDLL*/ Vector4 wxwx();
	/*MathDLL*/ Vector4 wxwy();
	/*MathDLL*/ Vector4 wxwz();
	/*MathDLL*/ Vector4 wxxw();
	/*MathDLL*/ Vector4 wxxx();
	/*MathDLL*/ Vector4 wxxy();
	/*MathDLL*/ Vector4 wxxz();
	/*MathDLL*/ Vector4 wxyw();
	/*MathDLL*/ Vector4 wxyx();
	/*MathDLL*/ Vector4 wxyy();
	/*MathDLL*/ Vector4 wxyz();
	/*MathDLL*/ Vector4 wxzw();
	/*MathDLL*/ Vector4 wxzx();
	/*MathDLL*/ Vector4 wxzy();
	/*MathDLL*/ Vector4 wxzz();
	/*MathDLL*/ Vector4 wyww();
	/*MathDLL*/ Vector4 wywx();
	/*MathDLL*/ Vector4 wywy();
	/*MathDLL*/ Vector4 wywz();
	/*MathDLL*/ Vector4 wyxw();
	/*MathDLL*/ Vector4 wyxx();
	/*MathDLL*/ Vector4 wyxy();
	/*MathDLL*/ Vector4 wyxz();
	/*MathDLL*/ Vector4 wyyw();
	/*MathDLL*/ Vector4 wyyx();
	/*MathDLL*/ Vector4 wyyy();
	/*MathDLL*/ Vector4 wyyz();
	/*MathDLL*/ Vector4 wyzw();
	/*MathDLL*/ Vector4 wyzx();
	/*MathDLL*/ Vector4 wyzy();
	/*MathDLL*/ Vector4 wyzz();
	/*MathDLL*/ Vector4 wzww();
	/*MathDLL*/ Vector4 wzwx();
	/*MathDLL*/ Vector4 wzwy();
	/*MathDLL*/ Vector4 wzwz();
	/*MathDLL*/ Vector4 wzxw();
	/*MathDLL*/ Vector4 wzxx();
	/*MathDLL*/ Vector4 wzxy();
	/*MathDLL*/ Vector4 wzxz();
	/*MathDLL*/ Vector4 wzyw();
	/*MathDLL*/ Vector4 wzyx();
	/*MathDLL*/ Vector4 wzyy();
	/*MathDLL*/ Vector4 wzyz();
	/*MathDLL*/ Vector4 wzzw();
	/*MathDLL*/ Vector4 wzzx();
	/*MathDLL*/ Vector4 wzzy();
	/*MathDLL*/ Vector4 wzzz();
	 
	// initializes the Vectors
	float x;
	float y;
	float z;
	float w;
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
/*MathDLL*/ Vector4 operator*(const float lhs, const Vector4& rhs);

//----------------------------------------------------------------------------
// Overloads the / operator to divide float & Vector together
//
// Param:
//      rhs: is the right hand side vector being divided
//      lhs: is the left hand side float being divided
// Return:
//       Returns the result of devided values
//----------------------------------------------------------------------------
/*MathDLL*/ Vector4 operator/(const float lhs, const Vector4& rhs);

