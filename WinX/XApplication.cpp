#include "XApplication.h"
#include "XApplicationProc.h"

class XVLayout;
class XHLayout;

//LRESULT CALLBACK XApplicationProc::cursorSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, DWORD_PTR ref_ptr)
//{
//
//}

HWND XApplication::XApplicationMainWindow;
MSG XApplication::XApplicationMessage;
int XApplication::vOffsetX = 0;
int XApplication::vOffsetY = 0;
int XApplication::hOffsetX = 0;
int XApplication::hOffsetY = 0;
int XApplication::appletId = 0;

LRESULT CALLBACK XApplicationProc::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	int index = 0;
	char buff[128];
	int idx_row;

	NMHDR* h = reinterpret_cast<NMHDR*>(lParam);
	//Base* b = types[0]();
	
	switch (uMsg) {
	case WM_NOTIFY:


		break;

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT)
		{	
			SetCursor(LoadCursorW(NULL, XApplicationProc::mainCursor.second));

			//for (int i = 0; i < XApplicationProc::cursorsForWindows.size(); i++)
			//{
			//	
			//	SetWindowSubclass(XApplicationProc::cursorsForWindows.at(i).first, 
			//		XApplicationProc::cursorSubclassProc,
			//		1, 
			//		(DWORD_PTR)NULL);
			//}

			return TRUE;
		}
		break;
	
	case WM_COMMAND:
		for (int i = 0; i < XApplicationProc::XComboBoxMessages.size(); i++) {
			switch (HIWORD(wParam))
			{
			case CBN_SELCHANGE:
				if(XApplicationProc::XComboBoxMessages.at(i) != NULL){
					index = SendMessage(XApplicationProc::XComboBoxMessages.at(i), CB_GETCURSEL, 0, 0);
				}
				break;
			default:
				break;
			}
			break;
		}

		//event click
		switch (LOWORD(wParam))
		{
		case BN_CLICKED:
			for (int i = 0; i < XTypes.size(); i++) {
				if (CurrentHandle == XTypes.at(i).first) {
					//XTypes.at(i).second->clicked();
					XTypes.at(i).second->clickEvent();
				}
			}
			//b->clicked();
			//for (int type_id = 0; type_id < XTypesMessages.size(); type_id++) {
				//typedef std::remove_reference<decltype(XApplicationProc::XTypesMessages[type_id])>::type XType;
					//for (auto& elem : XMapMessages<XType>) {
						//if (CurrentHandle == elem._Myfirst._Val) {
						//	OutputDebugStringA("OOOAFKDSMFL");
					//	}
				//}
			//}
			//std::unique_ptr<Base> temp = qwe[0]();



			//if (CurrentHandle == XMapMessages<MyClass>.operator[]<0>(0)) {
			//	//void (*pProc)() = XMapMessages.at(i).second;
			//	//if ((*pProc) != nullptr)
			//		//(*pProc)();
			//}
			break;
		default:
			break;
		}

		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		DrawText(hDC, L"Hello, World!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

void XApplication::setLayout(XVLayout* layout) {
	bool firstElem = true;
	XLayout::_beginVerticalLayout.push_back(layout->_beginHeight);
	//Extract applets from layouts
	while (!layout->waitingButtonts.empty()) {
		

		layout->waitingButtonts.front()->setApplet(XApplication::XApplicationMainWindow,
			XApplication::vOffsetX, XApplication::vOffsetY,
			XApplication::hOffsetX, XApplication::hOffsetY, layout, appletId++, firstElem);

		//XVLayout::_beginHeight = XLayout::_beginHeight;

		//if (!firstElem) {
			XLayout::_beginHeight += layout->waitingButtonts.front()->_minimumHeight;
		//}

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->waitingButtonts.erase(std::find(layout->waitingButtonts.begin(),
			layout->waitingButtonts.end(), layout->waitingButtonts.front()));
	}
	XLayout::_betweenVeticalApplets = 0;
	//XLayout::_beginHeight = 0;
}

void XApplication::setLayout(XHLayout* layout) {
	bool firstElem = true;
	int max = 0;
	XLayout::_beginHorizontalLayout.push_back(layout->_beginWidth);
	//Extract applets from layouts
	while (!layout->waitingButtonts.empty()) {
		layout->waitingButtonts.front()->setApplet(XApplication::XApplicationMainWindow,
			XApplication::vOffsetX, XApplication::vOffsetY,
			XApplication::hOffsetX, XApplication::hOffsetY, layout, appletId++, firstElem);
			//layout->maxPreviousLayoutWidth, layout->maxPreviousLayoutHeight);
		//XLayout::_beginWidth += layout->waitingButtonts.front()->_minimumWidth;
		//this->_beginWidth = XLayout::_beginWidth;
		for (int i = 0; i < layout->waitingButtonts.size(); i++) {
			
			if (max < layout->waitingButtonts.at(i)->_minimumHeight)
				max = layout->waitingButtonts.at(i)->_minimumHeight;
		}

		if (firstElem) {
			firstElem = !firstElem;
		}
		
		layout->waitingButtonts.erase(std::find(layout->waitingButtonts.begin(),
			layout->waitingButtonts.end(), layout->waitingButtonts.front()));
	}

	XLayout::_beginHeight += max;

	XLayout::_betweenHorizontalApplets = 0;
	//XApplication::hOffsetY = layout->maxPreviousLayoutHeight;

	//while (!XVLayout::waitingComboBox.empty()) {
	//	XVLayout::waitingComboBox.front()->setApplet(XApplication::XApplicationMainWindow, XApplication::offsetX, XApplication::offsetY);
	//	XVLayout::waitingComboBox.pop();
	//}

	/*while (!XHLayout::waitingButtonts.empty()) {
		XHLayout::waitingButtonts.front()->setApplet(XApplication::XApplicationMainWindow, XApplication::offsetX, XApplication::offsetY);
		XHLayout::waitingButtonts.pop();
	}*/

	//while (!XHLayout::waitingComboBox.empty()) {
	//	XHLayout::waitingComboBox.front()->setApplet(XApplication::XApplicationMainWindow, XApplication::offsetX, XApplication::offsetY);
	//	XHLayout::waitingComboBox.pop();
	//}
	//!Extract applets from layouts
}

//template <class T>
//void XApplication::AppendApplet(T btn)
//{	
//	btn.appendApplet(XApplicationMainWindow);
//}

//HWND XApplication::GetMainWindowHandle() {
//	return XApplicationMainWindow;
//}

//XApplication::~XApplication(){
//	//delete XApplicationMainWindow;
//	delete szClassName;
//}

