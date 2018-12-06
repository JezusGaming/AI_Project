//--------------------------------------------------------------------------------
// Class for Matrix4
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
#include "Vector4.h"
#include "Vector3.h"
#include <math.h>

class Matrix4
{
public:

	//----------------------------------------------------------------------------
	// Deafault Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix4();

	//----------------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw, float zx, float zy, float zz, float zw, float wx, float wy, float wz, float ww);

	//----------------------------------------------------------------------------
	// Deafault Destructor
	//----------------------------------------------------------------------------
	/*MathDLL*/ ~Matrix4();

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply a matrix and Vector together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector4 operator*(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// Overloads the * operator to multiply a matrix and matrix together
	//
	// Param:
	//      rhs: is the other value being multiplied
	//
	// Return:
	//       Returns the result of multiplyed values
	//----------------------------------------------------------------------------
	/*MathDLL*/ Matrix4 operator*(const Matrix4& rhs);

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
	/*MathDLL*/ void setPos(float x, float y, float z);

	//----------------------------------------------------------------------------
	// stores the postion of an object based on a vector
	//
	// Param:
	//      rhs: vector position geting stored
	// Return:
	//----------------------------------------------------------------------------
	/*MathDLL*/ void setPos(const Vector4& rhs);

	//----------------------------------------------------------------------------
	// gets the position stored in the matrix
	//
	// Param:
	//      
	// Return:
	//		Returns the objects position
	//----------------------------------------------------------------------------
	/*MathDLL*/ Vector3 getPos();

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
	/*MathDLL*/ Vector3 getScale();


	/*MathDLL*/ Vector4& operator[](const int rhs);
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
	/*MathDLL*/ void lookAt(Vector3 from, const Vector3 target, Vector3 up);

	float m[4][4];
};

