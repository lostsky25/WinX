#include "XButton.h"

XButton::XButton() {
	this->applet = new XHANDLE();
	this->_flags.setExtendedFlags(WS_EX_TRANSPARENT);
	this->_flags.setFlags(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON);
	_windowTitle = L"BUTTON";
}

XButton::~XButton() {
	delete &_flags;
	delete &_type;
}

void XButton::setApplet(XHANDLE* parent, XLayout* layout, int appletId, bool firstElem) {

	////////////////////////////////////////////////////////////////////
	//XLayout::_beginHeight += this->_margins.top;
	////////////////////////////////////////////////////////////////////

	if(!_fixedPosition){
		switch (layout->dir)
		{
		case LayoutDirection::None:
		case LayoutDirection::Vertical:
			applet->window->_rect.right = applet->window->_minimumWidth;
			applet->window->_rect.bottom = applet->window->_minimumHeight;

			//Save current rectangle and margins of applet
			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			//If it's not first layout, we add a previous height layout
			//if(layout->id > 1){
				//_beginVertical = XLayout::_beginVerticalLayout.at(layout->id - 2);
			//}

			if (!firstElem && XLayout::_appletId > 0) {
				XLayout::_betweenVeticalApplets += XLayout::_properties.at(XLayout::_appletId - 1).first.bottom;
			}

			XLayout::_appletId++;
		
			break;
		case LayoutDirection::Horizontal:
			applet->window->_rect.right = applet->window->_minimumWidth;
			applet->window->_rect.bottom = applet->window->_minimumHeight;

			//XLayout::_properties.push_back(std::make_pair(_rect, _margins));

			if (!firstElem && XLayout::_appletId > 0) {
				XLayout::_betweenHorizontalApplets += XLayout::_properties.at(XLayout::_appletId - 1).first.right;
			}

			XLayout::_appletId++;

			break;
		default:
			break;
		}

		//USES_CONVERSION;

		applet->window->_wnd = CreateWindowExW(
			this->_flags.extendedFlags(),												//Extended styles.
			L"BUTTON",																	//Predefined class; Unicode assumed.
			_text.getData(),																	//Button text.
			this->_flags.flags(),														//Styles.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::_betweenHorizontalApplets : 0),																	//x position.
			(layout->dir == LayoutDirection::Horizontal ? XLayout::_beginHeight + applet->window->_margins.top :
				XLayout::_beginHeight + applet->window->_margins.top),																	//y position.
			applet->window->_minimumWidth,																//Button width.
			applet->window->_minimumHeight,																//Button height.
			parent->window->_wnd,														//Parent window.
			(HMENU)BN_CLICKED,															//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->window->_wnd, GWLP_HINSTANCE),
			NULL);																		//Pointer not needed.

	}
	else {
		//USES_CONVERSION;

		applet->window->_wnd = CreateWindowExW(
			this->_flags.extendedFlags(),												//Extended styles.
			L"BUTTON",																	//Predefined class; Unicode assumed.
			_text.getData(),																	//Button text.
			this->_flags.flags(),														//Styles.
			this->_x,																	//x position.
			this->_y,																	//y position.
			applet->window->_minimumWidth,																//Button width.
			applet->window->_minimumHeight,																//Button height.
			parent->window->_wnd,														//Parent window.
			(HMENU)BN_CLICKED,															//No menu.
			(HINSTANCE)GetWindowLongPtr(parent->window->_wnd, GWLP_HINSTANCE),
			NULL);																		//Pointer not needed.
		//SetLayeredWindowAttributes(applet->window->_wnd, 0, 200, LWA_ALPHA);
	}
}

