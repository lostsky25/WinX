#include "XApplet.h"

XApplet::~XApplet() {
	delete applet;
}

void XApplet::clicked() {

}

void XApplet::released() {

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

	////////////////////////////////////////////////////////////////////
	//XLayout::_beginHeight += this->_margins.top;
	////////////////////////////////////////////////////////////////////

	if (!fixedPosition) {
		switch (layout->dir)
		{
		case LayoutDirection::None:
		case LayoutDirection::Vertical:
			applet->window->rect.setRight(applet->window->minimumWidth);
			applet->window->rect.setBottom(applet->window->minimumHeight);

			//Save current rectangle and margins of applet
			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			//If it's not first layout, we add a previous height layout
			//if(layout->id > 1){
				//_beginVertical = XLayout::_beginVerticalLayout.at(layout->id - 2);
			//}

			if (!firstElem && XLayout::appletId > 0) {
				XLayout::betweenVeticalApplets += XLayout::properties.at(XLayout::appletId - 1).first.bottom();
			}

			XLayout::appletId++;

			break;
		case LayoutDirection::Horizontal:
			applet->window->rect.setRight(applet->window->minimumWidth);
			applet->window->rect.setBottom(applet->window->minimumHeight);

			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			if (!firstElem && XLayout::appletId > 0) {
				XLayout::betweenHorizontalApplets += XLayout::properties.at(XLayout::appletId - 1).first.right();
			}

			XLayout::appletId++;

			break;
		default:
			break;
		}

		//USES_CONVERSION;

		applet->window->_wnd = CreateWindowExW(
			XWindow::flags.extendedFlags(),																			//Extended styles.
			XWindow::className.getData(),																			//Predefined class; Unicode assumed.
			XWindow::windowName.getData(),																			//Button text.
			XWindow::flags.flags(),																					//Styles.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::betweenHorizontalApplets : 0),					//x position.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::beginHeight + applet->window->margins.top() :
				XLayout::beginHeight + applet->window->margins.top()),												//y position.
			applet->window->minimumWidth,																			//Button width.
			applet->window->minimumHeight,																			//Button height.
			parent->window->_wnd,																					//Parent window.
			(HMENU)BN_CLICKED,																						//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->window->_wnd, GWLP_HINSTANCE),
			NULL);																									//Pointer not needed.

		SetLayeredWindowAttributes(applet->window->_wnd, 0, 255, LWA_ALPHA);

	}
	else {
		//USES_CONVERSION;

		applet->window->_wnd = CreateWindowExW(
			XWindow::flags.extendedFlags(),																			//Extended styles.
			XWindow::className.getData(),																			//Predefined class; Unicode assumed.
			XWindow::windowName.getData(),																			//Button text.
			XWindow::flags.flags(),																					//Styles.
			applet->window->rect.x(),																				//x position.
			applet->window->rect.y(),																				//y position.
			applet->window->minimumWidth,																			//Button width.
			applet->window->minimumHeight,																			//Button height.
			parent->window->_wnd,																					//Parent window.
			(HMENU)BN_CLICKED,																						//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->window->_wnd, GWLP_HINSTANCE),
			NULL);																									//Pointer not needed.

		SetLayeredWindowAttributes(applet->window->_wnd, 0, 255, LWA_ALPHA);
	}
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
	return XSize(applet->window->minimumHeight, applet->window->minimumWidth);
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
	return applet->window->margins;
}

void XApplet::setFixedSize(XSize _fixedSize)
{
	XWindow::fixedSizeState = true;

	applet->window->minimumHeight = _fixedSize.height();
	applet->window->minimumWidth = _fixedSize.width();
}

void XApplet::setFixedSize(int height, int width)
{
	XWindow::fixedSizeState = true;

	applet->window->minimumHeight = height;
	applet->window->minimumWidth = width;
}

void XApplet::setBorder()
{
	flags.addFlags(WS_BORDER);
}

void XApplet::setMinimumWidth(int width)
{
	applet->window->minimumWidth = width;
}

void XApplet::setMinimumHeight(int height)
{
	applet->window->minimumHeight = height;
}

void XApplet::setMaximumHeight(int height)
{
	applet->window->maximumHeight = height;
}

void XApplet::setMaximumSize(XSize size)
{
	applet->window->maximumWidth = size.width();
	applet->window->maximumHeight = size.height();
}

void XApplet::setMaximumSize(int width, int height)
{
	applet->window->maximumWidth = width;
	applet->window->maximumHeight = height;
}

int XApplet::height()
{
	return applet->window->minimumHeight;
}

int XApplet::width()
{
	return applet->window->minimumWidth;
}

void XApplet::setMargins(int left, int top, int right, int bottom) {

	applet->window->margins.setMargins(left, top, right, bottom);
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
	applet->window->maximumWidth = width;
}

void XApplet::setMinimumSize(int width, int height)
{
	applet->window->minimumWidth = width;
	applet->window->minimumHeight = height;
}

void XApplet::setMinimumSize(XSize size)
{
	applet->window->minimumWidth = size.width();
	applet->window->minimumHeight = size.height();
}

int XApplet::maximumHeight()
{
	return applet->window->minimumHeight;
}

XSize XApplet::maximumSize()
{
	return XSize(applet->window->maximumHeight, applet->window->maximumWidth);
}

int XApplet::maximumWidth()
{
	return applet->window->maximumWidth;
}

int XApplet::minimumHeight()
{
	return applet->window->minimumHeight;
}

XSize XApplet::minimumSize()
{
	return XSize(applet->window->minimumHeight, applet->window->minimumWidth);
}

int XApplet::minimumWidth()
{
	return applet->window->minimumWidth;
}

void XApplet::setWindowName(XString windowName) {
	this->windowName = windowName;
}

bool XApplet::isFullScreen()
{
	return &XWindow::isFullScreen;
}

bool XApplet::isActiveWindow()
{
	return &XWindow::isActiveWindow;
}
