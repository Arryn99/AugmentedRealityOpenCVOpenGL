#pragma once
#include <windows.h>
#include <gl/glu.h>
#include "Model.h"
#include "Camera.h"

class Game{

private:
	Camera* cam;
	GLuint truckTexture;
	Model *truckModel;

	static const GLfloat Light_Ambient[4];
	static const GLfloat Light_Diffuse[4];
	static const GLfloat Light_Position[4];
	static const GLfloat Material_Diffuse[4];
	static const GLfloat Mat_Shininess[1];

public:
	
	Game();
	~Game();

	void draw();
};