#pragma once

//#include "XApplication.h"

#include "XApplet.h"

class XButton : XApplet
{
public:
	XButton();
	void SetText(LPWSTR);	
	LPWSTR GetText();

	// Унаследовано через XApplet
	virtual void SetMinimumWidth(int) override;
	virtual void SetMinimumHeight(int) override;
	virtual int GetWidth() override;
	virtual int GetHeight() override;
	// !Унаследовано через XApplet

private:

protected:
	friend class XApplication;

	// Унаследовано через XApplet
	virtual void SetApplet(HWND, int, int) override;
	// !Унаследовано через XApplet

};