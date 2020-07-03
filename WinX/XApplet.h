#pragma once
#define ISOLATION_AWARE_ENABLED 1
#include <Windows.h>
#include <commctrl.h>
#include <atlbase.h>

#include "XLayout.h"
#include "XTypes.h"
#include "XString.h"
#include "XDebug.h"
#include "XWindow.h"

class XApplet : public XWindow
{
public:
	HWND windowHandle() override;
	void windowUpdate() override;
	//void setMinimumWidth(int) override;
	//void setMinimumHeight(int) override;
	void setMaximumHeight(int) override;
	void setMaximumSize(XTypes::XSize) override;
	void setMaximumSize(int, int) override;
	void setMaximumWidth(int) override;
	void setMinimumSize(int, int) override;
	void setMinimumSize(XTypes::XSize) override;
	int maximumHeight() override;
	XTypes::XSize maximumSize() override;
	int maximumWidth() override;
	int minimumHeight() override;
	XTypes::XSize minimumSize() override;
	int minimumWidth() override;
	XTypes::XRect frameGeomtry() override;
	void setText(LPCSTR) override;
	bool isFullScreen() override;
	bool isActiveWindow() override;
	bool isWindow() override;
	//int width() override;
	//int height() override;
	XTypes::XMargins margins() override;
	//void windowUpdate() override;
	//void setMargins(XTypes::XMargins);
	//void setMargins(int, int, int, int);

	virtual void setWindowTitle(XString) = 0;
	virtual XString windowTitle() = 0;
	virtual XTypes::XSize iconSize() = 0;
	virtual void setWindowState(XTypes::XWindowState) = 0;
	virtual XTypes::XSize size() = 0;
	virtual XTypes::XSize sizeIncrement() = 0;
	virtual void setBaseSize(XTypes::XSize) = 0;
	virtual void setBaseSize(int, int) = 0;
	virtual XTypes::XWindowFlags windowFlags() = 0;
	virtual XTypes::XIcon windowIcon() = 0;
	virtual float windowOpacity() = 0;
	virtual XTypes::XWindowState windowState() = 0;
	virtual XTypes::XWindowType windowType() = 0;
	//virtual void setWindowFlags(XTypes::XWindowFlags, bool = true) = 0;
	virtual void setWindowIcon(XTypes::XIcon) = 0;
	virtual void setWindowOpacity(float) = 0;
	virtual void setFixedHeight(int) = 0;
	virtual void setFixedSize(XTypes::XSize) = 0;
	virtual void setFixedSize(int, int) = 0;
	virtual void activateWindow() = 0;

	virtual void setMinimumWidth(int);
	virtual void setMinimumHeight(int);
	virtual int width() = 0;
	virtual int height() = 0;

protected:
	//HWND GetHandle();
	int _width;
	int _height;

	/*
	* Applet is window handle, it just means HWND.
	*/
	HWND applet;													//Applet handle.
	LPCSTR _text;													//Text in applet (this parameter use in XButton etc.).
	XTypes::XCursor _cursor;										//Cursor when hovering the applet.
	//XTypes::XLayoutDirection _layoutDirection;						//Layout direction for the another.

	virtual void setApplet(HWND, int&, int&, int&, int&, int, int, int) = 0;						//Set applet into ...
};

