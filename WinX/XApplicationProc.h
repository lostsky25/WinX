#pragma once
#include <Windows.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <typeinfo>
#include <type_traits>
#include <memory>

#include "Base.h"


class XApplicationProc
{
public:
	//static std::map<std::pair<HWND, int>, std::string> XMapMessages;

	static HWND CurrentHandle;

	template <class U>
	static std::vector<std::tuple<HWND, U*, void (U::*)()>> XMapMessages;
	//static std::vector<std::reference_wrapper<const std::type_info>> XTypesMessages;
	static std::vector<std::pair<HWND, std::unique_ptr<Base>>> XTypes;
	//template <class T>
	//static std::vector<> XTypesMessages;
	static std::vector<HWND> XButtonMessages;
	static std::vector<HWND> XComboBoxMessages;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};

