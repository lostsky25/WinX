#include "XWindowType.h"

XWindowType::XWindowType() {

}

XWindowType::XWindowType(DWORD _type) : _type(_type)
{
	this->_type = _type;
}

DWORD XWindowType::type()
{
	return this->_type;
}

void XWindowType::setType(DWORD _type)
{
	this->_type = _type;
}

XWindowType::~XWindowType()
{
}
