#pragma once

#define ISOLATION_AWARE_ENABLED 1
#define XWINDOWMINWIDTH 500
#define XWINDOWMINHEIGHT 500

#define SIGNAL(obj, signal) obj, std::bind(signal, obj)
#define SLOT(obj, slot) obj, std::bind(slot, obj)

#define SIGNAL_P(obj, signal) obj, std::bind(signal, obj, std::placeholders::_1)
#define SLOT_P(obj, slot) obj, std::bind(slot, obj, std::placeholders::_1)

//#include <Uxtheme.h>
#include <string>
#include <functional>
#include <algorithm>

#include "XTrackbar.h"
#include "XButton.h"
#include "XLabel.h"
#include "XComboBox.h"
#include "XTextBox.h"
#include "XWindow.h"
#include "XParams.h"
#include "XTypes.h"
#include "XLayout.h"
#include "XVLayout.h"
#include "XHLayout.h"

#include "XApplicationProc.h"

class XApplication : public XWindow
{
public:
	XApplication();
	XApplication(XParams xParams);
	~XApplication() = default;

	//template <class T, class U>
	//void connect(T* applet, uint8_t signal_type, U* object, std::function<void(void)> callback) {
	//	if (applet && signal_type && object && !callback._Empty()) {
	//		switch (signal_type){
	//			case 1: {
	//				XApplicationProc::XCallback.emplace_back(std::make_pair(applet->applet, callback));
	//				break;
	//			}
	//			default:
	//				break;
	//		}
	//	}
	//}

	template <class S>
	void connect(XApplet* signal_object, std::function<S(void)> signal_callback, XApplet* slot_object, std::function<void(S)> slot_callback) {
		if (std::is_same<S, int>::value) {
			XApplicationProc::bunchSignalSlotInteger.emplace_back(signal_object, signal_callback, slot_callback);
		}
	}
	//Без S
	//template <class T, class U>
	void connect(XApplet* signal_object, std::function<void(void)> signal_callback, XApplet* slot_object, std::function<void(void)> slot_callback) {
		XApplicationProc::bunchSignalSlotNonParams.push_back(std::make_tuple(signal_object, signal_callback, slot_callback));
	}

	//template <class T, class U>
	//void connect(T* signal_object, std::function<void()> signal_callback, U* slot_object, std::function<void()> slot_callback) {
	//}

	//template <class T, class U>
	//void connect(T* applet, uint8_t signal_type, U* object, void (U::* callback)()) {
	//	if (applet && signal_type && object && callback != nullptr) {
	//		switch (signal_type) {
	//			case 1: {
	//				std::function<void(void)> fn = std::bind(callback, object);
	//				XApplicationProc::XCallback.emplace_back(std::make_pair(applet->applet, fn));

	//				break;
	//			}

	//			default:
	//				break;
	//		}
	//	}
	//}

	void windowUpdate(void) {
		GetWindowRect(XApplication::XApplicationMainWindow->windowHWND(), &rect);
		SetWindowPos(XApplication::XApplicationMainWindow->windowHWND(), (HWND)NULL, rect.left, rect.top, minimumWidth(), minimumHeight(), (UINT)0);

		XComboBox::applyItems();
		XTrackbar::applyTrackConfiguration();

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

	static LRESULT CALLBACK standartProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
	{
		switch (uMsg)
		{
		case WM_GETMINMAXINFO:
		{
			//GetWindowRect(XApplication::);
			LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
			lpMMI->ptMinTrackSize.x = 200;
			lpMMI->ptMinTrackSize.y = 20;

			lpMMI->ptMaxTrackSize.x = 500;
			lpMMI->ptMaxTrackSize.y = 500;
		}
		case WM_MOUSEMOVE:
			//SetCursor(LoadCursor(NULL, IDC_HAND));
			break;

		case WM_LBUTTONDOWN:
			//MessageBoxA(hWnd, "Button down!", 0, 0);
			OutputDebugStringA("adsad");
			break;

		case WM_NCDESTROY:
			RemoveWindowSubclass(hWnd, standartProc, uIdSubclass);
			break;
		}

		return DefSubclassProc(hWnd, uMsg, wParam, lParam);
	}

	template <class T>
	void appendApplet(T* applet, void (*pProc)()) {
		applet->setApplet(XApplicationMainWindow, LayoutDirection::None, appletId++, false);

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XApplets.emplace_back(reinterpret_cast<XApplet*>(applet));
			applet->disp->setSubClass(applet, standartProc);
			//XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XLabel>::value) {
			XApplicationProc::XApplets.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XLabelMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XApplets.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
		else if (std::is_same<T, XTextBox>::value) {
			XApplicationProc::XApplets.emplace_back(reinterpret_cast<XApplet*>(applet));
			//XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->applet->window->_wnd));
		}
	}

	template <class T>
	void appendApplet(T* applet) {
		//WTF???!!!
		XVLayout* l = new XVLayout();
		applet->setApplet(XApplicationMainWindow->windowHWND(), l, appletId++, false);
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
	virtual void setWindowName(std::wstring) override {};


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
	//friend BOOL CALLBACK XApplicationProc::EnumChildProc(HWND, LPARAM);
	friend class XVLayout;
	friend class XHLayout;



	// Унаследовано через XWindow
	virtual bool windowHasMaximumSize() override;

};
