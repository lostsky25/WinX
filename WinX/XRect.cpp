#include "XRect.h"

XRect::XRect(int x, int y, int right, int bottom) :
	_x(x), _y(y), _right(right), _bottom(bottom) {

}

void XRect::setRect(int x, int y, int right, int bottom)
{
	_x = x;
	_y = y;
	_right = right;
	_bottom = bottom;
}

XRect XRect::rect()
{
	return XRect(_x, _y, _right, _bottom);
}

int XRect::x()
{
	return _x;
}

int XRect::y()
{
	return _y;
}

int XRect::right()
{
	return _right;
}

int XRect::bottom()
{
	return _bottom;
}

void XRect::setX(int x)
{
	_x = x;
}

void XRect::setY(int y)
{
	_y = y;
}

void XRect::setRight(int right)
{
	_right = right;
}

void XRect::setBottom(int bottom)
{
	_bottom = bottom;
}
