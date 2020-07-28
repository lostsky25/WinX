#include "XComboBox.h"

XComboBox::XComboBox() {
	XApplet::applet = new XHANDLE();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_STATICEDGE);
	XWindow::flags.setFlags(CBS_DROPDOWN | WS_CHILD | WS_VISIBLE);
	XApplet::className = L"COMBOBOX";
	XApplet::windowName = L"";
}

XComboBox::~XComboBox() {
	delete XApplet::applet;
}