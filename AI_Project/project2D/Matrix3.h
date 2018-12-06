//------------------------------------------------------------------------------------------------------------
// Class for Matrix3
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
#include "Vector3.h"
#include <math.h>

class Matrix3
{
public:

	//----------------------------------------------------------------------------
	// Deafault Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix3();

	//----------------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix3(float xx, float xy, float xz, float yy, float yx, float yz, float zz, float zx, float zy);

	//----------------------------------------------------------------------------
	// Deafault Destructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ ~Matrix3();
	 
	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply a matrix and Vector together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 operator*(const Vector3& rhs);

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply a matrix and matrix together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix3 operator*(const Matrix3& rhs);
	 
	//----------------------------------------------------------------------------
	// Rotates the on the xaxis
	//
	// Param:
	//      a: amount it is being rotated
	//
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setRotateX(const float a);

	//----------------------------------------------------------------------------
	// Rotates the on the yaxis
	//
	// Param:
	//      a: amount it is being rotated
	//
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setRotateY(const float a);

	//----------------------------------------------------------------------------
	// Rotates the on the zaxis
	//
	// Param:
	//      a: amount it is being rotated
	//
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setRotateZ(const float a);
	 
	//----------------------------------------------------------------------------
	// stores the postion of an object
	//
	// Param:
	//      x: location on the xaxis
	//		y: location on the yaxis
	//		z: location on the zaxis
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setPos(float x, float y);

	//----------------------------------------------------------------------------
	// stores the postion of an object based on a vector
	//
	// Param:
	//      rhs: vector position geting stored
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setPos(const Vector2& rhs);

	//----------------------------------------------------------------------------
	// gets the position stored in the matrix
	//
	// Param:
	//      
	// Return:
	//		Returns the objects position
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 getPos();

	//----------------------------------------------------------------------------
	// stores the scale of an object
	//
	// Param:
	//      x: scale on the xaxis
	//		y: scale on the yaxis
	//		z: sclae on the zaxis
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setScale(float x, float y, float z);

	//----------------------------------------------------------------------------
	// gets the scale of the object
	//
	// Param:
	//      
	// Return:
	//		Returns the objects scale
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector2 getScale();


	/*MathDLL*/ Vector3& operator[](const int rhs);
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
	 
	float m[3][3];
};

