#include "XLabel.h"

XLabel::XLabel() {
	XApplet::applet = new XHANDLE();
	XApplet::disp = new Dispether();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_TRANSPARENT | WS_EX_LAYERED);
	XWindow::flags.setFlags(WS_CHILD | WS_VISIBLE | WS_TABSTOP);
	XApplet::className = L"static";
	XApplet::windowName = L"ST_U";
}

XLabel::~XLabel() {
	delete XApplet::disp;
	delete XApplet::applet;
}
