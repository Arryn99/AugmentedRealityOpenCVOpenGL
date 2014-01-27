#include <windows.h>

class Window{

private:
	HDC ghdc;
	HGLRC ghrc;

	HWND        hwnd;
	HINSTANCE	ghInstance;
	RECT		gRect;
	RECT		screenRect;

public:
	~Window();	
	RECT getRect();
	HWND getHwnd();
	Window(LPSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance, WNDPROC WndProc);
};
