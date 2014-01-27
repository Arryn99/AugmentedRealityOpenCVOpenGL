#ifndef VECTOR_H
#define VECTOR_H

class Vector3
{
public:
	Vector3();
	Vector3(float x,float y, float z);
	float x;
	float y;
	float z;
	float Length();
	void normalise();
	Vector3 Cross(const Vector3 & otherVector)const;
};


#endif