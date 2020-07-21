#include "XApplet.h"

XHANDLE* XApplet::windowHandle() {
	if (applet)
		return applet;
	else{
		OutLine("You have a empty applet. Check the pointer.");
		return nullptr;
	}
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
	XWindow::flags.setFlags(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON);
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

void XApplet::setText(XString text) {
	this->text = text;
}

bool XApplet::isFullScreen()
{
	return &XWindow::isFullScreen;
}

bool XApplet::isActiveWindow()
{
	return &XWindow::isActiveWindow;
}

void XApplet::setApplet(XHANDLE* parent, XLayout* layout, int appletId, bool firstElem) {

}

