#ifndef CUBE_H
#define CUBE_H

#include "Squares.h"
#include "Vector3.h"

#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glu.h>

class Cube
{
public:
	Squares faceOne;
	Squares faceTwo;
	Squares faceThree;
	Squares faceFour;
	Squares faceFive;
	Squares faceSix;

	Vector3 position;
	Vector3 scale;
	Vector3 rotate;
	GLuint  texID[6];
	
	float angle;

	void setPosition(Vector3 Position);
	void setScale(Vector3 Scale);
	void setRotation(Vector3 Rotate, float Angle);
	void setTexture(GLuint TexID);
	void setTexture(GLuint TexID[6]);

	void drawCube();
};

#endif