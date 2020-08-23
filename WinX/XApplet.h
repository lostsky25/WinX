#pragma once
#include "XWindow.h"
#include "XApplicationProc.h"

//#define ISOLATION_AWARE_ENABLED 1

class XApplet : public XWindow
{
public:
	virtual ~XApplet();

	XHANDLE* windowHandle();

	void setMinimumHeight(int);
	void setMaximumHeight(int);

	void setMinimumWidth(int);
	void setMaximumWidth(int);

	void setMinimumSize(XSize);
	void setMinimumSize(int, int);

	void setMaximumSize(XSize);
	void setMaximumSize(int, int);

	int minimumHeight();
	int maximumHeight();

	int minimumWidth();
	int maximumWidth();
	
	XSize minimumSize();
	XSize maximumSize();

	XMargins margins();
	void setPosition(int, int);
	void setWindowName(XString);
	void setMargins(int, int, int, int);

	XWindowType windowType();
	void setWindowType(DWORD);
	bool isFullScreen();
	bool isActiveWindow();
	XSize iconSize();
	XSize size();
	XSize sizeIncrement();
	XWindowFlags windowFlags();
	void setFixedSize(XSize);
	void setFixedSize(int, int);
	void setBorder();
	void activateWindow();

	virtual bool windowHasMaximumSize() override;

	int width();
	int height();

	void setOpacity(float);

	Dispether* disp;

	static uint8_t clicked;

protected:
	XHANDLE* applet;														//Applet handle.
	XString text;															//Text in applet (this parameter use in XButton etc.).
	XTypes::XCursor cursor;													//Cursor when hovering the applet.

	virtual void setApplet(XHANDLE*, XLayout*, int, bool);					//Set applet into ...

	friend class XApplicationProc;
	friend class XApplication;
	friend class XHLayout;
	friend class XVLayout;
};

