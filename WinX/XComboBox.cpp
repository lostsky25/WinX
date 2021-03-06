#include "XComboBox.h"

std::vector<std::pair<XHANDLE*, std::wstring>> XComboBox::waitingItems;

XComboBox::XComboBox() {
	XApplet::applet = new XHANDLE();
	XApplet::disp = new Dispether();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_STATICEDGE | WS_EX_LAYERED);
	XWindow::flags.setFlags(CBS_DROPDOWN | WS_CHILD | WS_VISIBLE);
	XApplet::className = L"COMBOBOX";
	XApplet::windowName = L"";
}

void XComboBox::addItem(std::wstring item)
{
	waitingItems.emplace_back(applet, item);

}

XComboBox::~XComboBox() {
	delete XApplet::disp;
	delete XApplet::applet;
}