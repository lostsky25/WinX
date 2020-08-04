#pragma once

#define ISOLATION_AWARE_ENABLED 1

#define XWINDOWMINWIDTH 500
#define XWINDOWMINHEIGHT 500

//#include "xhandle.h"

#include "XApplicationProc.h"

#include <type_traits>
#include <cstdint>
#include <commctrl.h>
#include <algorithm>

#include "XButton.h"
#include "XLabel.h"
#include "XComboBox.h"
#include "XTextBox.h"
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
class XButton;

class XApplication : public XWindow
{
public:
	XApplication();
	XApplication(XParams xParams);
	~XApplication() = default;

	//It needs change to connect function.
	template <class T, class U>
	void connect(T* applet, U* object/*, void (U::* pProc)()*/) {
		if (applet && object) {
			XApplicationProc::XTypes.emplace_back(std::make_pair(applet->applet, object));
		}
	}

	void windowUpdate(void) {

		while (GetMessage(&XApplicationMessage, NULL, 0, 0)) {
			XApplicationProc::CurrentHandle = XApplicationMessage.hwnd;

			XApplicationProc::applyOpacity();
			Dispether::applySubClasses();

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
			XApplicationProc::XMessages.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XLabel>::value) {
			XApplicationProc::XMessages.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XLabelMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XMessages.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XTextBox>::value) {
			XApplicationProc::XMessages.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
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


	// Унаследовано через XWindow
	virtual XHANDLE* windowHandle() override;

	virtual void setPosition(int x, int y) override;

	virtual void setMinimumHeight(int height) override;

	virtual void setMaximumHeight(int height) override;

	virtual void setMinimumWidth(int width) override;

	virtual void setMaximumWidth(int width) override;

	virtual void setMinimumSize(XSize size) override;

	virtual void setMinimumSize(int width, int height) override;

	virtual void setMaximumSize(XSize size) override;

	virtual void setMaximumSize(int, int) override;

	virtual int minimumHeight() override;

	virtual int maximumHeight() override;

	virtual int minimumWidth() override;

	virtual int maximumWidth() override;

	virtual XSize minimumSize() override;

	virtual XSize maximumSize() override;

	virtual bool isFullScreen() override;

	virtual bool isActiveWindow() override;

	virtual void setOpacity(float) override;

	virtual int width() override;

	virtual int height() override;

	virtual XMargins margins() override {
		return XMargins(0, 0, 0, 0);
	}
	virtual void setMargins(int, int, int, int) override {};
	virtual void setWindowName(XString) override {};


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
	static RECT rect;

protected:
	friend LRESULT CALLBACK XApplicationProc::WndProc(HWND, UINT, WPARAM, LPARAM);
	friend class XVLayout;
	friend class XHLayout;


};
