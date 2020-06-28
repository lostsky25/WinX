#include "XLayout.h"

int XLayout::_layoutId;

std::map<int, std::pair<XTypes::XRect, XTypes::XMargins>> XLayout::_properties;					//Window margins (left, top, right, bottom).

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