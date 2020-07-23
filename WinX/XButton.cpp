#include "XButton.h"

XButton::XButton() {
	XApplet::applet = new XHANDLE();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_TRANSPARENT);
	XWindow::flags.setFlags(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON);
	XApplet::className = L"BUTTON";
	XApplet::windowName = L"";
}

XButton::~XButton() {
	delete XApplet::applet;
}

