#include "XApplication.h"
#include "XApplicationProc.h"
#include "XLayout.h"

class XVLayout;
class XHLayout;

XHANDLE* XApplication::XApplicationMainWindow;
MSG XApplication::XApplicationMessage;
int XApplication::appletId;
RECT XApplication::rect;
RECT rectPreviousMainWindow = { 0 };

BOOL CALLBACK XApplicationProc::EnumChildProc(HWND hWnd, LPARAM lParam) {
	for (size_t i = 0; i < XLayout::applets.size(); i++) {
		if (XLayout::applets.at(i)->applet->window->_wnd == hWnd && XLayout::applets.at(i)->windowHasMaximumSize()) {
			RECT rectMainWindow = { 0 };
			RECT rectChildWindow = { 0 };

			GetWindowRect(hWnd, &rectChildWindow);
			GetWindowRect(XApplication::XApplicationMainWindow->window->_wnd, &rectMainWindow);

			int right = rectChildWindow.right - rectChildWindow.left;
			int bottom = rectChildWindow.bottom - rectChildWindow.top;

			if (rectMainWindow.right - rectMainWindow.left > rectPreviousMainWindow.right - rectPreviousMainWindow.left
				&& right <= XLayout::applets.at(i)->maximumWidth()) {
				SetWindowPos(hWnd, (HWND)NULL, XLayout::applets.at(i)->applet->window->rect.x(), XLayout::applets.at(i)->applet->window->rect.y(), ++right, bottom, (UINT)0);
			}
			else if (rectMainWindow.right - rectMainWindow.left < rectPreviousMainWindow.right - rectPreviousMainWindow.left
				&& right >= XLayout::applets.at(i)->minimumWidth()) {
				SetWindowPos(hWnd, (HWND)NULL, XLayout::applets.at(i)->applet->window->rect.x(), XLayout::applets.at(i)->applet->window->rect.y(), --right, bottom, (UINT)0);
			}

			if (rectMainWindow.bottom - rectMainWindow.top > rectPreviousMainWindow.bottom - rectPreviousMainWindow.top
				&& bottom <= XLayout::applets.at(i)->maximumHeight()) {
				SetWindowPos(hWnd, (HWND)NULL, XLayout::applets.at(i)->applet->window->rect.x(), XLayout::applets.at(i)->applet->window->rect.y(), right, ++bottom, (UINT)0);
			}
			else if (rectMainWindow.bottom - rectMainWindow.top < rectPreviousMainWindow.bottom - rectPreviousMainWindow.top
				&& bottom >= XLayout::applets.at(i)->minimumHeight()) {
				SetWindowPos(hWnd, (HWND)NULL, XLayout::applets.at(i)->applet->window->rect.x(), XLayout::applets.at(i)->applet->window->rect.y(), right, --bottom, (UINT)0);
			}
		}
	}

	/*char buf[128];
	sprintf(buf, "Addr: 0x%p x: %d y: %d | right: %d bottom: %d\n", hWnd, rect.left, rect.top, rect.right, rect.bottom);
	OutputDebugStringA(buf);*/

	if (hWnd)
		return TRUE;
	else
		return FALSE;
}

LRESULT CALLBACK XApplicationProc::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CREATE:

		break;

	case WM_GETMINMAXINFO:
	{
		LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;

		if (XApplication::XApplicationMainWindow->window->minimumWidth > 0 && XApplication::XApplicationMainWindow->window->minimumWidth > 0) {
			lpMMI->ptMinTrackSize.x = XApplication::XApplicationMainWindow->window->minimumWidth;
			lpMMI->ptMinTrackSize.y = XApplication::XApplicationMainWindow->window->minimumHeight;

			lpMMI->ptMaxTrackSize.x = XApplication::XApplicationMainWindow->window->maximumWidth;
			lpMMI->ptMaxTrackSize.y = XApplication::XApplicationMainWindow->window->maximumHeight;
		}
		else
		{
			lpMMI->ptMinTrackSize.x = XWINDOWMINWIDTH;
			lpMMI->ptMinTrackSize.y = XWINDOWMINHEIGHT;
		}
	}
	case WM_NOTIFY:

		break;
	case WM_SIZE: {
		EnumChildWindows(hWnd, EnumChildProc, 0);
		GetWindowRect(hWnd, &rectPreviousMainWindow);

		break;
	}

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT)
		{	
			SetCursor(LoadCursorW(NULL, XApplicationProc::mainCursor.second));

			return TRUE;
		}
		break;
	
	case WM_COMMAND:
		/*for (unsigned i = 0; i < XApplicationProc::XComboBoxMessages.size(); i++) {
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
		}*/

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

		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
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

	GetWindowRect(GetDesktopWindow(), &XApplication::rect);
	XApplicationMainWindow->window->_wnd = CreateWindowEx(WS_EX_LAYERED, szClassName, L"Window title", WS_OVERLAPPEDWINDOW, 
		(XApplication::rect.right / 2), (XApplication::rect.bottom / 2),
		NULL, NULL,
		(HWND)NULL, (HMENU)NULL, (HINSTANCE)xParams.hInstance, NULL);

	SetLayeredWindowAttributes(XApplicationMainWindow->window->_wnd, 0, 255, LWA_ALPHA);
	
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

	//Just XApplet.
	while (!layout->XWaiting.empty()) {
		//Fixed position check.
		if (layout->XWaiting.front()->fixedPosition)
			throw std::invalid_argument("This applet has a \"fixed status\".");

		XLayout::beginHeight += layout->XWaiting.front()->applet->window->margins.top();

		layout->XWaiting.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->XWaiting.front()->applet->window->minimumHeight + layout->XWaiting.front()->applet->window->margins.bottom();

		if (firstElem) {
			firstElem = !firstElem;
		}

		layout->XWaiting.erase(std::find(layout->XWaiting.begin(), layout->XWaiting.end(), layout->XWaiting.front()));
	}

	XLayout::betweenVeticalApplets = 0;
}

bool XApplication::windowHasMaximumSize()
{
	return XWindow::_windowHasMaximumSize;
}


XHANDLE* XApplication::windowHandle()
{
	return XApplication::XApplicationMainWindow;
}

void XApplication::setPosition(int x, int y)
{
	GetWindowRect(XApplication::XApplicationMainWindow->window->_wnd, &rect);
	SetWindowPos(XApplication::XApplicationMainWindow->window->_wnd, (HWND)NULL, x, y, rect.right - rect.left, rect.bottom - rect.top, (UINT)0);
}

void XApplication::setMinimumHeight(int height)
{
	XApplication::XApplicationMainWindow->window->minimumHeight = height;
}

void XApplication::setMaximumHeight(int height)
{
	XApplication::XApplicationMainWindow->window->maximumHeight = height;
}

void XApplication::setMinimumWidth(int width)
{
	XApplication::XApplicationMainWindow->window->minimumWidth = width;
}

void XApplication::setMaximumWidth(int width)
{
	XApplication::XApplicationMainWindow->window->maximumWidth = width;
}

void XApplication::setMinimumSize(XSize size)
{
	XApplication::XApplicationMainWindow->window->minimumWidth = size.width();
	XApplication::XApplicationMainWindow->window->minimumHeight = size.height();
}

void XApplication::setMinimumSize(int width, int height)
{
	XApplication::XApplicationMainWindow->window->minimumWidth = width;
	XApplication::XApplicationMainWindow->window->minimumHeight = height;
}

void XApplication::setMaximumSize(XSize size)
{
	XApplication::XApplicationMainWindow->window->maximumWidth = size.width();
	XApplication::XApplicationMainWindow->window->maximumHeight = size.height();
}

void XApplication::setMaximumSize(int width, int height)
{
	XApplication::XApplicationMainWindow->window->maximumWidth = width;
	XApplication::XApplicationMainWindow->window->maximumHeight = height;
}

int XApplication::minimumHeight()
{
	return XApplication::XApplicationMainWindow->window->minimumHeight;
}

int XApplication::maximumHeight()
{
	return XApplication::XApplicationMainWindow->window->maximumHeight;
}

int XApplication::minimumWidth()
{
	return XApplication::XApplicationMainWindow->window->minimumWidth;
}

int XApplication::maximumWidth()
{
	return XApplication::XApplicationMainWindow->window->maximumWidth;
}

XSize XApplication::minimumSize()
{
	return XSize(XApplication::XApplicationMainWindow->window->minimumWidth, XApplication::XApplicationMainWindow->window->minimumHeight);
}

XSize XApplication::maximumSize()
{
	return XSize(XApplication::XApplicationMainWindow->window->maximumWidth, XApplication::XApplicationMainWindow->window->maximumHeight);
}

//void XApplication::setWindowName(XString windowName)
//{
//	XWindow::windowName = windowName;
//}
//
//XMargins XApplication::margins()
//{
//	return XMargins();
//}
//
//void XApplication::setMargins(int, int, int, int)
//{
//}

bool XApplication::isFullScreen()
{
	return XWindow::_isFullScreen;
}

bool XApplication::isActiveWindow()
{
	return XWindow::_isActiveWindow;
}

void XApplication::setOpacity(float opacity)
{
	SetLayeredWindowAttributes(XApplication::XApplicationMainWindow->window->_wnd, 0, 255 - (255 * opacity), LWA_ALPHA);
}

int XApplication::width()
{
	return XApplication::XApplicationMainWindow->window->minimumWidth;
}

int XApplication::height()
{
	return XApplication::XApplicationMainWindow->window->minimumHeight;
}

void XApplication::setLayout(XHLayout* layout) {

	firstElem = true;
	max = 0;
	XLayout::beginHorizontalLayout.push_back(layout->beginWidth);

	if (layout->XWaiting.front()->fixedPosition)
		throw std::invalid_argument("This applet has a \"fixed status\".");

	for (unsigned i = 0; i < layout->XWaiting.size(); i++) {
		if (max < layout->XWaiting.at(i)->applet->window->margins.top() + layout->XWaiting.at(i)->applet->window->minimumHeight + layout->XWaiting.at(i)->applet->window->margins.bottom())
			max = layout->XWaiting.at(i)->applet->window->margins.top() + layout->XWaiting.at(i)->applet->window->minimumHeight + layout->XWaiting.at(i)->applet->window->margins.bottom();
	}

	while (!layout->XWaiting.empty()) {
		//Fixed position check.
		if (layout->XWaiting.front()->fixedPosition) {
			throw std::invalid_argument("This applet has a \"fixed status\".");
		}

		layout->XWaiting.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::betweenHorizontalApplets += layout->XWaiting.front()->applet->window->minimumWidth;

		layout->XWaiting.erase(std::find(layout->XWaiting.begin(), layout->XWaiting.end(), layout->XWaiting.front()));
	}

	XLayout::beginWidth = 0;
	XLayout::beginHeight += max;
	XLayout::betweenHorizontalApplets = 0;
}