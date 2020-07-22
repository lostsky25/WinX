#pragma once

#if _WIN32 || _WIN64
	#if _WIN64
		#define _AMD64_
	#else
		#define _X86_
	#endif
#endif


#include <windef.h>													//For HWND.
#include "XTypes.h"													//For XMargins, XRect.

class __xhandle
{
private:
	HWND _wnd;														//The main window handle.
	XMargins margins;												//Window margins (left, top, right, bottom).
	XRect rect;												//Window rectangle (x, y, right, bottom).

	int maximumHeight = 0;											//Maximum window height.
	int maximumWidth = 0;											//Maximum window width.
	int minimumHeight = 0;											//Minimum window height.
	int minimumWidth = 0;											//Minimum window width.

protected:
	friend class XButton;
	friend class XLabel;
	friend class XVLayout;
	friend class XHLayout;
	friend class XApplet;
	friend class XApplication;
	friend class XApplicationProc;
	friend class XHANDLE;
};

class XHANDLE
{
public:
	XHANDLE();
	~XHANDLE();

private:
	__xhandle *window;

protected:
	friend class XButton;
	friend class XLabel;
	friend class XVLayout;
	friend class XHLayout;
	friend class XApplet;
	friend class XApplication;
	friend class XApplicationProc;
};