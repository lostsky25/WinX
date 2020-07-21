#include "XMargins.h"
#include <ostream>

XMargins::XMargins(int left, int top, int right, int bottom) :
	_left(left), _top(top), _right(right), _bottom(bottom){

}

void XMargins::setMargins(int left, int top, int right, int bottom) {
	_left = left;
	_top = top;
	_right = right;
	_bottom = bottom;
}

XMargins XMargins::margins()
{
	return XMargins(_left, _top, _right, _bottom);
}

int XMargins::left()
{
	return _left;
}

int XMargins::top()
{
	return _top;
}

int XMargins::right()
{
	return _right;
}

int XMargins::bottom()
{
	return _bottom;
}

void XMargins::setLeft(int left)
{
	_left = left;
}

void XMargins::setTop(int top)
{
	_top = top;
}

void XMargins::setRight(int right)
{
	_right = right;
}

void XMargins::setBottom(int bottom)
{
	_bottom = bottom;
}