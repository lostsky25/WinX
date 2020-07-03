#include "XMainWindow.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    XMainWindow* mainWindow = new XMainWindow({ hInstance, hPrevInstance, lpCmdLine, nCmdShow});

	
	return 0;
}