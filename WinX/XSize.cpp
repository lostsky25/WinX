#include "XSize.h"

XSize::XSize()
{
	_height = 0;
	_width = 0;
}

XSize::XSize(unsigned widht, unsigned height) : _height(height), _width(_width)
{

}

XSize::~XSize()
{
}

unsigned XSize::height()
{
	return _height;
}

unsigned XSize::width()
{
	return _width;
}

void XSize::setHeight(unsigned height)
{
	_height = height;
}

void XSize::setWidth(unsigned width)
{
	_width = width;
}
