#pragma once

#include <Windows.h>
#include <memory>
#include "XTypes.h"

class __xhandle
{
public:
	HWND _wnd;
	XTypes::XMargins _margins;					//Window margins (left, top, right, bottom).
	XTypes::XRect _rect;							//Window rectangle (x, y, right, bottom).

	int _maximumHeight = 0;											//Maximum window height.
	int _maximumWidth = 0;											//Maximum window width.
	int _minimumHeight = 0;											//Minimum window height.
	int _minimumWidth = 0;											//Minimum window width.
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
	friend class XVLayout;
	friend class XHLayout;
	friend class XApplet;
	friend class XApplication;
	friend class XApplicationProc;
};