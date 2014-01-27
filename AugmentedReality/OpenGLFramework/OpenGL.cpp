#include "OpenGL.h"
#include <gl/glu.h>

#define COLOUR_DEPTH 16	//Colour depth

void OpenGL::InitializeOpenGL(int width, int height, HWND &openGLwindow) 
{  
	ghdc = GetDC(openGLwindow);//  sets  global HDC

	if (!TrySetPixelFormat(ghdc))//  sets  pixel format
		PostQuitMessage (0);


	ghrc = wglCreateContext(ghdc);	//  creates  rendering context from  hdc
	wglMakeCurrent(ghdc, ghrc);		//	Use this HRC.

	ResizeGLWindow(width, height);	// Setup the Screen
	glEnable(GL_COLOR_MATERIAL);

	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_LIGHTING);
}

void OpenGL::openGLCleanup(HWND &openGLwindow)
{
	if (ghrc)
	{
		wglMakeCurrent(NULL, NULL);	// free rendering memory
		wglDeleteContext(ghrc);		// Delete our OpenGL Rendering Context
	}
	if (ghdc)
		ReleaseDC(openGLwindow, ghdc);			// Release our HDC from memory
}

void OpenGL::swapBuffersGL() {
	SwapBuffers(ghdc);	// Swap the frame buffers
}

bool OpenGL::TrySetPixelFormat(HDC hdc) { 
	PIXELFORMATDESCRIPTOR pfd = {0}; 
	int pixelformat; 

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);	// Set the size of the structure
	pfd.nVersion = 1;							// Always set this to 1
	// Pass in the appropriate OpenGL flags
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
	pfd.dwLayerMask = PFD_MAIN_PLANE;			// standard mask (this is ignored anyway)
	pfd.iPixelType = PFD_TYPE_RGBA;				// RGB and Alpha pixel type
	pfd.cColorBits = COLOUR_DEPTH;				// Here we use our #define for the color bits
	pfd.cDepthBits = COLOUR_DEPTH;				// Ignored for RBA
	pfd.cAccumBits = 0;							// nothing for accumulation
	pfd.cStencilBits = 0;						// nothing for stencil

	//Gets a best match on the pixel format as passed in from device
	if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == false ) 
	{ 
		MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
		return false; 
	} 

	//sets the pixel format if its ok. 
	if (SetPixelFormat(hdc, pixelformat, &pfd) == false) 
	{ 
		MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
		return false; 
	} 

	return true;
}

void OpenGL::ResizeGLWindow(int width, int height)// Initialize The GL Window
{
	if (height==0)// Prevent A Divide By Zero error
	{
		height=1;// Make the Height Equal One
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//calculate aspect ratio
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 0.1f ,250.0f);

	glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
	glLoadIdentity();// Reset The Modelview Matrix
}



