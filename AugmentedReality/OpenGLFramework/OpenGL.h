#include <windows.h>

class OpenGL{
	HDC ghdc;
	HGLRC ghrc;

public:
	void InitializeOpenGL(int width, int height, HWND &openGLwindow);
	bool TrySetPixelFormat(HDC hdc);
	void ResizeGLWindow(int width, int height);
	void openGLCleanup(HWND &openGLwindow);
	void swapBuffersGL();
};
