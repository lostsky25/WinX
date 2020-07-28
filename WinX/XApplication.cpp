#include "XApplication.h"
#include "XApplicationProc.h"

class XVLayout;
class XHLayout;

XHANDLE* XApplication::XApplicationMainWindow;
MSG XApplication::XApplicationMessage;
int XApplication::appletId;

LRESULT CALLBACK XApplicationProc::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	int index = 0;

	NMHDR* h = reinterpret_cast<NMHDR*>(lParam);
	//Base* b = types[0]();
	
	switch (uMsg) {
	case WM_NOTIFY:
		
		break;

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT)
		{	
			SetCursor(LoadCursorW(NULL, XApplicationProc::mainCursor.second));

			return TRUE;
		}
		break;
	
	case WM_COMMAND:
		for (unsigned i = 0; i < XApplicationProc::XComboBoxMessages.size(); i++) {
			switch (HIWORD(wParam))
			{
			case CBN_SELCHANGE:
				if(XApplicationProc::XComboBoxMessages.at(i) != NULL){
					index = SendMessage(XApplicationProc::XComboBoxMessages.at(i)->window->_wnd, CB_GETCURSEL, 0, 0);
				}
				break;
			default:
				break;
			}
			break;
		}

		//Event click
		switch (LOWORD(wParam))
		{
		case BN_CLICKED:
			for (unsigned i = 0; i < XTypes.size(); i++) {
				if (CurrentHandle == XTypes.at(i).first->window->_wnd) {
					XTypes.at(i).second->clicked();
				}
			}
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

XApplication::XApplication(){
	icex = { 0 };
	WndClassEx = { 0 };
	szClassName = L"XApplicationMainWindow";
	hInstance = nullptr;
	hPrevInstance = nullptr;
	lpCmdLine = nullptr;
	nCmdShow = 0;
	firstElem = false;
}

XApplication::XApplication(XParams xParams) {
	icex = { 0 };
	WndClassEx = { 0 };
	szClassName = L"XApplicationMainWindow";
	hInstance = nullptr;
	hPrevInstance = nullptr;
	lpCmdLine = nullptr; 
	nCmdShow = 0;
	firstElem = false;

	XApplicationMainWindow = new XHANDLE();
	// Ensure that the common control DLL is loaded. 
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
	icex.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icex);

	WndClassEx.cbSize = sizeof(WndClassEx);
	WndClassEx.lpfnWndProc = ::XApplicationProc::WndProc;
	WndClassEx.style = CS_HREDRAW | CS_VREDRAW; //---> устанавливаются поразрядные флаги (bit flags), так как только один разряд установлен в единичное значение.

	/*
		CS_GLOBALCLASS - Создать класс, доступный всем приложениям. Обычно этот стиль применяется для создания определяемых пользователем элементов управления в DLL.
		CS_HREDRAW - Перерисовывать все окно, если изменен размер по горизонтали.
		CS_NOCLOSE - Запретить команду Close в системном меню.
		CS_OWNDC - Выделить уникальный контекст устройства для каждого окна, созданного при помощи этого класса.
		CS_VREDRAW - Перерисовывать все окно, если изменен размер по вертикали.
	*/

	WndClassEx.cbClsExtra = 0;
	WndClassEx.cbWndExtra = 0;
	WndClassEx.hInstance = xParams.hInstance;
	WndClassEx.hIcon = LoadIcon(xParams.hInstance, IDI_APPLICATION);
	WndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClassEx.lpszMenuName = NULL;
	WndClassEx.lpszClassName = szClassName;
	WndClassEx.hIconSm = LoadIcon(xParams.hInstance, IDI_APPLICATION);
	//!Заполнить структуру окна

	if (!RegisterClassEx(&WndClassEx)) {
		//return EXIT_FAILURE;
	}

	XApplicationMainWindow->window->_wnd = CreateWindowEx(WS_EX_TRANSPARENT, szClassName, L"Window title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, (HWND)NULL, (HMENU)NULL, (HINSTANCE)xParams.hInstance, NULL);
	/*
		CS_ - Опция стиля класса
		CW_ - Опция создания окна
		DT_ - Опция рисования текста
		IDC_ - Идентификатор предопределенного курсора
		IDI_ - Иденитификатор предопределенной иконки (пиктограммы)
		WM_ - Сообщение окна
		WS_ - Стиль окна
	*/

	if (!XApplicationMainWindow) {
		exit(EXIT_FAILURE);
	}

	ShowWindow(XApplicationMainWindow->window->_wnd, SW_SHOWDEFAULT);
}

void XApplication::setLayout(XVLayout* layout) {
	firstElem = true;
	max = 0;

	//Extract applets from layouts.
	while (!layout->waitingButtonts.empty()) {
		//Fixed position check.
		if (layout->waitingButtonts.front()->fixedPosition) 
			throw std::invalid_argument("This applet has a \"fixed status\".");

		XLayout::beginHeight += layout->waitingButtonts.front()->applet->window->margins.top();

		layout->waitingButtonts.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->waitingButtonts.front()->applet->window->minimumHeight + layout->waitingButtonts.front()->applet->window->margins.bottom();

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->waitingButtonts.erase(std::find(layout->waitingButtonts.begin(), layout->waitingButtonts.end(), layout->waitingButtonts.front()));
	}

	//XLabel
	while (!layout->waitingLabels.empty()) {
		//Fixed position check.
		if (layout->waitingLabels.front()->fixedPosition)
			throw std::invalid_argument("This applet has a \"fixed status\".");

#define FONT_SIZE 14
		XLayout::beginHeight += layout->waitingLabels.front()->applet->window->margins.top() + FONT_SIZE;

		layout->waitingLabels.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->waitingLabels.front()->applet->window->minimumHeight + layout->waitingLabels.front()->applet->window->margins.bottom();

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->waitingLabels.erase(std::find(layout->waitingLabels.begin(), layout->waitingLabels.end(), layout->waitingLabels.front()));
	}

	//XComboBox
	while (!layout->waitingComboBox.empty()) {
		//Fixed position check.
		if (layout->waitingComboBox.front()->fixedPosition)
			throw std::invalid_argument("This applet has a \"fixed status\".");

		XLayout::beginHeight += layout->waitingComboBox.front()->applet->window->margins.top() + FONT_SIZE;

		layout->waitingComboBox.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->waitingComboBox.front()->applet->window->minimumHeight + layout->waitingComboBox.front()->applet->window->margins.bottom();

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->waitingComboBox.erase(std::find(layout->waitingComboBox.begin(), layout->waitingComboBox.end(), layout->waitingComboBox.front()));
	}

	XLayout::betweenVeticalApplets = 0;
}

void XApplication::setLayout(XHLayout* layout) {

	firstElem = true;
	max = 0;
	XLayout::beginHorizontalLayout.push_back(layout->beginWidth);

	//Extract applets from layouts.
	if (layout->waitingButtonts.front()->fixedPosition)
		throw std::invalid_argument("This applet has a \"fixed status\".");

	//Find the maximum height element with margins in current layout.
	for (unsigned i = 0; i < layout->waitingButtonts.size(); i++) {
		if (max < layout->waitingButtonts.at(i)->applet->window->margins.top() + layout->waitingButtonts.at(i)->applet->window->minimumHeight + layout->waitingButtonts.at(i)->applet->window->margins.bottom())
			max = layout->waitingButtonts.at(i)->applet->window->margins.top() + layout->waitingButtonts.at(i)->applet->window->minimumHeight + layout->waitingButtonts.at(i)->applet->window->margins.bottom();
	}

	while (!layout->waitingButtonts.empty()) {
		//Fixed position check.
		if (layout->waitingButtonts.front()->fixedPosition) {
			throw std::invalid_argument("This applet has a \"fixed status\".");
		}

		layout->waitingButtonts.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::betweenHorizontalApplets += layout->waitingButtonts.front()->applet->window->minimumWidth;

		//if (firstElem) {
		//	firstElem = !firstElem;
		//}

		layout->waitingButtonts.erase(std::find(layout->waitingButtonts.begin(), layout->waitingButtonts.end(), layout->waitingButtonts.front()));
	}

	//XLabel
	while (!layout->waitingLabels.empty()) {
		//Fixed position check.
		if (layout->waitingLabels.front()->fixedPosition)
			throw std::invalid_argument("This applet has a \"fixed status\".");

#define FONT_SIZE 14
		XLayout::beginHeight += layout->waitingLabels.front()->applet->window->margins.top() + FONT_SIZE;

		layout->waitingLabels.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->waitingLabels.front()->applet->window->minimumHeight + layout->waitingLabels.front()->applet->window->margins.bottom();

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->waitingLabels.erase(std::find(layout->waitingLabels.begin(), layout->waitingLabels.end(), layout->waitingLabels.front()));
	}

	//XComboBox
	while (!layout->waitingComboBox.empty()) {
		//Fixed position check.
		if (layout->waitingComboBox.front()->fixedPosition)
			throw std::invalid_argument("This applet has a \"fixed status\".");

		XLayout::beginHeight += layout->waitingComboBox.front()->applet->window->margins.top() + FONT_SIZE;

		layout->waitingComboBox.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->waitingComboBox.front()->applet->window->minimumHeight + layout->waitingComboBox.front()->applet->window->margins.bottom();

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->waitingComboBox.erase(std::find(layout->waitingComboBox.begin(), layout->waitingComboBox.end(), layout->waitingComboBox.front()));
	}

	XLayout::beginWidth = 0;
	XLayout::beginHeight += max;
	XLayout::betweenHorizontalApplets = 0;
}