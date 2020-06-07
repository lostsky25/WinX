#pragma once
#define ISOLATION_AWARE_ENABLED 1
#include <Windows.h>
#include <commctrl.h>

class XApplet
{
public:
	virtual void SetMinimumWidth(int) = 0;
	virtual void SetMinimumHeight(int) = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;

protected:
	HWND GetHandle();
	HWND applet;
	int width;
	int height;
	LPWSTR text;

	virtual void SetApplet(HWND, int, int) = 0;
};

