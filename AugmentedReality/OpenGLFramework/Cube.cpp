#include "Cube.h"

void Cube::drawCube()
{
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, texID[0]);
		
		glTranslatef(position.x, position.y, position.z);	//where to draw cube
		glRotatef(angle, rotate.x, rotate.y, rotate.z);
		glScalef(scale.x, scale.y, scale.z);				//what size cube should be

		glBindTexture(GL_TEXTURE_2D, texID[0]);
		faceOne.drawSquare();	//front face
		glRotatef(90, 0, 1, 0);
		glTranslatef(0.5f, 0.0f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texID[1]);
		faceTwo.drawSquare();	//right face
		glRotatef(90, 0, 1, 0);
		glTranslatef(0.5f, 0.0f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texID[2]);
		faceThree.drawSquare();	//back face
		glRotatef(90, 0, 1, 0);
		glTranslatef(0.5f, 0.0f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texID[3]);
		faceFour.drawSquare();	//left face
		glRotatef(90, 1, 0, 0);
		glTranslatef(0.0f, -0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texID[4]);
		faceFive.drawSquare();	//bottom face
		glTranslatef(0.0f, 0.0f, -1.0f);
		glBindTexture(GL_TEXTURE_2D, texID[5]);
		faceSix.drawSquare();	//top face

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}	

void Cube::setPosition(Vector3 Position)
{
	position = Position;
}

void Cube::setScale(Vector3 Scale)
{
	scale = Scale;
}

void Cube::setRotation(Vector3 Rotate, float Angle)
{
	angle = Angle;
	rotate = Rotate;
}

//set one texture for the whole cube
void Cube::setTexture(GLuint TexID)
{
	texID[0] = TexID;
	texID[1] = TexID;
	texID[2] = TexID;
	texID[3] = TexID;
	texID[4] = TexID;
	texID[5] = TexID;
}

//set a different texture for each side of the cube
void Cube::setTexture(GLuint TexID[6])
{
	texID[0] = TexID[0];	//set the first texture 
	texID[1] = TexID[1];	//set the second texture
	texID[2] = TexID[2];	//set the third texture
	texID[3] = TexID[3];	//set the fourth texture
	texID[4] = TexID[4];	//set the fifth texture
	texID[5] = TexID[5];	//set the sixth texture
}