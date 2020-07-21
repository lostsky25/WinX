#pragma once

#define ISOLATION_AWARE_ENABLED 1

//#include "xhandle.h"

#include "XApplicationProc.h"

#include <type_traits>
#include <cstdint>
#include <commctrl.h>
#include <algorithm>

#include "XButton.h"
#include "XComboBox.h"
#include "XParams.h"

//#define CONNECT(T, APPLET, FPROC) Application->SetClickedEvent<T>(APPLET, FPROC)

#include "XTypes.h"

#include "XLayout.h"

#include "XWindow.h"

#include "XVLayout.h"
#include "XHLayout.h"

//#include <Uxtheme.h>

//#define CONNECT(T, APPLET, FPROC) Application->SetClickedEvent<T>(APPLET, FPROC)

class XVLayout;
class XHLayout;

class XApplication : XApplet
{
public:
	XApplication();
	XApplication(XParams xParams);
	~XApplication() = default;

	template <class T, class U>
	void setClickedEvent(T& applet, U* object, void (U::* pProc)()) {
		if (pProc != nullptr) {
			XApplicationProc::XMapMessages<U>.push_back(std::make_tuple(applet.applet, object, pProc));
			XApplicationProc::XTypes.emplace_back(applet.applet, object);
		}
	}

	void windowUpdate(void) {
		while (GetMessage(&XApplicationMessage, NULL, 0, 0)) {
			XApplicationProc::CurrentHandle = XApplicationMessage.hwnd;
			TranslateMessage(&XApplicationMessage);
			DispatchMessage(&XApplicationMessage);
		}
	}

	void setCursor(LPCWSTR idc) {
		XApplicationProc::mainCursor.second = idc;
	}

	void setCursor(XTypes::XCursor cursor) {
		XApplicationProc::mainCursor.second = cursor.idc();
	}

	template <class T>
	void appendApplet(T* applet, void (*pProc)()) {
		applet->setApplet(XApplicationMainWindow, LayoutDirection::None, appletId++, false);

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
	}

	template <class T>
	void appendApplet(T* applet) {
		//WTF???!!!
		XVLayout* l = new XVLayout();
		applet->setApplet(XApplicationMainWindow->window->_wnd, l, appletId++, false);
	}

	void setLayout(XHLayout*);
	void setLayout(XVLayout*);

private:
	INITCOMMONCONTROLSEX icex;

	static int appletId;
	static XHANDLE* XApplicationMainWindow;

	//Application instance handle.
	HINSTANCE hInstance;
	//It doesn't use in the latest versions. Simple plug.
	HINSTANCE hPrevInstance;
	//For console mode.
	LPSTR lpCmdLine;
	//First element or not.
	bool firstElem;
	//Maximum value (top margin + minimum height + bottom). When you try to set all applets from some layout.
	int max;
	//Window display mode.
	int nCmdShow;
	LPCWSTR szClassName;
	static MSG XApplicationMessage;
	WNDCLASSEX WndClassEx;

protected:
	friend class XVLayout;
	friend class XHLayout;

};
