#pragma once
#define ISOLATION_AWARE_ENABLED 1
#include <Windows.h>
#include <commctrl.h>
#include <atlbase.h>
#include <stdexcept>

#include "xhandle.h"

#include "XLayout.h"

//////////
//#include "XHLayout.h"
//#include "XVLayout.h"
//////////

#include "XTypes.h"
#include "XString.h"
#include "XDebug.h"
#include "XWindow.h"

class XLayout;

class XApplet : public XWindow
{
public:
	//XApplet();

	XHANDLE* windowHandle() override;
	void windowUpdate() override;
	void setMaximumHeight(int) override;
	void setMaximumSize(XSize) override;
	void setMaximumSize(int, int) override;
	void setMaximumWidth(int) override;
	void setMinimumSize(int, int) override;
	void setMinimumSize(XSize) override;
	int maximumHeight() override;
	XSize maximumSize() override;
	int maximumWidth() override;
	int minimumHeight() override;
	XSize minimumSize() override;
	int minimumWidth() override;
	XTypes::XRect frameGeomtry() override;
	bool isFullScreen() override;
	bool isActiveWindow() override;
	bool isWindow() override;
	XTypes::XMargins margins() override;
	virtual void updateSize() override;
	virtual void setPosition(int, int) override;
	virtual void setWindowOpacity(float) override;
	virtual float windowOpacity() override; 
	void setText(XString) override;
	virtual void setMargins(int, int, int, int) override;


	virtual XWindowType windowType();
	virtual void setWindowType(DWORD);
	virtual void setWindowTitle(XString);
	virtual XString windowTitle();
	virtual XSize iconSize();
	virtual void setWindowState(XTypes::XWindowState);
	virtual XSize size();
	virtual XSize sizeIncrement();
	virtual void setBaseSize(XSize);
	virtual void setBaseSize(int, int);
	virtual XWindowFlags windowFlags();
	virtual XTypes::XIcon windowIcon();
	virtual XTypes::XWindowState windowState();
	virtual void setWindowIcon(XTypes::XIcon);
	virtual void setFixedHeight(int);
	virtual void setFixedWidth(int);
	virtual void setFixedSize(XSize);
	virtual void setFixedSize(int, int);
	virtual void activateWindow();

	virtual void setMinimumWidth(int);
	virtual void setMinimumHeight(int);

	/// <summary>
	/// This getter needs for information about (minimum) width of applet.
	/// </summary>
	/// <returns>width of appplet</returns>
	virtual int width();

	/// <summary>
	/// This getter needs for information about (minimum) height of applet.
	/// </summary>
	/// <returns>height of appplet</returns>
	virtual int height();

protected:
	int _width = 0;
	int _height = 0;

	//Applet is window handle, it just means HWND.
	//HWND applet = nullptr;												//Applet handle.
	XHANDLE* applet;														//Applet handle.
	XString _text = nullptr;												//Text in applet (this parameter use in XButton etc.).
	XTypes::XCursor _cursor;												//Cursor when hovering the applet.
	std::vector<std::pair<XTypes::XRect, XTypes::XMargins>> _properties;
	virtual void setApplet(XHANDLE*, XLayout*, int, bool);					//Set applet into ...
};

