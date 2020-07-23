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

	template <class U>
	static std::vector<std::tuple<XHANDLE*, U*, void (U::*)()>> XMapMessages;
	static std::pair<HINSTANCE, LPCWSTR> mainCursor;
	static std::vector<std::pair<XHANDLE*, std::unique_ptr<XApplet>>> XTypes;
	static std::vector<XHANDLE*> XButtonMessages;
	static std::vector<XHANDLE*> XLabelMessages;
	static std::vector<XHANDLE*> XComboBoxMessages;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};

