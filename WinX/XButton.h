#pragma once

#include "XApplet.h"

class XButton : public XApplet
{
public:
	XButton();
	~XButton();
	
	virtual void setApplet(XHANDLE*, XLayout*, int, bool) override;

protected:
	friend class XApplication;
	friend class XHLayout;
	friend class XVLayout;

};