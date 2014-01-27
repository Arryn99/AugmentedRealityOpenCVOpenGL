#include "Camera.h"
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>

Camera::Camera()
{
	pos.x = -20;
	pos.y = 0;
	pos.z = 90;

	forward.x = 0;
	forward.y = 0;
	forward.z = -1;

	up.x = 0;
	up.y = 1;
	up.z = 0;

	right.x = 1;
	right.y = 0;
	right.z = 0;
}

void Camera::LookAt()
{
	gluLookAt(pos.x, pos.y, pos.z,     pos.x + forward.x, pos.y + forward.y, pos.z + forward.z,     up.x, up.y, up.z);
}

void Camera::SetPositionX(float x)
{
	pos.x = x;
}
void Camera::SetPositionY(float y)
{
	pos.y = y;
}
void Camera::SetPositionZ(float z)
{
	pos.z = z;
}

float Camera::getPositionX()
{
	return pos.x;
}

float Camera::getPositionY()
{
	return pos.y;
}

float Camera::getPositionZ()
{
	return pos.z;
}

void Camera::moveForward(float speed)
{
	pos.x += forward.x*speed;
	pos.y += forward.y*speed;
	pos.z += forward.z*speed;
}

void Camera::moveBackwards(float speed)
{
	pos.x -= forward.x*speed;
	pos.y -= forward.y*speed;
	pos.z -= forward.z*speed;
}

void Camera::moveRight(float speed)
{
	pos.x += right.x*speed;
	pos.y += right.y*speed;
	pos.z += right.z*speed;
}
void Camera::moveLeft(float speed)
{
	pos.x -= right.x*speed;
	pos.y -= right.y*speed;
	pos.z -= right.z*speed;
}

void Camera::moveUp(float speed)
{
	pos.x += up.x*speed;
	pos.y += up.y*speed;
	pos.z += up.z*speed;
}
void Camera::moveDown(float speed)
{
	pos.x -= up.x*speed;
	pos.y -= up.y*speed;
	pos.z -= up.z*speed;
}

//Camera Update function (note this will NOT compile)

void Camera::CameraUpdate()
{
	float cosR, cosP, cosY;		//temp values for sin/cos from 
	float sinR, sinP, sinY;		//the inputed roll/pitch/yaw

	// “cam” is an object  created to store the vectors for the camera.
	// Only Want to calculate these values once. 
	// For speeds sake. 
	cosY = cosf(Yaw*3.1415/180);
	cosP = cosf(Pitch*3.1415/180);
	cosR = cosf(Roll*3.1415/180);
	sinY = sinf(Yaw*3.1415/180);
	sinP = sinf(Pitch*3.1415/180);
	sinR = sinf(Roll*3.1415/180);

	// Forward Vector
	forward.x = sinY * cosP*360;
	forward.y = sinP*360;
	forward.z = cosP * -cosY*360;	

	//normalise to unit vector
	forward.normalise();

	// Up Vector
	up.x = -cosY * sinR - sinY * sinP * cosR;
	up.y = cosP * cosR;
	up.z = -sinY * sinR - sinP * cosR * -cosY;

	//normalise to unit vector
	up.normalise();

	// Side Vector (right)
	right = forward.Cross(up);
}

void Camera::setRoll(int x)
{
	Roll = x;
}

void Camera::setPitch(int y)
{
	Pitch = y;
}

void Camera::setYaw(int z)
{
	Yaw = z;
}

void Camera::incrementPitch(float speed)
{
	Pitch += speed;
}

void Camera::incrementYaw(float speed)
{
	Yaw += speed;
}

void Camera::incrementRoll(float speed)
{
	Roll += speed;
}
