#include "XWindowFlags.h"

XWindowFlags::XWindowFlags()//(DWORD _flags) : _flags(_flags)
{
}

DWORD XWindowFlags::extendedFlags()
{
	if (this->_extendedFlags == NULL)
	{
		throw std::invalid_argument("Extended flags value is empty.");
	}

	return this->_extendedFlags;
}


DWORD XWindowFlags::flags()
{
	return this->_flags;
}

void XWindowFlags::setExtendedFlags(DWORD _extendedFlags)
{
	this->_extendedFlags = _extendedFlags;

	if (this->_extendedFlags == NULL)
	{
		throw std::invalid_argument("Flags value is empty.");
	}
}

void XWindowFlags::setFlags(DWORD _flags)
{
	this->_flags = _flags;
}

XWindowFlags::~XWindowFlags()
{

}