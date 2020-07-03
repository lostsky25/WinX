//#include "XComboBox.h"
//
//XComboBox::XComboBox() {
//
//}
//
//void XComboBox::SetApplet(HWND parent, int offsetX, int offsetY) {
//	applet = CreateWindowEx(
//		//WS_EX_LAYOUTRTL | WS_EX_APPWINDOW | BS_COMMANDLINK | BS_DEFPUSHBUTTON,
//		WS_EX_STATICEDGE,
//		L"COMBOBOX",  // Predefined class; Unicode assumed 
//		L"XCombo1",      // Button text 
//		CBS_DROPDOWN | WS_CHILD | WS_VISIBLE,  // Styles 
//		offsetX + 0,         // x position 
//		offsetY + 0,         // y position 
//		width,        // Button width
//		height,        // Button height
//		parent,     // Parent window
//		(HMENU)BN_CLICKED,       // No menu.
//		(HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
//		NULL);      // Pointer not needed.
//
//	for (int i = 0; i < messages.size(); i++) {
//		SendMessageW(applet, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPWSTR)messages.at(i)));
//	}
//}
////
////int XComboBox::SelectedIndex() {
////	return SendMessageW(applet, CB_GETCURSEL, 0, 0);
////}
//
//void XComboBox::AppendItem(LPWSTR text) {
//	messages.push_back(text);
//	SendMessageW(applet, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPWSTR)text));
//}
//
//void XComboBox::SetMinimumWidth(int width)
//{
//	this->width = width;
//}
//
//void XComboBox::SetMinimumHeight(int height)
//{
//	this->height = height;
//}
//
//int XComboBox::GetWidth()
//{
//	return width;
//}
//
//int XComboBox::GetHeight()
//{
//	return height;
//}
//
////
////void XComboBox::SetApplet(HWND parent, int offsetX, int offsetY) {
////	applet = CreateWindowEx(
////		//WS_EX_LAYOUTRTL | WS_EX_APPWINDOW | BS_COMMANDLINK | BS_DEFPUSHBUTTON,
////		WS_EX_STATICEDGE,
////		L"COMBOBOX",  // Predefined class; Unicode assumed 
////		L"XCombo1",      // Button text 
////		CBS_DROPDOWN | WS_CHILD | WS_VISIBLE,  // Styles 
////		offsetX + 0,         // x position 
////		offsetY + 0,         // y position 
////		width,        // Button width
////		height,        // Button height
////		parent,     // Parent window
////		(HMENU)BN_CLICKED,       // No menu.
////		(HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
////		NULL);      // Pointer not needed.
////
////	for (int i = 0; i < messages.size(); i++) {
////		SendMessageW(applet, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPWSTR)messages.at(i)));
////	}
////}
//////
//////int XComboBox::SelectedIndex() {
//////	return SendMessageW(applet, CB_GETCURSEL, 0, 0);
//////}
////
////void XComboBox::AppendItem(LPWSTR text) {
////	messages.push_back(text);
////	SendMessageW(applet, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPWSTR)text));
////}
////
////void XComboBox::SetMinimumWidth(int width)
////{
////	this->width = width;
////}
////
////void XComboBox::SetMinimumHeight(int height)
////{
////	this->height = height;
////}
////
////int XComboBox::GetWidth()
////{
////	return width;
////}
////
////int XComboBox::GetHeight()
////{
////	return height;
////}
