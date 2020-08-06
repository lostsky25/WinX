#pragma once
#include <map>
#include <queue>
#include <Windows.h>
#include <commctrl.h>

//#include "XApplet.h"
#include "XTypes.h"

#include "xhandle.h"

class XApplet;

enum class LayoutDirection {
	Vertical = 0,
	Horizontal = 1,
	None = 2,
};

class XLayout
{
public:
	static std::vector<std::pair<XRect, XMargins>> properties;					//Window margins (left, top, right, bottom).	
	static std::vector<XApplet*> applets;

protected:
	static LRESULT CALLBACK standartProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
	{
		switch (uMsg)
		{
		case WM_GETMINMAXINFO:
		{
			LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
			lpMMI->ptMinTrackSize.x = 200;
			lpMMI->ptMinTrackSize.y = 20;

			lpMMI->ptMaxTrackSize.x = 500;
			lpMMI->ptMaxTrackSize.y = 500;
		}
		case WM_SIZE: {

			break;
		}
		case WM_MOUSEMOVE:
			break;

		case WM_LBUTTONDOWN:
			char buf[128];
			sprintf(buf, "Addr: 0x%p Clicked\n", hWnd);
			OutputDebugStringA(buf);
			break;

		case WM_NCDESTROY:
			RemoveWindowSubclass(hWnd, standartProc, uIdSubclass);
			break;
		}
		return DefSubclassProc(hWnd, uMsg, wParam, lParam);
	}

	friend class XApplicationProc;
	friend class XApplication;
	friend class XApplet;

	static RECT rect;

	static int beginHeight;
	static int beginWidth;
	static int beginHeightMargins;
	static int beginWidthMargins;

	static int betweenVeticalApplets;
	static int betweenHorizontalApplets;
	static int appletId;

	int count = 0;
	static int layoutId;

	int id = 0;

	static std::vector<int> beginVerticalLayout;
	static std::vector<int> beginHorizontalLayout;
	static std::vector<int> maxHorizontalElement;
	static std::vector<int> maxVerticalElement;

	std::vector<XApplet*> XWaiting;

	LayoutDirection dir = LayoutDirection(0);													//Current direction.
	virtual void deleteApplet(int) = 0;															//Delete some applet by id.
	virtual void destroyedLayout() = 0;															//Clear layout and freeing up memory.
	virtual void activate() = 0;																//By default -> true;
	virtual void addSpacing(int) = 0;															//Set spacing between applets.
	
	//virtual int count() = 0;																	//Get count of applets in the layout.
};
