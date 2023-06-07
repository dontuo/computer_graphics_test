#include "windows.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	WNDCLASSEX wc = {0};

	RegisterClassEx(&wc);
	return 0;
}