#pragma once

#include "XDebug.h"

#include "XWindowFlags.h"
#include "XWindowType.h"
#include "XSize.h"
#include "XString.h"

#include <WinUser.h>

#define CURSOR_ARROW_SMALL					IDC_APPSTARTING		//Standard arrow and small hourglass
#define CURSOR_ARROW						IDC_ARROW			//Standard arrow
#define CURSOR_CROSSHAIR					IDC_CROSS			//Crosshair
#define CURSOR_HAND							IDC_HAND			//Windows NT 5.0 and later: Hand
#define CURSOR_QUESTION						IDC_HELP			//Arrow and question mark
#define CURSOR_BEAM							IDC_IBEAM			//I - beam
#define CURSOR_ICON							IDC_ICON			//Obsolete for applications marked version 4.0 or later.
#define CURSOR_SLASHED						IDC_NO				//Slashed circle
#define CURSOR_SIZE							IDC_SIZE			//Obsolete for applications marked version 4.0 or later.Use IDC_SIZEALL.
#define CURSOR_SIZEALL						IDC_SIZEALL			//Four - pointed arrow pointing north, south, east, and west
#define CURSOR_POINTED_ARROW				IDC_SIZENESW		//Double - pointed arrow pointing northeast and southwest
#define CURSOR_POINTED_ARROW2				IDC_SIZENS			//Double - pointed arrow pointing north and south
#define CURSOR_POINTED_ARROW3				IDC_SIZENWSE		//Double - pointed arrow pointing northwest and southeast
#define CURSOR_POINTED_ARROW4				IDC_SIZEWE			//Double - pointed arrow pointing west and east
#define CURSOR_POINTED_ARROW_VERTICAL		IDC_UPARROW			//Vertical arrow
#define CURSOR_HOURGLASS					IDC_WAIT			//Hourglass


namespace XTypes{

	typedef struct _XWindowType {
		DWORD type = 0;

		_XWindowType(){}
		_XWindowType(DWORD type) : type(type) {
		}
		
	}XWindowType;


	typedef struct _XMargins {
		//private:
			int left = 0;
			int top = 0;
			int right = 0;
			int bottom = 0;
			
		//public:
			_XMargins(){}
			_XMargins(int left, int top, int right, int bottom) :
				left(left),
				top(top),
				right(right),
				bottom(bottom)
			{
				if (left < 0 || top < 0 || right < 0 || bottom < 0)
				{
					OutLine("You should use absolute values for XMargins.");
				}
			}



	}XMargins;

	typedef struct _XLayoutDirection {
		_XLayoutDirection() {}
	}XLayoutDirection;

	typedef struct _XLayout {
		_XLayout() {}
	}XLayout;

	typedef struct _XRect {
		int x = 0;
		int y = 0;
		int right = 0;
		int bottom = 0;
		
		_XRect(){}
		_XRect(int x, int y, int right, int bottom) :
			x(x),
			y(y),
			right(right),
			bottom(bottom)
		{
		}
	}XRect;

	typedef struct _XCursor {
		private:
			HCURSOR _cursor = nullptr;
			LPCWSTR _idc = nullptr;

		public:
			_XCursor() {
				this->_cursor = NULL;
				this->_idc = NULL;
			}

			void setCursor(LPCWSTR idc) {
				if (idc != NULL)
				{
					this->_idc = idc;
					this->_cursor = LoadCursorW(NULL, this->_idc);
					if (this->_cursor == NULL)
					{
						OutLine("You have an error with cursor name. Check the CURSOR_*.");
					}
				}
				else {
					OutLine("You have an empty idc. Check the pointer.");
				}
			}

			HCURSOR cursor(void) {
				return this->_cursor;
			}

			LPCWSTR idc(void) {
				return this->_idc;
			}
	}XCursor;

	typedef struct _XFocusPolicy {
		_XFocusPolicy() {}
	}XFocusPolicy;

	typedef struct _XPalette {
		_XPalette() {}
	}XPalette;

	typedef struct _XPoint {
		int x = 0;
		int y = 0;
		_XPoint() {}
	}XPoint;

	typedef struct _XWindowState {
		LONG _state = WS_CHILD | WS_VISIBLE;

		_XWindowState() {}
		
		//void overlapped(bool state) {
		//	if (state) {
		//		/*_state |= (WS_OVERLAPPED | 
		//			WS_CAPTION | 
		//			WS_SYSMENU | 
		//			WS_THICKFRAME | 
		//			WS_MINIMIZEBOX | 
		//			WS_MAXIMIZEBOX);*/
		//	}
		//	else {
		//		/*_state &= (WS_OVERLAPPED | 
		//			WS_CAPTION | 
		//			WS_SYSMENU | 
		//			WS_THICKFRAME | 
		//			WS_MINIMIZEBOX | 
		//			WS_MAXIMIZEBOX);*/
		//	}
		//}

	}XWindowState;

	typedef struct _XIcon {
		_XIcon() {}
	}XIcon;
}