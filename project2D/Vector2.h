#pragma once
#include <math.h>
#include "real.h"
class Vector2
{
public:

	

	Vector2();

	 Vector2(real newX, real newY);
	 Vector2(const Vector2& other);


	virtual ~Vector2();

	//Vector2 operator=(Vector2& vector)const;

	real & operator[] (const int &index);

	const real  operator[] (const int index) const;

	//operator Vector3();
	Vector2 operator+(Vector2 & other) const;
	Vector2 operator-(Vector2 & vector) const;
	Vector2 operator*(const real scalar);
	Vector2 operator/(const real scalar);

	friend Vector2 operator*(real scalar, Vector2 &vector) {return vector * scalar;}
	real dot(Vector2 & other) const;
	real magnitude();
	void normalise();
	const int  getSize() { return  1; } ;
	//************************************************************************************
	//                      OveLoadeded Cast operator
	//************************************************************************************
	operator real*() {return &V[0];}
    //************************************************************************************
	//************************************************************************************


	union
	{
		struct { real x, y; };
		real V[2];
	};




//#pragma region swizzle 
//	/*
//	* GetXX
//	*
//	* swizzles vector to (x,x)
//	*
//	* @returns Vector2 - the swizzled vector
//	*/
//	 Vector2 GetXX();
//
//	/*
//	* GetYX
//	*
//	* swizzles vector to (y,x)
//	*
//	* @returns Vector2 - the swizzled vector
//	*/
//	 Vector2 GetYX();
//
//	/*
//	* GetYY
//	*
//	* swizzles vector to (y,y)
//	*
//	* @returns Vector2 - the swizzled vector
//	*/
//	 Vector2 GetYY();
//
//	/*
//	* GetXXX
//	*
//	* swizzles vector to (x,x,x)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	 Vector3 GetXXX();
//
//	/*
//	* GetXXY
//	*
//	* swizzles vector to (x,x,y)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	 Vector3 GetXXY();
//
//	/*
//	* GetXYX
//	*
//	* swizzles vector to (x,y,x)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	 Vector3 GetXYX();
//
//	/*
//	* GetXYY
//	*
//	* swizzles vector to (x,y,y)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	 Vector3 GetXYY();
//
//	/*
//	* GetYXX
//	*
//	* swizzles vector to (y,x,x)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	 Vector3 GetYXX();
//
//	/*
//	* GetYXY
//	*
//	* swizzles vector to (y,x,y)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//     Vector3 GetYXY();
//
//	/*
//	* GetYYX
//	*
//	* swizzles vector to (y,y,x)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	 Vector3 GetYYX();
//
//	/*
//	* GetYYY
//	*
//	* swizzles vector to (y,y,y)
//	*
//	* @returns Vector3 - the swizzled vector
//	*/
//	Vector3 GetYYY();
//
//	/*
//	* GetXXXX
//	*
//	* swizzles vector to (x,x,x,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXXXX();
//
//	/*
//	* GetXXXY
//	*
//	* swizzles vector to (x,x,x,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXXXY();
//
//	/*
//	* GetXXYX
//	*
//	* swizzles vector to (x,x,y,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXXYX();
//
//	/*
//	* GetXXYY
//	*
//	* swizzles vector to (x,x,y,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXXYY();
//
//	/*
//	* GetXYXX
//	*
//	* swizzles vector to (x,y,x,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXYXX();
//
//	/*
//	* GetXYXY
//	*
//	* swizzles vector to (x,y,x,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXYXY();
//
//	/*
//	* GetXYYX
//	*
//	* swizzles vector to (x,y,y,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXYYX();
//
//	/*
//	* GetXYYY
//	*
//	* swizzles vector to (x,y,y,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetXYYY();
//
//	/*
//	* GetYXXX
//	*
//	* swizzles vector to (y,x,x,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYXXX();
//
//	/*
//	* GetYXXY
//	*
//	* swizzles vector to (y,x,x,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYXXY();
//
//	/*
//	* GetYXYX
//	*
//	* swizzles vector to (y,x,y,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYXYX();
//
//	/*
//	* GetYXYY
//	*
//	* swizzles vector to (y,x,y,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYXYY();
//
//	/*
//	* GetYYXX
//	*
//	* swizzles vector to (y,y,x,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYYXX();
//
//	/*
//	* GetYYXY
//	*
//	* swizzles vector to (y,y,x,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYYXY();
//
//	/*
//	* GetYYYX
//	*
//	* swizzles vector to (y,y,y,x)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYYYX();
//
//	/*
//	* GetYYYY
//	*
//	* swizzles vector to (y,y,y,y)
//	*
//	* @returns Vector4 - the swizzled vector
//	*/
//	 Vector4 GetYYYY();


#pragma endregion swizzle 

};
