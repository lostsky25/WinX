#include "XVLayout.h"

//template <class T>
//std::vector<T*> XVLayout::applets;
//
//std::queue<XButton*> XVLayout::waitingButtonts;
//std::queue<XComboBox*> XVLayout::waitingComboBox;

int XVLayout::_beginHeight = 0;

XVLayout::XVLayout() {
	dir = Vertical;
	id = ++XLayout::_layoutId;
}

XVLayout::~XVLayout()
{

}

void XVLayout::deleteApplet(int index)
{
}

void XVLayout::destroyedLayout()
{
}

void XVLayout::activate()
{
}

void XVLayout::addSpacing(int space)
{
}

int XVLayout::count()
{
	return _count;
}
