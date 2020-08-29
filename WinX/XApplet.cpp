#include "XApplet.h"

XApplet::~XApplet() {
	delete applet;
}

bool XApplet::windowHasMaximumSize()
{
	return XWindow::_windowHasMaximumSize;
}

XHANDLE* XApplet::windowHandle() {
	if (applet)
		return applet;
	else{
		OutLine("You have an empty applet. Check the pointer.");
		return nullptr;
	}
}

void XApplet::setApplet(XHANDLE* parent, XLayout* layout, int appletId, bool firstElem) {
	applet->windowRect().setX((layout->dir == LayoutDirection::Horizontal ? XLayout::betweenHorizontalApplets : 0));
	applet->windowRect().setY((layout->dir == LayoutDirection::Horizontal ? XLayout::beginHeight + applet->windowMargins().top() : XLayout::beginHeight + applet->windowMargins().top()));
	applet->windowRect().setRight(applet->minimumWidth());
	applet->windowRect().setBottom(applet->minimumHeight());

	if (!fixedPosition) {
		switch (layout->dir)
		{
		case LayoutDirection::None:
		case LayoutDirection::Vertical:

			if (!firstElem && XLayout::appletId > 0) {
				XLayout::betweenVeticalApplets += XLayout::properties.at(XLayout::appletId - 1).first.bottom();
			}

			XLayout::appletId++;

			break;
		case LayoutDirection::Horizontal:
			if (!firstElem && XLayout::appletId > 0) {
				XLayout::betweenHorizontalApplets += XLayout::properties.at(XLayout::appletId - 1).first.right();
			}

			XLayout::appletId++;
			break;
		default:
			break;
		}

		//?????
		XLayout::betweenHorizontalApplets += applet->windowMargins().left();

		//USES_CONVERSION;

		applet->setWindowHWND(CreateWindowExW(
			XWindow::flags.extendedFlags(),																			//Extended styles.
			XWindow::className.c_str(),																			//Predefined class; Unicode assumed.
			XWindow::windowName.c_str(),																			//Button text.
			XWindow::flags.flags(),																					//Styles.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::betweenHorizontalApplets : 0),					//x position.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::beginHeight + applet->windowMargins().top() :
				XLayout::beginHeight + applet->windowMargins().top()),												//y position.
			applet->minimumWidth(),																			//Button width.
			applet->minimumHeight(),																			//Button height.
			parent->windowHWND(),																					//Parent window.
			(HMENU)BN_CLICKED,																						//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->windowHWND(), GWLP_HINSTANCE),
			NULL));																									//Pointer not needed.
	}
	else {
		//USES_CONVERSION;

		applet->setWindowHWND(CreateWindowExW(
			XWindow::flags.extendedFlags(),																			//Extended styles.
			XWindow::className.c_str(),																			//Predefined class; Unicode assumed.
			XWindow::windowName.c_str(),																			//Button text.
			XWindow::flags.flags(),																					//Styles.
			applet->windowRect().x(),																				//x position.
			applet->windowRect().y(),																				//y position.
			applet->minimumWidth(),																			//Button width.
			applet->minimumHeight(),																			//Button height.
			parent->windowHWND(),																					//Parent window.
			(HMENU)BN_CLICKED,																						//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->windowHWND(), GWLP_HINSTANCE),
			NULL));																									//Pointer not needed.
	}

	SetLayeredWindowAttributes(applet->windowHWND(), 0, 255, LWA_ALPHA);
}

void XApplet::setOpacity(float opacity) {
	XApplicationProc::waitingOpacity.emplace(applet, opacity);
}

XWindowType XApplet::windowType()
{
	return type;
}

void XApplet::setWindowType(DWORD _type)
{
	type.setType(_type);
}

XSize XApplet::iconSize()
{
	return XSize();
}

XSize XApplet::size()
{
	return XSize(applet->minimumHeight(), applet->minimumWidth());
}

XSize XApplet::sizeIncrement()
{
	return XSize();
}

XWindowFlags XApplet::windowFlags()
{
	return XWindow::flags;
}

XMargins XApplet::margins() {
	return applet->windowMargins();
}

void XApplet::setFixedSize(XSize _fixedSize)
{
	XWindow::fixedSizeState = true;

	applet->setMinimumHeight(_fixedSize.height());
	applet->setMinimumWidth(_fixedSize.width());
}

void XApplet::setFixedSize(int height, int width)
{
	XWindow::fixedSizeState = true;

	applet->setMinimumHeight(height);
	applet->setMinimumWidth(width);
}

void XApplet::setBorder()
{
	flags.addFlags(WS_BORDER);
}

void XApplet::setMinimumWidth(int width)
{
	applet->setMinimumWidth(width);
}

void XApplet::setMinimumHeight(int height)
{
	applet->setMinimumHeight(height);
}

void XApplet::setMaximumHeight(int height)
{
	XWindow::_windowHasMaximumSize = true;
	applet->setMaximumHeight(height);
}

void XApplet::setMaximumSize(XSize size)
{
	XWindow::_windowHasMaximumSize = true;
	applet->setMaximumWidth(size.width());
	applet->setMaximumHeight(size.height());
}

void XApplet::setMaximumSize(int width, int height)
{
	XWindow::_windowHasMaximumSize = true;
	applet->setMaximumWidth(width);
	applet->setMaximumHeight(height);
}

int XApplet::height()
{
	return applet->minimumHeight();
}

int XApplet::width()
{
	return applet->minimumWidth();
}

void XApplet::setMargins(int left, int top, int right, int bottom) {

	applet->windowMargins().setMargins(left, top, right, bottom);
}

void XApplet::setPosition(int x, int y) {
	XWindow::fixedPosition = true;

	XWindow::rect.setX(x);
	XWindow::rect.setY(y);
}

void XApplet::activateWindow()
{
	XWindow::flags.setFlags(WS_TABSTOP | WS_VISIBLE | WS_CHILD);
}

void XApplet::setMaximumWidth(int width)
{
	XWindow::_windowHasMaximumSize = true;
	applet->setMaximumWidth(width);
}

void XApplet::setMinimumSize(int width, int height)
{
	applet->setMinimumWidth(width);
	applet->setMinimumHeight(height);
}

void XApplet::setMinimumSize(XSize size)
{
	applet->setMinimumWidth(size.width());
	applet->setMinimumHeight(size.height());
}

int XApplet::maximumHeight()
{
	return applet->maximumHeight();
}

XSize XApplet::maximumSize()
{
	return XSize(applet->maximumHeight(), applet->maximumWidth());
}

int XApplet::maximumWidth()
{
	return applet->maximumWidth();
}

int XApplet::minimumHeight()
{
	return applet->minimumHeight();
}

XSize XApplet::minimumSize()
{
	return XSize(applet->minimumHeight(), applet->minimumWidth());
}

int XApplet::minimumWidth()
{
	return applet->minimumWidth();
}

void XApplet::setWindowName(std::wstring windowName) {
	this->windowName = windowName;
	SetWindowTextW(applet->windowHWND(), windowName.c_str());
}

bool XApplet::isFullScreen()
{
	return &XWindow::isFullScreen;
}

bool XApplet::isActiveWindow()
{
	return &XWindow::isActiveWindow;
}
