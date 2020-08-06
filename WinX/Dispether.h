#pragma once
#include <Windows.h>
#include <commctrl.h>
#include <queue>

#include "xhandle.h"

class Dispether
{
public:
	Dispether();

	static void applySubClasses() {
		while (!waitingSubclasses.empty())
		{
			SetWindowSubclass(waitingSubclasses.front().first->window->_wnd, waitingSubclasses.front().second, ++subProcId, NULL);
			waitingSubclasses.pop();
		}
	}

	//static void applyStandartSubClasses(XHANDLE* xhandle, LRESULT(*wndProc)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR)) {
	//	SetWindowSubclass(xhandle->window->_wnd, wndProc, 0, 0);
	//}

	void setSubClass(XHANDLE* xhandle, LRESULT(*wndProc)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR))
	{
		waitingSubclasses.emplace(xhandle, wndProc);
	}

	~Dispether();
private:
	friend class XApplication;
	friend class XApplet;
	static unsigned subProcId;
	static std::queue<std::pair<XHANDLE*, LRESULT(*)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR)>> waitingSubclasses;
};

