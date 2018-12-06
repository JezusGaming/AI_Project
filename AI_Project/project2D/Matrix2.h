//------------------------------------------------------------------------------------------------------------
// Class for Matrix2
// Which is both static and dynamic libary and replaces __declspec with /*MathDLL*/
//------------------------------------------------------------------------------------------------------------
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
#include "Vector2.h"
#include <math.h>

class Matrix2
{
public:

	//----------------------------------------------------------------------------
	// Deafault Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix2(); 

	//----------------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix2(float xx, float xy, float yy, float yx);

	//----------------------------------------------------------------------------
	// Deafault Destructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ ~Matrix2();
	 
	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply a matrix and Vector together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 operator*(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply a matrix and matrix together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix2 operator*(const Matrix2& rhs);

	//----------------------------------------------------------------------------
	// Rotates the on the xaxis
	//
	// Param:
	//      a: amount it is being rotated
	//
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setRotate(const float a);

	//----------------------------------------------------------------------------
	// stores the scale of an object
	//
	// Param:
	//      x: scale on the xaxis
	//		y: scale on the yaxis
	//		z: sclae on the zaxis
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setScale(float x, float y);

	//----------------------------------------------------------------------------
	// gets the scale of the object
	//
	// Param:
	//      
	// Return:
	//		Returns the objects scale
	//----------------------------------------------------------------------------
	/*MathDLL*/	Vector2 getScale();


	/*MathDLL*/ Vector2& operator[](const int rhs);
	/*MathDLL*/ operator float*();	

	//----------------------------------------------------------------------------
	// checks if the matrix is an identity matrix
	//
	// Param:
	//      
	// Return:
	//		Returns true or false depending if it is or is not an identity matrix
	//----------------------------------------------------------------------------
	/*MathDLL*/ bool isIdentity();

	//----------------------------------------------------------------------------
	// calculates the determinant of the matrix
	//
	// Param:
	//      
	// Return:
	//		Returns determinant of the matrix
	//----------------------------------------------------------------------------
	/*MathDLL*/ float determinant();

	//----------------------------------------------------------------------------
	// calculates the transpose of this matrix
	//
	// Param:
	//      
	// Return:
	//		Returns the transpose of this matrix
	//----------------------------------------------------------------------------
	/*MathDLL*/ void transpose();

	//----------------------------------------------------------------------------
	// calculates the invers of the matrix
	//
	// Param:
	//      
	// Return:
	//		Returns inverse of the matrix
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix2 inverse();

	float m[2][2];
};

