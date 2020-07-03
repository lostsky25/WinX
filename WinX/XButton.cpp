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

#define ID_BUTTON 100

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
	int& hOffsetX, int& hOffsetY, int layoutDirection, int layoutCount) {

	switch (layoutDirection)
	{
	case LayoutDirection::None:
	case LayoutDirection::Vertical:
		_rect.right = _minimumWidth;
		_rect.bottom = _minimumHeight;

		XLayout::_properties.insert(std::make_pair(this->currentId, std::make_pair(_rect, _margins)));

		updateSize();

		_margins.top += (this->currentId > 0 ? XLayout::_properties.find(this->currentId - 1)->second.first.bottom : 0);

		vOffsetX += 0;
		vOffsetY +=
			_margins.top +
			(this->currentId > 0 ? XLayout::_properties.find(this->currentId - 1)->second.second.bottom : 0);
		_margins.bottom;
		break;
	case LayoutDirection::Horizontal:
		_rect.right = _minimumWidth;
		_rect.bottom = _minimumHeight;

		XLayout::_properties.insert(std::make_pair(this->currentId, std::make_pair(_rect, _margins)));

		updateSize();

		//_margins.top += (this->currentId > 0 ? XLayout::_properties.find(this->currentId - 1)->second.first.bottom : 0);
		
		if (baseInfo.find(this->currentId)->second) {
			hOffsetY += _height + XLayout::_properties.find(this->currentId - layoutCount - 1)->second.second.bottom;
			hOffsetX =
				(this->currentId > 0 ? 0 : 0);
		}
		else {
			hOffsetY += 0;
			hOffsetX +=
				(this->currentId > 0 ? _width + XLayout::_properties.find(this->currentId - 1)->second.second.right : 0);

			if (!baseInfo.find(this->currentId)->second) {
				hOffsetX += XLayout::_properties.find(this->currentId - 1)->second.second.left;
			}
		}

		//if (XButton::idBtn == 0) {
		//hOffsetY = _height;
			//_height = 0;
		//}
		//else {
			//hOffsetY += _height;
		//}
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
		_rect.x + _margins.left + (layoutDirection == LayoutDirection::Horizontal ? hOffsetX : vOffsetX),																	//x position.
		_rect.y + (layoutDirection == LayoutDirection::Horizontal ? hOffsetY + vOffsetY : vOffsetY),																	//y position.
		/*_rect.right*/_minimumWidth,																//Button width.
		/*_rect.bottom*/_minimumHeight,																//Button height.
		parent,																		//Parent window.
		(HMENU)BN_CLICKED,															//No menu.
		(HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),						
		NULL);																		//Pointer not needed.
}
