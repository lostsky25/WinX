#include "xhandle.h"

XHANDLE::XHANDLE()
{
	window = new __xhandle();
}

XHANDLE::~XHANDLE()
{
	delete window;
}

HWND XHANDLE::windowHWND() {
	return window->wnd;
}

void XHANDLE::setWindowHWND(HWND hWnd) {
	window->wnd = hWnd;
}

XMargins XHANDLE::windowMargins() {
	return window->margins;
}

XRect XHANDLE::windowRect() {
	return window->rect;
}

void XHANDLE::setMaximumHeight(int height) {
	window->maximumHeight = height;
}
void XHANDLE::setMaximumWidth(int width) {
	window->maximumWidth = width;
}

void XHANDLE::setMinimumHeight(int height) {
	window->minimumHeight = height;
}

void XHANDLE::setMinimumWidth(int width) {
	window->minimumWidth = width;
}

int XHANDLE::maximumHeight() {
	return window->maximumHeight;
}

int XHANDLE::maximumWidth() {
	return window->maximumWidth;
}

int XHANDLE::minimumHeight() {
	return window->minimumHeight;
}

int XHANDLE::minimumWidth() {
	return window->minimumWidth;
}
