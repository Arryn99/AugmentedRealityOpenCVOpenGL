#include "Window.h"
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include <gl/gl.h>

Window::Window(LPSTR strWindowName, int width, int height, DWORD dwStyle,
	bool bFullScreen, HINSTANCE hInstance, WNDPROC WndProc) {

		WNDCLASS wcex;

		memset(&wcex, 0, sizeof(WNDCLASS));
		wcex.style			= CS_HREDRAW | CS_VREDRAW;		
		wcex.lpfnWndProc	= WndProc;		
		wcex.hInstance		= hInstance;						
		wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);; 
		wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);		
		wcex.hbrBackground	= (HBRUSH) (COLOR_WINDOW+1);
		wcex.lpszMenuName	= NULL;	
		wcex.lpszClassName	= "FirstWindowClass";	


		RegisterClass(&wcex);// Register the class

		dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

		//Set the Client area of the window to be our resolution.
		RECT glwindow;
		glwindow.left		= 0;		
		glwindow.right		= width;	
		glwindow.top		= 0;		
		glwindow.bottom		= height;	

		AdjustWindowRect( &glwindow, dwStyle, false);

		//Create the window
		hwnd = CreateWindow(	"FirstWindowClass", 
			strWindowName, 
			dwStyle, 
			0, 
			0,
			glwindow.right  - glwindow.left,
			glwindow.bottom - glwindow.top, 
			NULL,
			NULL,
			hInstance,
			NULL
			);

		if(hwnd){
			ShowWindow(hwnd, SW_SHOWNORMAL);	
			UpdateWindow(hwnd);					
			SetFocus(hwnd);						
			GetClientRect(hwnd, &gRect);	//get rect into our handy global rect
		}
}

Window::~Window(){
	UnregisterClass("FirstWindowClass", ghInstance);// Free the window class
	PostQuitMessage (0);		// Post a QUIT message to the windowS
}

RECT Window::getRect(){
	return gRect;
}

HWND Window::getHwnd(){
	return hwnd;
}