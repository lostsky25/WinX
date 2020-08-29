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
RECT rectChildWindow;
RECT rectMainWindow;
RECT previousSizeMainWindow;

//BOOL CALLBACK XApplicationProc::EnumChildProc(HWND hWnd, LPARAM lParam) {}

LRESULT CALLBACK XApplicationProc::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CREATE:

		break;

	case WM_HSCROLL: {
		//for (size_t i = 0; i < XApplicationProc::bunchSignalSlot.size(); i++) {
		for (size_t j = 0; j < XApplicationProc::XApplets.size(); j++) {
			if (XApplets.at(j)->applet->windowHWND() == hWnd) {
				reinterpret_cast<XTrackbar*>(XApplets.at(j))->_currentValue = SendMessageW(reinterpret_cast<XTrackbar*>(XApplets.at(j))->applet->windowHWND(), TBM_GETPOS, 0, 0);
			}
		}

		for (size_t c = 0; c < XApplicationProc::bunchSignalSlotInteger.size(); c++) {
			if (std::get<0>(XApplicationProc::bunchSignalSlotInteger.at(c))->applet->windowHWND() == CurrentHandle) {
				std::get<2>(XApplicationProc::bunchSignalSlotInteger.at(c))(std::get<1>(XApplicationProc::bunchSignalSlotInteger.at(c))());
			}
		}
		//}
		break;
	}

	case WM_GETMINMAXINFO:
	{
		LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;

		if (XApplication::XApplicationMainWindow->minimumWidth() > 0 && XApplication::XApplicationMainWindow->minimumWidth() > 0) {
			lpMMI->ptMinTrackSize.x = XApplication::XApplicationMainWindow->minimumWidth();
			lpMMI->ptMinTrackSize.y = XApplication::XApplicationMainWindow->minimumHeight();

			lpMMI->ptMaxTrackSize.x = XApplication::XApplicationMainWindow->maximumWidth();
			lpMMI->ptMaxTrackSize.y = XApplication::XApplicationMainWindow->maximumHeight();
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
		//EnumChildWindows(hWnd, EnumChildProc, 0);
		//GetWindowRect(hWnd, &rectPreviousMainWindow);

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
		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE: {
			for (size_t j = 0; j < XComboBox::waitingItems.size(); j++) {
				for (size_t i = 0; i < XApplets.size(); i++) {
					if (XApplets.at(i)->applet->windowHWND() == XComboBox::waitingItems.at(j).first->windowHWND()) {
						reinterpret_cast<XComboBox*>(XApplets.at(i))->_selectedIndex = SendMessageW(XApplets.at(i)->applet->windowHWND(), CB_GETCURSEL, 0, 0);
					}
				}
			}
			break;
		}
		default:
			break;
			break;
		}

		//Event click
		switch (LOWORD(wParam))
		{
		case BN_CLICKED:
			for (size_t c = 0; c < XApplicationProc::bunchSignalSlotNonParams.size(); c++) {
				if (std::get<0>(XApplicationProc::bunchSignalSlotNonParams.at(c))->applet->windowHWND() == CurrentHandle) {
					std::get<2>(XApplicationProc::bunchSignalSlotNonParams.at(c))();
				}
			}

			//for (unsigned i = 0; i < XCallback.size(); i++) {
			//	if (CurrentHandle == XCallback.at(i).first->windowHWND()) {
			//		XCallback.at(i).second();
			//	}
			//}
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

XApplication::XApplication() {
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
	XApplicationMainWindow->setWindowHWND(CreateWindowEx(WS_EX_LAYERED, szClassName, L"Window title", WS_OVERLAPPEDWINDOW,
		(XApplication::rect.right / 2), (XApplication::rect.bottom / 2),
		NULL, NULL,
		(HWND)NULL, (HMENU)NULL, (HINSTANCE)xParams.hInstance, NULL));

	SetLayeredWindowAttributes(XApplicationMainWindow->windowHWND(), 0, 255, LWA_ALPHA);

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

	ShowWindow(XApplicationMainWindow->windowHWND(), SW_SHOWDEFAULT);
}

void XApplication::setLayout(XVLayout* layout) {
	firstElem = true;
	max = 0;

	//Just XApplet.
	while (!layout->XWaiting.empty()) {
		//Fixed position check.
		if (layout->XWaiting.front()->fixedPosition)
			throw std::invalid_argument("This applet has a \"fixed status\".");

		XLayout::beginHeight += layout->XWaiting.front()->applet->windowMargins().top();

		layout->XWaiting.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::beginHeight += layout->XWaiting.front()->applet->minimumHeight() + layout->XWaiting.front()->applet->windowMargins().bottom();

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
	GetWindowRect(XApplication::XApplicationMainWindow->windowHWND(), &rect);
	SetWindowPos(XApplication::XApplicationMainWindow->windowHWND(), (HWND)NULL, x, y, rect.right - rect.left, rect.bottom - rect.top, (UINT)0);
}

void XApplication::setMinimumHeight(int height)
{
	XApplication::XApplicationMainWindow->setMinimumHeight(height);
}

void XApplication::setMaximumHeight(int height)
{
	XApplication::XApplicationMainWindow->setMaximumHeight(height);
}

void XApplication::setMinimumWidth(int width)
{
	XApplication::XApplicationMainWindow->setMinimumWidth(width);
}

void XApplication::setMaximumWidth(int width)
{
	XApplication::XApplicationMainWindow->setMaximumWidth(width);
}

void XApplication::setMinimumSize(XSize size)
{
	XApplication::XApplicationMainWindow->setMinimumWidth(size.width());
	XApplication::XApplicationMainWindow->setMinimumHeight(size.height());
}

void XApplication::setMinimumSize(int width, int height)
{
	XApplication::XApplicationMainWindow->setMinimumWidth(width);
	XApplication::XApplicationMainWindow->setMinimumHeight(height);
}

void XApplication::setMaximumSize(XSize size)
{
	XApplication::XApplicationMainWindow->setMaximumWidth(size.width());
	XApplication::XApplicationMainWindow->setMaximumHeight(size.height());
}

void XApplication::setMaximumSize(int width, int height)
{
	XApplication::XApplicationMainWindow->setMaximumWidth(width);
	XApplication::XApplicationMainWindow->setMaximumHeight(height);
}

int XApplication::minimumHeight()
{
	return XApplication::XApplicationMainWindow->minimumHeight();
}

int XApplication::maximumHeight()
{
	return XApplication::XApplicationMainWindow->maximumHeight();
}

int XApplication::minimumWidth()
{
	return XApplication::XApplicationMainWindow->minimumWidth();
}

int XApplication::maximumWidth()
{
	return XApplication::XApplicationMainWindow->maximumWidth();
}

XSize XApplication::minimumSize()
{
	return XSize(XApplication::XApplicationMainWindow->minimumWidth(), XApplication::XApplicationMainWindow->minimumHeight());
}

XSize XApplication::maximumSize()
{
	return XSize(XApplication::XApplicationMainWindow->maximumWidth(), XApplication::XApplicationMainWindow->maximumHeight());
}

//void XApplication::setWindowName(string windowName)
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
	SetLayeredWindowAttributes(XApplication::XApplicationMainWindow->windowHWND(), 0, 255 - (255 * opacity), LWA_ALPHA);
}

int XApplication::width()
{
	return XApplication::XApplicationMainWindow->minimumWidth();
}

int XApplication::height()
{
	return XApplication::XApplicationMainWindow->minimumHeight();
}

void XApplication::setLayout(XHLayout* layout) {
	firstElem = true;
	max = 0;
	XLayout::beginHorizontalLayout.push_back(layout->beginWidth);

	if (layout->XWaiting.front()->fixedPosition)
		throw std::invalid_argument("This applet has a \"fixed status\".");

	for (unsigned i = 0; i < layout->XWaiting.size(); i++) {
		if (max < layout->XWaiting.at(i)->applet->windowMargins().top() + layout->XWaiting.at(i)->applet->minimumHeight() + layout->XWaiting.at(i)->applet->windowMargins().bottom())
			max = layout->XWaiting.at(i)->applet->windowMargins().top() + layout->XWaiting.at(i)->applet->minimumHeight() + layout->XWaiting.at(i)->applet->windowMargins().bottom();
	}

	while (!layout->XWaiting.empty()) {
		//Fixed position check.
		if (layout->XWaiting.front()->fixedPosition) {
			throw std::invalid_argument("This applet has a \"fixed status\".");
		}

		layout->XWaiting.front()->setApplet(XApplication::XApplicationMainWindow, layout, appletId++, firstElem);

		XLayout::betweenHorizontalApplets += layout->XWaiting.front()->applet->minimumWidth();

		layout->XWaiting.erase(std::find(layout->XWaiting.begin(), layout->XWaiting.end(), layout->XWaiting.front()));
	}

	XLayout::beginWidth = 0;
	XLayout::beginHeight += max;
	XLayout::betweenHorizontalApplets = 0;
}