#include "XVLayout.h"

//template <class T>
//std::vector<T*> XVLayout::applets;
//
//std::queue<XButton*> XVLayout::waitingButtonts;
//std::queue<XComboBox*> XVLayout::waitingComboBox;

XVLayout::XVLayout() {
	dir = Vertical;
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
