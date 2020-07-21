#pragma once

#include "XApplet.h"

class XButton : public XApplet
{
public:
	XButton();
	~XButton();
	
	void setApplet(XHANDLE*, XLayout*, int, bool);

protected:
	friend class XApplication;
	friend class XHLayout;
	friend class XVLayout;

};