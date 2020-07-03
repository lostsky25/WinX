#include "XButton.h"

#define ID_BUTTON 100

//
//LPWSTR XButton::getText()
//{
//	return this->_text;
//}

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
	int& hOffsetX, int& hOffsetY, int layoutDirection, int layoutCount, int id) {

	switch (layoutDirection)
	{
	case LayoutDirection::None:
	case LayoutDirection::Vertical:
		_rect.right = _minimumWidth;
		_rect.bottom = _minimumHeight;

		XLayout::_properties.push_back(std::make_pair(_rect, _margins));

		updateSize();

		_margins.top += (this->currentId > 0 ? XLayout::_properties.at(id - 1).first.bottom : 0);

		vOffsetX += _margins.left;

		vOffsetY +=
			_margins.top +
			(this->currentId > 0 ? XLayout::_properties.at(id - 1).second.bottom : 0);
		
		break;
	case LayoutDirection::Horizontal:
		_rect.right = _minimumWidth;
		_rect.bottom = _minimumHeight;

		XLayout::_properties.push_back(std::make_pair(_rect, _margins));

		if (baseInfo.find(this->currentId)->second) {
			hOffsetX = 0;
			hOffsetY += _height + XLayout::_properties.at(id - 1).first.bottom;
			hOffsetX += _margins.left + _margins.right;
		}
		else {
			hOffsetX += XLayout::_properties.at(id - 1).first.right +
				_margins.left + _margins.right;//_margins.left + _margins.right + _minimumWidth;
		}

		break;
	default:
		break;
	}

	USES_CONVERSION;

	applet = CreateWindowEx(
		WS_EX_TRANSPARENT,
		L"BUTTON",																	//Predefined class; Unicode assumed.
		A2W(_text),																		//Button text.
		_windowState._state | BS_PUSHBUTTON,										//Styles.
		_rect.x + (layoutDirection == LayoutDirection::Horizontal ? hOffsetX : vOffsetX),																	//x position.
		_rect.y + (layoutDirection == LayoutDirection::Horizontal ? hOffsetY + vOffsetY : vOffsetY),																	//y position.
		/*_rect.right*/_minimumWidth,																//Button width.
		/*_rect.bottom*/_minimumHeight,																//Button height.
		parent,																		//Parent window.
		(HMENU)BN_CLICKED,															//No menu.
		(HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),						
		NULL);																		//Pointer not needed.
}
