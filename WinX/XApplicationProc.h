#pragma once
#include <Windows.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <typeinfo>
#include <type_traits>
#include <memory>
#include "XApplet.h"

#include "xhandle.h"

class XApplicationProc
{
public:
	static HWND CurrentHandle;

	//template <class U>
	//static std::vector<std::tuple<XHANDLE*, U*, void (U::*)()>> XMapMessages;
	static std::pair<HINSTANCE, LPCWSTR> mainCursor;
	static std::vector<std::pair<XHANDLE*, std::unique_ptr<XApplet>>> XTypes;
	static std::queue<std::pair<XHANDLE*, float>> waitingOpacity;
	static std::vector<XApplet*> XMessages;/*
	static std::vector<XHANDLE*> XButtonMessages;
	static std::vector<XHANDLE*> XLabelMessages;
	static std::vector<XHANDLE*> XComboBoxMessages;*/
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	static void applyOpacity() {
		while (!waitingOpacity.empty())
		{
			SetLayeredWindowAttributes(waitingOpacity.front().first->window->_wnd, 0, 255 - (255 * waitingOpacity.front().second), LWA_ALPHA);
			waitingOpacity.pop();
		}
	}

};

