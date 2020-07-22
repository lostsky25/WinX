#include "XLabel.h"

XLabel::XLabel() {
	XApplet::applet = new XHANDLE();
	XWindow::enabled = 0;
	XWindow::focus = 0;
	XWindow::fixedPosition = false;
	XWindow::fixedSizeState = false;
	XWindow::fixedHeightState = false;
	XWindow::fixedWidthState = false;
	XWindow::flags.setExtendedFlags(WS_EX_TRANSPARENT);
	XWindow::flags.setFlags(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON);
}

XLabel::~XLabel() {
	delete XApplet::applet;
}

void XLabel::setApplet(XHANDLE* parent, XLayout* layout, int appletId, bool firstElem) {

	////////////////////////////////////////////////////////////////////
	//XLayout::_beginHeight += this->_margins.top;
	////////////////////////////////////////////////////////////////////

	if (!fixedPosition) {
		switch (layout->dir)
		{
		case LayoutDirection::None:
		case LayoutDirection::Vertical:
			applet->window->rect.setRight(applet->window->minimumWidth);
			applet->window->rect.setBottom(applet->window->minimumHeight);

			//Save current rectangle and margins of applet
			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			//If it's not first layout, we add a previous height layout
			//if(layout->id > 1){
				//_beginVertical = XLayout::_beginVerticalLayout.at(layout->id - 2);
			//}

			if (!firstElem && XLayout::appletId > 0) {
				XLayout::betweenVeticalApplets += XLayout::properties.at(XLayout::appletId - 1).first.bottom();
			}

			XLayout::appletId++;

			break;
		case LayoutDirection::Horizontal:
			applet->window->rect.setRight(applet->window->minimumWidth);
			applet->window->rect.setBottom(applet->window->minimumHeight);

			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			if (!firstElem && XLayout::appletId > 0) {
				XLayout::betweenHorizontalApplets += XLayout::properties.at(XLayout::appletId - 1).first.right();
			}

			XLayout::appletId++;

			break;
		default:
			break;
		}

		//USES_CONVERSION;
		applet->window->_wnd = CreateWindowExW(0, L"static", L"ST_U",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			(layout->dir == LayoutDirection::Horizontal ? XLayout::betweenHorizontalApplets : 0),										//x position.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::beginHeight + applet->window->margins.top() :
				XLayout::beginHeight + applet->window->margins.top()),																	//y position.
			applet->window->minimumWidth,																								//Label width.
			applet->window->minimumHeight,																								//Label height.
			parent->window->_wnd, (HMENU)(501),
			(HINSTANCE)GetWindowLong(parent->window->_wnd, GWLP_HINSTANCE), NULL);
		SetWindowText(applet->window->_wnd, text.getData());
	}
	else {
		//USES_CONVERSION;
		applet->window->_wnd = CreateWindowExW(0, L"static", L"ST_U",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			applet->window->rect.x(),																	//x position.
			applet->window->rect.y(),																	//y position.
			applet->window->minimumWidth,																//Button width.
			applet->window->minimumHeight,																//Button height.
			parent->window->_wnd,																		//Parent window.
			(HMENU)(501),
			(HINSTANCE)GetWindowLong(parent->window->_wnd, GWLP_HINSTANCE), NULL);
		SetWindowText(applet->window->_wnd, text.getData());
	}
}

