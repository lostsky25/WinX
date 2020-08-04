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

	~Dispether();
private:
	friend class XApplication;
	friend class XApplet;
	static unsigned subProcId;
	static std::queue<std::pair<XHANDLE*, LRESULT(*)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR)>> waitingSubclasses;
};

