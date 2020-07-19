#include "xhandle.h"

XHANDLE::XHANDLE()
{
	window = new __xhandle();
}

XHANDLE::~XHANDLE()
{
	delete window;
}