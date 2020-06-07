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

#define CONNECT(T, APPLET, FPROC) Application->SetClickedEvent<T>(APPLET, FPROC)

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
	void AppendApplet(T* applet, void (*pProc)()) {
		applet->SetApplet(XApplicationMainWindow, offsetX, offsetY);
		offsetX += applet->width;
		offsetY += applet->height;

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
		}
		//XApplicationProc::XMapMessages.push_back(std::make_pair(reinterpret_cast<HWND>(applet->GetHandle()), pProc));
	}

	template <class T>
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
		}
	}

	//template <class T, class U>
	//void connect(T& object, void (T::* ptr)(), U& object2, void (U::* ptr2)()) {
	//	//*object->slotFoo();
	//	(object.*ptr)();
	//}
	//void AppendHWND(HWND);

	
	HWND GetMainWindowHandle();
	void WindowUpdate(void);

	~XApplication();

private:
	INITCOMMONCONTROLSEX icex;
	HWND XApplicationMainWindow;
	
	int offsetX;
	int offsetY;

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
	// Унаследовано через XApplicationProc
	

};

//void AppendHWND(HWND h) {
//	XApplication::e.push_back(h);
//}
