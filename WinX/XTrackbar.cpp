#include "XTrackbar.h"


std::vector<std::pair<XHANDLE*, int>> XTrackbar::waitingRanges;

XTrackbar::XTrackbar() {
	wc.lpszClassName = L"Trackbar";
	wc.hInstance = (HINSTANCE)NULL;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	//wc.lpfnWndProc = TrackProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	RegisterClassW(&wc);

	XApplet::applet = new XHANDLE();
	XApplet::disp = new Dispether();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_STATICEDGE | WS_EX_LAYERED);
	XWindow::flags.setFlags(WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS);
	XApplet::className = L"msctls_trackbar32";
	XApplet::windowName = L"Trackbar Control";

}



XTrackbar::~XTrackbar() {
	delete XApplet::disp;
	delete XApplet::applet;
}