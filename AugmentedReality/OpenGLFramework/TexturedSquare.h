#ifndef TEXTUREDSQUARE_H
#define TEXTUREDSQUARE_H

#include "Vector3.h"
#include "Squares.h"
#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glu.h>

class TexturedSquare: public Squares
{
public:
	void drawSquare();
	void setTexture(GLuint texID);
protected:
	GLuint m_texID;
};

#endif