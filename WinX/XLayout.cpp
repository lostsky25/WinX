#include "XLayout.h"

int XLayout::_layoutId = 0;
int XLayout::_betweenVeticalApplets;
int XLayout::_betweenHorizontalApplets;
int XLayout::_appletId = 0;
int XLayout::_beginHeight;
int XLayout::_beginWidth;
int XLayout::_beginHeightMargins;
int XLayout::_beginWidthMargins;
std::vector<int> XLayout::_maxHorizontalElement;
std::vector<int> XLayout::_maxVerticalElement;
std::vector<int> XLayout::_beginVerticalLayout;
std::vector<int> XLayout::_beginHorizontalLayout;
std::vector<std::pair<XTypes::XRect, XTypes::XMargins>> XLayout::_properties;					//Window margins (left, top, right, bottom).