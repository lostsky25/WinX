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
}

XButton::~XButton() {
	delete XApplet::applet;
}

void XButton::setApplet(XHANDLE* parent, XLayout* layout, int appletId, bool firstElem) {

	////////////////////////////////////////////////////////////////////
	//XLayout::_beginHeight += this->_margins.top;
	////////////////////////////////////////////////////////////////////

	if(!fixedPosition){
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

			if (!firstElem && XLayout::_appletId > 0) {
				XLayout::_betweenVeticalApplets += XLayout::_properties.at(XLayout::_appletId - 1).first.bottom();
			}

			XLayout::_appletId++;
		
			break;
		case LayoutDirection::Horizontal:
			applet->window->rect.setRight(applet->window->minimumWidth);
			applet->window->rect.setBottom(applet->window->minimumHeight);

			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			if (!firstElem && XLayout::_appletId > 0) {
				XLayout::_betweenHorizontalApplets += XLayout::_properties.at(XLayout::_appletId - 1).first.right();
			}

			XLayout::_appletId++;

			break;
		default:
			break;
		}

		//USES_CONVERSION;

		applet->window->_wnd = CreateWindowExW(
			XWindow::flags.extendedFlags(),												//Extended styles.
			L"BUTTON",																	//Predefined class; Unicode assumed.
			text.getData(),																	//Button text.
			XWindow::flags.flags(),														//Styles.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::_betweenHorizontalApplets : 0),																	//x position.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::_beginHeight + applet->window->margins.top() :
				XLayout::_beginHeight + applet->window->margins.top()),																	//y position.
			applet->window->minimumWidth,																//Button width.
			applet->window->minimumHeight,																//Button height.
			parent->window->_wnd,														//Parent window.
			(HMENU)BN_CLICKED,															//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->window->_wnd, GWLP_HINSTANCE),
			NULL);																		//Pointer not needed.

	}
	else {
		//USES_CONVERSION;

		applet->window->_wnd = CreateWindowExW(
			XWindow::flags.extendedFlags(),												//Extended styles.
			L"BUTTON",																	//Predefined class; Unicode assumed.
			text.getData(),																	//Button text.
			XWindow::flags.flags(),														//Styles.
			applet->window->rect.x(),																	//x position.
			applet->window->rect.y(),																	//y position.
			applet->window->minimumWidth,																//Button width.
			applet->window->minimumHeight,																//Button height.
			parent->window->_wnd,														//Parent window.
			(HMENU)BN_CLICKED,															//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->window->_wnd, GWLP_HINSTANCE),
			NULL);																		//Pointer not needed.
		//SetLayeredWindowAttributes(applet->window->_wnd, 0, 200, LWA_ALPHA);
	}
}

