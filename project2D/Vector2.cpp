#include "Vector2.h"



Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(real newX, real newY)
{
	x = newX;
	y = newY;

}

Vector2::Vector2(const Vector2 & other)
{
	x = other.x;
	y = other.y;
}


Vector2::~Vector2()
{
}


//Vector2::operator Vector3()
//{
//	return Vector3(x, y, 1.0f);
//}

Vector2 Vector2::operator+(Vector2 & other) const
{
	
	return Vector2(x + other.x,y + other.y);
}

Vector2 Vector2::operator-(Vector2 & other) const
{
	return Vector2(x - other.x, y - other.y);
}


Vector2 Vector2::operator*(const real scalar)
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(const real scalar)
{
	return Vector2(x / scalar, y / scalar);
}

real Vector2::dot(Vector2 & other) const
{
	real Xdot = x * other.x;
	real Ydot = y * other.y;
	real dotProduct = Xdot + Ydot;
	return dotProduct;
}

real Vector2::magnitude()
{
	real powX = (real)pow(x,2);
	real powY = (real)pow(y, 2);
	real magnitude = (real)sqrt(powX + powY);
	return (real)magnitude;
}

void Vector2::normalise()
{
	real mag = magnitude();

	if (mag == 0)
	{
		return;
	}

	x = x / mag;
	y = y / mag;
}



//#pragma region swizzle
////swizzling
//Vector2 Vector2::GetXX()
//{
//	return Vector2{ x,x };
//}
//
////swizzling
//Vector2 Vector2::GetYX()
//{
//	return Vector2{ y,x };
//}
//
////swizzling
//Vector2 Vector2::GetYY()
//{
//	return Vector2{ y,y };
//}
//
////swizzling
//Vector3 Vector2::GetXXX()
//{
//	return Vector3{ x,x,x };
//}
//
////swizzling
//Vector3 Vector2::GetXXY()
//{
//	return Vector3{ x,x,y };
//}
//
////swizzling
//Vector3 Vector2::GetXYX()
//{
//	return Vector3{ x,y,x };
//}
//
////swizzling
//Vector3 Vector2::GetXYY()
//{
//	return Vector3{ x,y,y };
//}
//
////swizzling
//Vector3 Vector2::GetYXX()
//{
//	return Vector3{ y,x,x };
//}
//
////swizzling
//Vector3 Vector2::GetYXY()
//{
//	return Vector3{ y,x,y };
//}
//
////swizzling
//Vector3 Vector2::GetYYX()
//{
//	return Vector3{ y,y,x };
//}
//
////swizzling
//Vector3 Vector2::GetYYY()
//{
//	return Vector3{ y,y,y };
//}
//
////swizzling
//Vector4 Vector2::GetXXXX()
//{
//	return Vector4{ x,x,x,x };
//}
//
////swizzling
//Vector4 Vector2::GetXXXY()
//{
//	return Vector4{ x,x,x,y };
//}
//
////swizzling
//Vector4 Vector2::GetXXYX()
//{
//	return Vector4{ x,x,y,x };
//}
//
////swizzling
//Vector4 Vector2::GetXXYY()
//{
//	return Vector4{ x,x,y,y };
//}
//
////swizzling
//Vector4 Vector2::GetXYXX()
//{
//	return Vector4{ x,y,x,x };
//}
//
////swizzling
//Vector4 Vector2::GetXYXY()
//{
//	return Vector4{ x,y,x,y };
//}
//
////swizzling
//Vector4 Vector2::GetXYYX()
//{
//	return Vector4{ x,y,y,x };
//}
//
////swizzling
//Vector4 Vector2::GetXYYY()
//{
//	return Vector4{ x,y,y,y };
//}
//
////swizzling
//Vector4 Vector2::GetYXXX()
//{
//	return Vector4{ y,x,x,x };
//}
//
////swizzling
//Vector4 Vector2::GetYXXY()
//{
//	return Vector4{ y,x,x,y };
//}
//
////swizzling
//Vector4 Vector2::GetYXYX()
//{
//	return Vector4{ y,x,y,x };
//}
//
////swizzling
//Vector4 Vector2::GetYXYY()
//{
//	return Vector4{ y,x,y,y };
//}
//
////swizzling
//Vector4 Vector2::GetYYXX()
//{
//	return Vector4{ y,y,x,x };
//}
//
////swizzling
//Vector4 Vector2::GetYYXY()
//{
//	return Vector4{ y,y,x,y };
//}
//
////swizzling
//Vector4 Vector2::GetYYYX()
//{
//	return Vector4{ y,y,y,x };
//}
//
////swizzling
//Vector4 Vector2::GetYYYY()
//{
//	return Vector4{ y,y,y,y };
//}
//
//
//#pragma endregion swizzle


real &Vector2::operator[] (const int &index)
{
	return V[index];
}

const real  Vector2::operator[] (const int index) const
{
	return V[index];
}