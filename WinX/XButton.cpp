#include "XButton.h"

XButton::XButton() {

}

#define ID_BUTTON 100

void XButton::SetApplet(HWND parent, int offsetX, int offsetY) {
	applet = CreateWindowEx(
		//WS_EX_LAYOUTRTL | WS_EX_APPWINDOW | BS_COMMANDLINK | BS_DEFPUSHBUTTON,
		WS_EX_TRANSPARENT,
		L"BUTTON",  // Predefined class; Unicode assumed 
		text,      // Button text 
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // Styles 
		offsetX + 0,         // x position 
		offsetY + 0,         // y position 
		width,        // Button width
		height,        // Button height
		parent,     // Parent window
		(HMENU)BN_CLICKED,       // No menu.
		(HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.
}

LPWSTR XButton::GetText()
{
	return this->text;
}

void XButton::SetText(LPWSTR text)
{
	this->text = text;
}

void XButton::SetMinimumWidth(int width)
{
	this->width = width;
}

void XButton::SetMinimumHeight(int height)
{
	this->height = height;
}

int XButton::GetWidth()
{
	return width;
}

int XButton::GetHeight()
{
	return height;
}
