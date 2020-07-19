#include "XSize.h"

XSize::XSize()
{
	this->_height = 0;
	this->_width = 0;
}

XSize::XSize(unsigned _widht, unsigned _height) : _height(_height), _width(_width)
{

}

XSize::~XSize()
{
}

int XSize::height()
{
	return this->_height;
}

int XSize::width()
{
	return this->_width;
}

void XSize::setHeight(int _height)
{
	this->_height = _height;
}

void XSize::setWidth(int _width)
{
	this->_width = _width;
}
