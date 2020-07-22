#pragma once

#include "XApplet.h"

class XLabel : public XApplet
{
public:
	XLabel();
	~XLabel();

	void setApplet(XHANDLE*, XLayout*, int, bool);

protected:
	friend class XApplication;
	friend class XHLayout;
	friend class XVLayout;
};

