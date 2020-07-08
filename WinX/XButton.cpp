#include "XButton.h"

#define ID_BUTTON 100

//
//LPWSTR XButton::getText()
//{
//	return this->_text;
//}


XButton::XButton(){
}

void XButton::setText(LPCSTR text)
{
	this->_text = text;
}


int XButton::idBtn;

XTypes::XSize XButton::iconSize()
{
	return XTypes::XSize();
}

void XButton::setMargins(int left, int top, int right, int bottom) {
	_margins.left = left;
	_margins.top = top;
	_margins.right = right;
	_margins.bottom = bottom;
}

void XButton::setWindowTitle(XString)
{
}

int XButton::height()
{
	return _minimumHeight;
}

int XButton::width()
{
	return _minimumWidth;
}

XString XButton::windowTitle()
{
	return XString();
}

void XButton::setWindowState(XTypes::XWindowState windowState)
{
	this->_windowState = windowState;
}

XTypes::XSize XButton::size()
{
	return XTypes::XSize();
}

XTypes::XSize XButton::sizeIncrement()
{
	return XTypes::XSize();
}

void XButton::setBaseSize(XTypes::XSize)
{
}

void XButton::setBaseSize(int, int)
{
}

XTypes::XWindowFlags XButton::windowFlags()
{
	return XTypes::XWindowFlags();
}

XTypes::XIcon XButton::windowIcon()
{
	return XTypes::XIcon();
}

float XButton::windowOpacity()
{
	return 0.0f;
}

XTypes::XWindowState XButton::windowState()
{
	return _windowState;
}

XTypes::XWindowType XButton::windowType()
{
	return XTypes::XWindowType();
}

void XButton::setWindowIcon(XTypes::XIcon)
{
}

void XButton::setWindowOpacity(float)
{
}

void XButton::setFixedHeight(int)
{
}

void XButton::setFixedSize(XTypes::XSize)
{
}

void XButton::setFixedSize(int, int)
{
}

void XButton::activateWindow()
{
}

void XButton::setApplet(HWND parent, int& vOffsetX, int& vOffsetY, 
	int& hOffsetX, int& hOffsetY, XLayout* layout, int appletId, bool firstElem) {
	int _beginVertical = 0;
	int _beginHorizontal = 0;

	switch (layout->dir)
	{
	case LayoutDirection::None:
	case LayoutDirection::Vertical:

		_rect.right = _minimumWidth;
		_rect.bottom = _minimumHeight;

		//Save current rectangle and margins of applet
		XLayout::_properties.push_back(std::make_pair(_rect, _margins));

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
		_rect.right = _minimumWidth;
		_rect.bottom = _minimumHeight;

		XLayout::_properties.push_back(std::make_pair(_rect, _margins));
		//XLayout::_beginHeight

		if (!firstElem && XLayout::_appletId > 0) {
			XLayout::_betweenHorizontalApplets += XLayout::_properties.at(XLayout::_appletId - 1).first.right;
		}

		XLayout::_appletId++;

		break;
	default:
		break;
	}

	USES_CONVERSION;

	applet = CreateWindowEx(
		WS_EX_TRANSPARENT,
		L"BUTTON",																	//Predefined class; Unicode assumed.
		A2W(_text),																	//Button text.
		_windowState._state | BS_PUSHBUTTON,										//Styles.
		(layout->dir == LayoutDirection::Horizontal ? hOffsetX + XLayout::_betweenHorizontalApplets : vOffsetX),																	//x position.
		(layout->dir == LayoutDirection::Horizontal ? hOffsetY + XLayout::_beginHeight : /*_beginVertical + XLayout::_betweenVeticalApplets +*/ XLayout::_beginHeight),																	//y position.
		/*_rect.right*/_minimumWidth,																//Button width.
		/*_rect.bottom*/_minimumHeight,																//Button height.
		parent,																		//Parent window.
		(HMENU)BN_CLICKED,															//No menu.
		(HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),						
		NULL);																		//Pointer not needed.
}

