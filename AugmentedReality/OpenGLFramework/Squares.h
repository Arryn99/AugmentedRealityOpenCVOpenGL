#ifndef SQUARES_H
#define SQUARES_H

#include "Vector3.h"

#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glu.h>

class Squares
{
public:
	Squares();
	Squares(int width, int length){};
	~Squares(){};
	void drawSquare();
	void setPosition(Vector3 position);
	void setScale(Vector3 scale);
protected:
	Vector3 m_position;
	Vector3 m_scale;
};

#endif