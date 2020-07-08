#include "XLayout.h"

int XLayout::_layoutId = 0;
int XLayout::_betweenVeticalApplets;
int XLayout::_betweenHorizontalApplets;
int XLayout::_appletId = 0;
int XLayout::_beginHeight;
int XLayout::_beginWidth;
std::vector<int> XLayout::_beginVerticalLayout;
std::vector<int> XLayout::_beginHorizontalLayout;
std::vector<std::pair<XTypes::XRect, XTypes::XMargins>> XLayout::_properties;					//Window margins (left, top, right, bottom).

//XTypes::XMargins XLayout::margins() {
//	//return _margins;
//}
//
//void XLayout::setMargin(XTypes::XMargins margins) {
//	//_margins = margins;
//}
//
//void XLayout::setMargin(int left, int top, int right, int bottom) {
//	//_margins = {left, top, right, bottom};
//}