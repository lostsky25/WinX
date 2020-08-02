#pragma once
#include <IntSafe.h>
#include <cstddef>
#include <stdexcept>

class XWindowFlags
{
public:
	XWindowFlags();

	DWORD extendedFlags();
	DWORD flags();

	void setExtendedFlags(DWORD);
	void setFlags(DWORD);

	void addExtendedFlags(DWORD);
	void addFlags(DWORD);

	~XWindowFlags();

private:
	DWORD _extendedFlags = 0;
	DWORD _flags = 0;
};

