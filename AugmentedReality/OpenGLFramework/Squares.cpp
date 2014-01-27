#include "Squares.h"

Squares::Squares()
{
	m_scale = Vector3(1,1,1);
}

void Squares::drawSquare()
{
	//front face (facing camera)
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glScalef(m_scale.x, m_scale.y, m_scale.z);
	glBegin (GL_QUADS);
	glNormal3f( 0.0f, 0.0f, 1.0f);		//Normal Pointing Towards Viewer
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f,  0.0f);	//Bottom Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 0.5f, -0.5f,  0.0f);	//Bottom Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 0.5f,  0.5f,  0.0f);	//Top Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f,  0.5f,  0.0f);	//Top Left Of The Texture and Quad
	glEnd();
	glPopMatrix();
}

void Squares::setPosition(Vector3 position)
{
	m_position = position;
}
void Squares::setScale(Vector3 scale)
{
	m_scale = scale;
}
