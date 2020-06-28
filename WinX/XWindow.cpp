#include "XWindow.h"

void XWindow::updateSize()
{
	this->_width = this->_minimumWidth + this->_maximumWidth;
	this->_height = this->_minimumHeight + this->_maximumHeight;

	this->_x = this->_minimumWidth;
	this->_y = this->_minimumHeight;
}