#pragma once

//#include "XApplication.h"

#include "XApplet.h"

class XButton : XApplet
{
public:
	XButton();
	void SetText(LPWSTR);	
	LPWSTR GetText();

	// ������������ ����� XApplet
	virtual void SetMinimumWidth(int) override;
	virtual void SetMinimumHeight(int) override;
	virtual int GetWidth() override;
	virtual int GetHeight() override;
	// !������������ ����� XApplet

private:

protected:
	friend class XApplication;

	// ������������ ����� XApplet
	virtual void SetApplet(HWND, int, int) override;
	// !������������ ����� XApplet

};