#include "XApplet.h"

HWND XApplet::windowHandle() {
	if (applet)
		return applet;
	else
		OutLine("You have a empty applet. Check the pointer.");
}

void XApplet::windowUpdate()
{
	windowUpdate();
}

void XApplet::setWindowIcon(XTypes::XIcon) {

}

void XApplet::setWindowOpacity(float) {

}
void XApplet::setFixedHeight(int) {

}
void XApplet::setFixedSize(XTypes::XSize) {

}
void XApplet::setFixedSize(int, int) {

}
void XApplet::activateWindow() {

}


XTypes::XMargins XApplet::margins() {
	return _margins;
}

void XApplet::setMinimumWidth(int width)
{
	this->_minimumWidth = width;
}

void XApplet::setMinimumHeight(int height)
{
	this->_minimumHeight = height;
}

void XApplet::setMaximumHeight(int height)
{
	this->_maximumHeight = height;
}

void XApplet::setMaximumSize(XTypes::XSize size)
{
	this->_maximumWidth = size.widht;
	this->_maximumHeight = size.height;
}

void XApplet::setMaximumSize(int width, int height)
{

}

void XApplet::setMaximumWidth(int width)
{
	this->_maximumWidth = width;
}

void XApplet::setMinimumSize(int width, int height)
{
	this->_minimumWidth = width;
	this->_minimumHeight = height;
}

void XApplet::setMinimumSize(XTypes::XSize size)
{
	this->_minimumWidth = size.widht;
	this->_minimumHeight = size.height;
}

int XApplet::maximumHeight()
{
	return _minimumHeight;
}

XTypes::XSize XApplet::maximumSize()
{
	XTypes::XSize size;
	size.widht = this->_maximumWidth;
	size.height = this->_maximumHeight;
	return size;
}

//XTypes::XMargins XApplet::margins() {
//	return this->_margins;
//}

//void XApplet::setMargins(XTypes::XMargins margins)
//{
//	this->_margins = margins;
//}
//
//void XApplet::setMargins(int left, int top, int right, int bottom)
//{
//	this->_margins = {left, top, right, bottom};
//}

int XApplet::maximumWidth()
{
	return _maximumWidth;
}

int XApplet::minimumHeight()
{
	return _minimumHeight;
}

XTypes::XSize XApplet::minimumSize()
{
	XTypes::XSize size;
	size.widht = this->_minimumWidth;
	size.height = this->_minimumHeight;
	return size;
}

int XApplet::minimumWidth()
{
	return _minimumWidth;
}

XTypes::XRect XApplet::frameGeomtry()
{
	return {_x, _y, _width, _height};
}

void XApplet::setText(LPCSTR text) {
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




//void XApplet::updateSize()
//{
//	/*this->_width = this->_minimumWidth + this->_maximumWidth;
//	this->_height = this->_minimumHeight + this->_maximumHeight;
//
//	this->_x = this->_minimumWidth;
//	this->_y = this->_minimumHeight;*/
//}
