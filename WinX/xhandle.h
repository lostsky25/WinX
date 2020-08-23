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

class XHANDLE
{
public:
	XHANDLE();

	HWND windowHWND();
	void setWindowHWND(HWND);
	XMargins windowMargins();
	XRect windowRect();

	void setMaximumHeight(int);
	void setMaximumWidth(int);
	void setMinimumHeight(int);
	void setMinimumWidth(int);

	int maximumHeight();
	int maximumWidth();
	int minimumHeight();
	int minimumWidth();

	~XHANDLE();

private:
	class __xhandle
	{
	private:
		HWND wnd;														//The main window handle.
		XMargins margins;												//Window margins (left, top, right, bottom).
		XRect rect;														//Window rectangle (x, y, right, bottom).

		int maximumHeight = 0;											//Maximum window height.
		int maximumWidth = 0;											//Maximum window width.
		int minimumHeight = 0;											//Minimum window height.
		int minimumWidth = 0;											//Minimum window width.

	protected:
		//friend class XButton;
		//friend class XTextBox;
		//friend class XComboBox;
		//friend class XLabel;
		//friend class XVLayout;
		//friend class XHLayout;
		//friend class XApplet;
		//friend class XApplication;
		//friend class XApplicationProc;
		friend class XHANDLE;
		//friend class Dispether;
	};

	__xhandle *window;

protected:
	//friend class XButton;
	//friend class XTextBox;
	//friend class XComboBox;
	//friend class XLabel;
	//friend class XVLayout;
	//friend class XHLayout;
	//friend class XApplet;
	friend class XApplication;
	friend class XApplicationProc;
	friend class Dispether;
};