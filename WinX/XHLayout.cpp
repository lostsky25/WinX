#include "XHLayout.h"

//std::queue<XButton*> XHLayout::waitingButtonts;
//std::queue<XComboBox*> XHLayout::waitingComboBox;

XHLayout::XHLayout() {
	XLayout::_layoutId++;
	dir = Horizontal;
}

XHLayout::~XHLayout() {

}

void XHLayout::deleteApplet(int index)
{
}

void XHLayout::destroyedLayout()
{
}

void XHLayout::activate()
{
}

void XHLayout::addSpacing(int space)
{
}

int XHLayout::count()
{
	return _count;
}
