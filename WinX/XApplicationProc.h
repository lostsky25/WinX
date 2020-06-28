#pragma once
#include <Windows.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <typeinfo>
#include <type_traits>
#include <memory>

<<<<<<< Updated upstream
#include "Base.h"
=======
#include "XEvent.h"
>>>>>>> Stashed changes


class XApplicationProc
{
public:
	//static std::map<std::pair<HWND, int>, std::string> XMapMessages;

	static HWND CurrentHandle;
<<<<<<< Updated upstream

	template <class U>
	static std::vector<std::tuple<HWND, U*, void (U::*)()>> XMapMessages;
	//static std::vector<std::reference_wrapper<const std::type_info>> XTypesMessages;
	static std::vector<std::pair<HWND, std::unique_ptr<Base>>> XTypes;
=======
	static std::pair<HINSTANCE, LPCWSTR> mainCursor;
	//static std::vector<std::pair<HWND, LPCWSTR>> cursorsForWindows;

	template <class U>
	static std::vector<std::tuple<HWND, U*, void (U::*)()>> XMapMessages;
	//static LRESULT CALLBACK cursorSubclassProc(HWND, UINT, WPARAM, LPARAM, DWORD_PTR);
	//static std::vector<std::reference_wrapper<const std::type_info>> XTypesMessages;
	static std::vector<std::pair<HWND, std::unique_ptr<XEvent>>> XTypes;
>>>>>>> Stashed changes
	//template <class T>
	//static std::vector<> XTypesMessages;
	static std::vector<HWND> XButtonMessages;
	static std::vector<HWND> XComboBoxMessages;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};

