#include "XApplet.h"

XHANDLE* XApplet::windowHandle() {
	if (this->applet)
		return this->applet;
	else{
		OutLine("You have a empty applet. Check the pointer.");
		return nullptr;
	}
}

void XApplet::windowUpdate()
{
	windowUpdate();
}

XWindowType XApplet::windowType()
{
	return this->_type;
}

void XApplet::setWindowType(DWORD _type)
{
	this->_type.setType(_type);
}

void XApplet::setWindowTitle(XString _title)
{
	_windowTitle = _title;
}

XString XApplet::windowTitle()
{
	return _windowTitle;
}

XSize XApplet::iconSize()
{
	return XSize();
}

void XApplet::setWindowState(XTypes::XWindowState windowState)
{
	this->_windowState = windowState;
}

XSize XApplet::size()
{
	return XSize(applet->window->_minimumHeight, applet->window->_minimumWidth);
}

XSize XApplet::sizeIncrement()
{
	return XSize();
}

void XApplet::setBaseSize(XSize)
{
	//No implementation.
}

void XApplet::setBaseSize(int, int)
{
	//No implementation.
}

XWindowFlags XApplet::windowFlags()
{
	return this->_flags;
}

XTypes::XIcon XApplet::windowIcon()
{
	return XTypes::XIcon();
}

XTypes::XWindowState XApplet::windowState()
{
	return _windowState;
}

void XApplet::setWindowIcon(XTypes::XIcon)
{
	//No implementation.
}

void XApplet::setFixedHeight(int _minimumHeight)
{
	this->_fixedHeightState = true;

	applet->window->_minimumHeight = _minimumHeight;
}

void XApplet::setFixedWidth(int _minimumWidth)
{
	this->_fixedWidthState = true;

	applet->window->_minimumWidth = _minimumWidth;
}

XTypes::XMargins XApplet::margins() {
	return applet->window->_margins;
}

void XApplet::setFixedSize(XSize _fixedSize)
{
	this->_fixedSizeState = true;

	applet->window->_minimumHeight = _fixedSize.height();
	applet->window->_minimumWidth = _fixedSize.width();
}

void XApplet::setFixedSize(int _height, int _width)
{
	this->_fixedSizeState = true;

	applet->window->_minimumHeight = _height;
	applet->window->_minimumWidth = _width;
}

void XApplet::setMinimumWidth(int width)
{
	applet->window->_minimumWidth = width;
}

void XApplet::setMinimumHeight(int height)
{
	applet->window->_minimumHeight = height;
}

void XApplet::setMaximumHeight(int height)
{
	applet->window->_maximumHeight = height;
}

void XApplet::setMaximumSize(XSize size)
{
	applet->window->_maximumWidth = size.width();
	applet->window->_maximumHeight = size.height();
}

void XApplet::setMaximumSize(int width, int height)
{

}

int XApplet::height()
{
	return applet->window->_minimumHeight;
}

int XApplet::width()
{
	return applet->window->_minimumWidth;
}

void XApplet::updateSize()
{
	this->_width = applet->window->_minimumWidth + applet->window->_maximumWidth;
	this->_height = applet->window->_minimumHeight + applet->window->_maximumHeight;

	this->_x = applet->window->_minimumWidth;
	this->_y = applet->window->_minimumHeight;
}

void XApplet::setMargins(int _left, int _top, int _right, int _bottom) {
	applet->window->_margins.left = _left;
	applet->window->_margins.top = _top;
	applet->window->_margins.right = _right;
	applet->window->_margins.bottom = _bottom;
}

void XApplet::setWindowOpacity(float opacity)
{
	//No implementation.
}

float XApplet::windowOpacity()
{
	//No implementation.
	return 0.0f;
}

void XApplet::setPosition(int x, int y) {
	this->_fixedPosition = true;

	this->_x = x;
	this->_y = y;
}

void XApplet::activateWindow()
{
	this->_flags.setFlags(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON);
}

void XApplet::setMaximumWidth(int width)
{
	applet->window->_maximumWidth = width;
}

void XApplet::setMinimumSize(int width, int height)
{
	applet->window->_minimumWidth = width;
	applet->window->_minimumHeight = height;
}

void XApplet::setMinimumSize(XSize size)
{
	applet->window->_minimumWidth = size.width();
	applet->window->_minimumHeight = size.height();
}

int XApplet::maximumHeight()
{
	return applet->window->_minimumHeight;
}

XSize XApplet::maximumSize()
{
	return XSize(applet->window->_maximumHeight, applet->window->_maximumWidth);
}

int XApplet::maximumWidth()
{
	return applet->window->_maximumWidth;
}

int XApplet::minimumHeight()
{
	return applet->window->_minimumHeight;
}

XSize XApplet::minimumSize()
{
	return XSize(applet->window->_minimumHeight, applet->window->_minimumWidth);
}

int XApplet::minimumWidth()
{
	return applet->window->_minimumWidth;
}

XTypes::XRect XApplet::frameGeomtry()
{
	return {_x, _y, _width, _height};
}

void XApplet::setText(XString text) {
	this->_text = text;
}

bool XApplet::isFullScreen()
{
	return this->_fullScreen;
}

bool XApplet::isActiveWindow()
{
	return this->_isActiveWindow;
}

bool XApplet::isWindow()
{
	return this->_isWindow;
}

void XApplet::setApplet(XHANDLE* parent, XLayout* layout, int appletId, bool firstElem) {

}

