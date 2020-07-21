#include "XLayout.h"

int XLayout::layoutId = 0;
int XLayout::betweenVeticalApplets;
int XLayout::betweenHorizontalApplets;
int XLayout::appletId = 0;
int XLayout::beginHeight;
int XLayout::beginWidth;
int XLayout::beginHeightMargins;
int XLayout::beginWidthMargins;
std::vector<int> XLayout::maxHorizontalElement;
std::vector<int> XLayout::maxVerticalElement;
std::vector<int> XLayout::beginVerticalLayout;
std::vector<int> XLayout::beginHorizontalLayout;
std::vector<std::pair<XRect, XMargins>> XLayout::properties;					//Window margins (left, top, right, bottom).