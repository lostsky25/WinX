#pragma once
#include <windows.h>

class XThread
{
public:
	XThread() = default;
	~XThread() = default;
protected:
	DWORD id;
	HANDLE thread;
	DWORD param;

	void startThread(DWORD (*thProc)(LPVOID)) {
		param = 0;
		thread = CreateThread(0, 0, thProc, &param, 0, &id);
	}
};

