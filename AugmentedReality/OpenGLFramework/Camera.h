#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera
{
public:
	Camera();
	void CameraUpdate();
	void SetPositionX(float x);
	void SetPositionY(float y);
	void SetPositionZ(float z);
	float getPositionX();
	float getPositionY();
	float getPositionZ();
	void moveForward(float speed);
	void moveBackwards(float speed);
	void moveRight(float speed);
	void moveLeft(float speed);
	void moveUp(float speed);
	void moveDown(float speed);
	void LookAt();
	void setRoll(int x);
	void setPitch(int y);
	void setYaw(int z);
	void incrementPitch(float speed);
	void incrementYaw(float speed);
	void incrementRoll(float speed);

private:
	Vector3 pos;
	Vector3 forward;
	Vector3 up;
	Vector3 right;
	float Roll;
	float Pitch;
	float Yaw;
};


#endif