#pragma once
#include <Windows.h>
#include <commctrl.h>
#include <vector>

#include "xhandle.h"

class Dispether
{
public:
	Dispether();

	void setSubClass(XHANDLE* xhandle, LRESULT(*wndProc)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR))
	{
		waitingSubclasses.emplace_back(xhandle, wndProc);
	}


	~Dispether();
private:
	friend class XApplication;
	static unsigned subProcId;
	static std::vector<std::pair<XHANDLE*, LRESULT(*)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR)>> waitingSubclasses;
};

