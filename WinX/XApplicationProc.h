#pragma once
#include <Windows.h>
#include <vector>
#include <queue>
#include <functional>

#include "xhandle.h"
#include "XApplet.h"

//#include "XTrackbar.h"
//#include "XButton.h"
//#include "XLabel.h"
//#include "XComboBox.h"
//#include "XTextBox.h"
//#include "XParams.h"
//#include "XTypes.h"
//#include "XLayout.h"
//#include "XVLayout.h"
//#include "XHLayout.h"

class XApplicationProc
{
public:
	static HWND CurrentHandle;
	static std::pair<HINSTANCE, LPCWSTR> mainCursor;
	static std::queue<std::pair<XHANDLE*, float>> waitingOpacity;
	static std::vector<std::pair<XHANDLE*, std::function<void(void)>>> XCallback;
	static std::vector<std::pair<XApplet*, std::pair<std::function<int(HWND)>, std::function<void(int)>>>> bunchSignalSlot;
	static std::vector<XApplet*> XApplets;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	//static BOOL CALLBACK EnumChildProc(HWND, LPARAM);

	static void applyOpacity() {
		while (!waitingOpacity.empty())
		{
			SetLayeredWindowAttributes(waitingOpacity.front().first->windowHWND(), 0, 255 - (255 * waitingOpacity.front().second), LWA_ALPHA);
			waitingOpacity.pop();
		}
	}

protected:
	friend class XLabel;
	friend class XButton;
	friend class XTextBox;
	friend class XComboBox;
	friend class XApplication;
	friend class XApplicationProc;
};

