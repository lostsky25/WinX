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

#include "XTypes.h"

#include "XLayout.h"


#include "XVLayout.h"
#include "XHLayout.h"


#define CONNECT(T, APPLET, FPROC) Application->SetClickedEvent<T>(APPLET, FPROC)

//using namespace XTypes;

class XApplication// : XApplicationProc
{


public:
	XApplication() {

	}

	XApplication(XParams xParams) {
		// Ensure that the common control DLL is loaded. 
		icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
		icex.dwICC = ICC_LISTVIEW_CLASSES;
		InitCommonControlsEx(&icex);

		offsetX = 0;
		offsetY = 0;

		WndClassEx.cbSize = sizeof(WndClassEx);
		WndClassEx.lpfnWndProc = ::XApplicationProc::WndProc;
		WndClassEx.style = CS_HREDRAW | CS_VREDRAW; //---> устанавливаются поразрядные флаги (bit flags), так как только один разряд установлен в единичное значение.

		/*
			CS_GLOBALCLASS - Создать класс, доступный всем приложениям. Обычно этот стиль применяется для создания определяемых пользователем элементов управления в DLL.
			CS_HREDRAW - Перерисовывать все окно, если изменен размер по горизонтали.
			CS_NOCLOSE - Запретить команду Close в системном меню.
			CS_OWNDC - Выделить уникальный контекст устройства для каждого окна, созданного при помощи этого класса.
			CS_VREDRAW - Перерисовывать все окно, если изменен размер по вертикали.
		*/

		WndClassEx.cbClsExtra = 0;
		WndClassEx.cbWndExtra = 0;
		WndClassEx.hInstance = xParams.hInstance;
		WndClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClassEx.hIcon = LoadIcon(xParams.hInstance, MAKEINTRESOURCE("w102.ico"));
		WndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClassEx.lpszMenuName = NULL;
		WndClassEx.lpszClassName = szClassName;
		WndClassEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		WndClassEx.hIconSm = LoadIcon(xParams.hInstance, MAKEINTRESOURCE("w102.ico"));
		//!Заполнить структуру окна

		if (!RegisterClassEx(&WndClassEx)) {
			//return EXIT_FAILURE;
		}

		XApplicationMainWindow = CreateWindow(szClassName, L"Window title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, (HWND)NULL, (HMENU)NULL, (HINSTANCE)xParams.hInstance, NULL);
		/*
			CS_ - Опция стиля класса
			CW_ - Опция создания окна
			DT_ - Опция рисования текста
			IDC_ - Идентификатор предопределенного курсора
			IDI_ - Иденитификатор предопределенной иконки (пиктограммы)
			WM_ - Сообщение окна
			WS_ - Стиль окна
		*/

		if (!XApplicationMainWindow) {
			//return EXIT_FAILURE;
		}

		ShowWindow(XApplicationMainWindow, xParams.nCmdShow);

		//auto lambdaWindowUpdate = [=] { WindowUpdate(); };
		//std::thread XApplicationWindowUpdate(lambdaWindowUpdate);
		//
		//std::thread t2(&XApplication::WindowUpdate, this);
		//t2.join();

		//return XApplicationMessage.wParam;
	}

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
		applet->setApplet(XApplicationMainWindow, vOffsetX, vOffsetY, hOffsetX, hOffsetY, LayoutDirection::None, 0);
		offsetX += applet->_width;
		offsetY += applet->_height;

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->GetHandle()));
		}
	}

	template <class T>
	void appendApplet(T* applet, void (*pProc)()) {
		applet->setApplet(XApplicationMainWindow, vOffsetX, vOffsetY, hOffsetX, hOffsetY, LayoutDirection::None, 0);
		//offsetX += applet->width();
		//offsetY += applet->height();

		if (std::is_same<T, XButton>::value) {
			XApplicationProc::XButtonMessages.push_back(reinterpret_cast<HWND>(applet->windowHandle()));
		}
		else if (std::is_same<T, XComboBox>::value) {
			XApplicationProc::XComboBoxMessages.push_back(reinterpret_cast<HWND>(applet->windowHandle()));
		}
		//XApplicationProc::XMapMessages.push_back(std::make_pair(reinterpret_cast<HWND>(applet->GetHandle()), pProc));
	}

	template <class T>
	void AppendApplet(T* applet) {
		applet->setApplet(XApplicationMainWindow, vOffsetX, vOffsetY, hOffsetX, hOffsetY, LayoutDirection::None, 0);
		offsetX += applet->_width;
		offsetY += applet->_height;
	}


	
	template <class T, class U>
	void SetClickedEvent(T& applet, U* object, void (U::* pProc)()) {
		if (pProc != nullptr) {
			XApplicationProc::XMapMessages<U>.push_back(std::make_tuple(applet.GetHandle(), object, pProc));
			XApplicationProc::XTypes.emplace_back(std::make_pair(applet.GetHandle(), object));
		}
	}

	template <class T>
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
		}
	}

	//template <class T, class U>
	//void connect(T& object, void (T::* ptr)(), U& object2, void (U::* ptr2)()) {
	//	//*object->slotFoo();
	//	(object.*ptr)();
	//}
	//void AppendHWND(HWND);
	
	void setCursor(XTypes::XCursor cursor) {
		XApplicationProc::mainCursor.second = cursor.idc();
	}

	void setCursor(LPCWSTR idc) {
		XApplicationProc::mainCursor.second = idc;
	}

	void setLayout(XVLayout* layout);
	void setLayout(XHLayout* layout);
	
	//void setCursor(HWND hwnd, XCursor cursor) {
	//	XApplicationProc::cursorsForWindows.emplace_back(std::make_pair(hwnd, cursor.idc()));
	//}

	//void setCursor(HWND hwnd, LPCWSTR idc) {
	//	XApplicationProc::cursorsForWindows.emplace_back(std::make_pair(hwnd, idc));
	//}

	//HWND GetMainWindowHandle();
	void WindowUpdate(void) {
		while (GetMessage(&XApplicationMessage, NULL, 0, 0)) {
			XApplicationProc::CurrentHandle = XApplicationMessage.hwnd;
			TranslateMessage(&XApplicationMessage);
			DispatchMessage(&XApplicationMessage);
		}
	}

	//~XApplication();

private:
	INITCOMMONCONTROLSEX icex;
	
	int offsetX;
	int offsetY;
	static HWND XApplicationMainWindow;
	
	static int vOffsetX;
	static int hOffsetX;
	static int hOffsetY;
	static int vOffsetY;

	//For WinAPI window
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;
	LPCWSTR szClassName = L"XApplicationMainWindow";
	static MSG XApplicationMessage;
	WNDCLASSEX WndClassEx;
	//static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
protected:
	// Унаследовано через XApplicationProc
	
	friend class XVLayout;
	friend class XHLayout;
};

//void AppendHWND(HWND h) {
//	XApplication::e.push_back(h);
//}
