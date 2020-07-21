#pragma once
#include <IntSafe.h>

class XWindowType
{
public:
	XWindowType();
	XWindowType(DWORD);

	DWORD type();
	void setType(DWORD);


	~XWindowType();

private:
	DWORD _type = 0;
};

