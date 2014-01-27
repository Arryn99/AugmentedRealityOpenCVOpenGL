#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float X,float Y, float Z){
	x = X;
	y = Y;
	z = Z;
}

float Vector3::Length()
{
	float length = sqrt(x*x + y*y + z*z);

	return length;
}

void Vector3::normalise()
{
	float len = Length();

	if (len == 0)
	{
		return;
	}

	x = x/len;
	y = y/len;
	z = z/len;
}

Vector3 Vector3::Cross(const Vector3 & otherVector) const
{
	Vector3 returnVal;
	returnVal.x =	(this->y*otherVector.z - otherVector.y * this->z);
	returnVal.y = - (this->x*otherVector.z - otherVector.x * this->z);
	returnVal.z =	(this->x*otherVector.y - otherVector.x * this->y);
	return returnVal;
}