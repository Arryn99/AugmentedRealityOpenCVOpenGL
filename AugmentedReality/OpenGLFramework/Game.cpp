#include "Game.h"
#include "textures.h"
#include "MilkshapeModel.h"

const GLfloat Game::Light_Ambient[4] = {0.3f, 0.3f, 0.3f, 1.0f};
const GLfloat Game::Light_Diffuse[4] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat Game::Light_Position[4]= {3.0f, 0.0f, 1.5f, 1.0f};
const GLfloat Game::Material_Diffuse[4] = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat Game::Mat_Shininess[1] = {6.0f};

Game::Game() {
	cam = new Camera();
	CreateGLTexture("truckTexture.tga", truckTexture);

	truckModel = new MilkshapeModel();
	if ( truckModel->loadModelData( "textTruck.ms3d" ) == false )
	{
		MessageBox( NULL, "Couldn't load the model data/truck.ms3d", "Error", MB_OK | MB_ICONERROR );
	}
	truckModel->reloadTextures();
};

void Game::draw(){
	int i=0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear The Screen And The Depth Buffer
	glLoadIdentity();// load Identity Matrix
	//cam.CameraUpdate();
	cam->LookAt();

	glEnable(GL_LIGHT1);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, truckTexture);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-30, -9.5f, -20.5f);
	glScalef(3.0f, 3.0f, 3.0f);
	truckModel->draw();
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();	

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Material_Diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, Mat_Shininess);

	glLightfv(GL_LIGHT1, GL_AMBIENT,  Light_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  Light_Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position);

};