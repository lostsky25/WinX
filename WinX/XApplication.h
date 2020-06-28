#pragma once

#define ISOLATION_AWARE_ENABLED 1
#include "XApplicationProc.h"
//#include <Windows.h>

#include <type_traits>
#include <cstdint>
#include <commctrl.h>

#include "XButton.h"
#include "XComboBox.h"
#include "XParams.h"
<<<<<<< Updated upstream

#define CONNECT(T, APPLET, FPROC) Application->SetClickedEvent<T>(APPLET, FPROC)

=======
#include "XTypes.h"

//#include "XLayout.h"

class XVLayout;
class XHLayout;

#include "XVLayout.h"
#include "XHLayout.h"


#define CONNECT(T, APPLET, FPROC) Application->SetClickedEvent<T>(APPLET, FPROC)

//using namespace XTypes;

>>>>>>> Stashed changes
class XApplication// : XApplicationProc
{


public:
	XApplication();
	XApplication(XParams);

	//template <class T>
	//void AppendApplet(T* applet, void (*pProc)());// {
	//	applet->SetApplet(XApplicationMainWindow, offsetX, offsetY);
	//	offsetX += applet->width;
	//	offsetY += applet->height;
	//	
	//	if (std::is_same<T, XButton>::value) {
	//		XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
	//	}
	//	else if (std::is_same<T, XComboBox>::value){
	//		XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
	//	}
	//	XApplicationProc::XMapMessages.push_back(std::make_pair(reinterpret_cast<HWND>(applet->GetHandle()), pProc));
	//}

	//template <class T>
	//void AppendApplet(T* applet);// {
	//	applet->SetApplet(XApplicationMainWindow, offsetX, offsetY);
	//	offsetX += applet->width;
	//	offsetY += applet->height;
	//}

	//template <class T>
	//void SetClickedEvent(T* applet, void (*pProc)());// {
	//	if(pProc != nullptr)
	//		XApplicationProc::XMapMessages.push_back(std::make_pair(reinterpret_cast<HWND>(applet->GetHandle()), pProc));	
	//}
	template <class T>
<<<<<<< Updated upstream
	void AppendApplet(T* applet, void (*pProc)()) {
		applet->SetApplet(XApplicationMainWindow, offsetX, offsetY);
		offsetX += applet->width;
		offsetY += applet->height;

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
=======
	void appendApplet(T* applet, void (*pProc)()) {
		applet->setApplet(XApplicationMainWindow, vOffsetX, vOffsetY, hOffsetX, hOffsetY, LayoutDirection::None, 0);
		//offsetX += applet->width();
		//offsetY += applet->height();

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->windowHandle()));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->windowHandle()));
>>>>>>> Stashed changes
		}
		//XApplicationProc::XMapMessages.push_back(std::make_pair(reinterpret_cast<HWND>(applet->GetHandle()), pProc));
	}

	template <class T>
<<<<<<< Updated upstream
	void AppendApplet(T* applet) {
		applet->SetApplet(XApplicationMainWindow, offsetX, offsetY);
		offsetX += applet->width;
		offsetY += applet->height;
	}


	
	template <class T, class U>
	void SetClickedEvent(T& applet, U* object, void (U::* pProc)()) {
		if (pProc != nullptr) {
			XApplicationProc::XMapMessages<U>.push_back(std::make_tuple(applet.GetHandle(), object, pProc));
			XApplicationProc::XTypes.emplace_back(std::make_pair(applet.GetHandle(), object));
=======
	void appendApplet(T* applet) {

		/*Y += XLayout::_properties.find(i)->second.second.bottom +
			XLayout::_properties.find(i)->second.second.top +
			_minimumHeight;*/

		applet->setApplet(XApplicationMainWindow, vOffsetX, vOffsetY, hOffsetX, hOffsetY, LayoutDirection::None, 0);
	}

	/*void appendApplet(XVLayout* verticalLayout) {
		for (int i = 0; i < XVLayout::applets<int>.size(); i++)
		{

		}
	}*/


	//void appendApplet(XHLayout layout) {

	//}

	template <class T, class U>
	void setClickedEvent(T& applet, U* object, void (U::* pProc)()) {
		if (pProc != nullptr) {
			XApplicationProc::XMapMessages<U>.push_back(std::make_tuple(applet.windowHandle(), object, pProc));
			XApplicationProc::XTypes.emplace_back(std::make_pair(applet.windowHandle(), object));
>>>>>>> Stashed changes
		}
	}

	//template <class T, class U>
	//void connect(T& object, void (T::* ptr)(), U& object2, void (U::* ptr2)()) {
	//	//*object->slotFoo();
	//	(object.*ptr)();
	//}
	//void AppendHWND(HWND);
<<<<<<< Updated upstream

	
=======
	
	void setCursor(XTypes::XCursor cursor) {
		XApplicationProc::mainCursor.second = cursor.idc();
	}

	void setCursor(LPCWSTR idc) {
		XApplicationProc::mainCursor.second = idc;
	}

	void setLayout(XVLayout*);
	void setLayout(XHLayout*);
	
	//void setCursor(HWND hwnd, XCursor cursor) {
	//	XApplicationProc::cursorsForWindows.emplace_back(std::make_pair(hwnd, cursor.idc()));
	//}

	//void setCursor(HWND hwnd, LPCWSTR idc) {
	//	XApplicationProc::cursorsForWindows.emplace_back(std::make_pair(hwnd, idc));
	//}

>>>>>>> Stashed changes
	HWND GetMainWindowHandle();
	void WindowUpdate(void);

	~XApplication();

private:
	INITCOMMONCONTROLSEX icex;
<<<<<<< Updated upstream
	HWND XApplicationMainWindow;
	
	int offsetX;
	int offsetY;
=======
	static HWND XApplicationMainWindow;
	
	static int vOffsetX;
	static int hOffsetX;
	static int hOffsetY;
	static int vOffsetY;
>>>>>>> Stashed changes

	//For WinAPI window
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;
	LPCWSTR szClassName = L"XApplicationMainWindow";
	MSG XApplicationMessage;
	WNDCLASSEX WndClassEx;
	//static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
protected:
<<<<<<< Updated upstream
	// Унаследовано через XApplicationProc
	
=======
	friend class XVLayout;
	friend class XHLayout;
>>>>>>> Stashed changes

};

//void AppendHWND(HWND h) {
//	XApplication::e.push_back(h);
//}
