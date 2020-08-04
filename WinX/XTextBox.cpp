#include "XTextBox.h"

XTextBox::XTextBox() {
	XApplet::applet = new XHANDLE();
	XApplet::disp = new Dispether();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_LAYERED);
	XWindow::flags.setFlags(WS_VISIBLE | WS_CHILD);
	XApplet::className = L"EDIT";
	XApplet::windowName = L"Smth";
}

XTextBox::~XTextBox() {
	delete XApplet::disp;
	delete XApplet::applet;
}