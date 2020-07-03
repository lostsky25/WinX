#pragma once

//#include "XApplication.h"

#include "XApplet.h"

//class XButton : XApplet
//{
//public:
//	XButton();
//	void SetText(LPWSTR);	
//	LPWSTR GetText();
//
//	// Унаследовано через XApplet
//	virtual void SetMinimumWidth(int) override;
//	virtual void SetMinimumHeight(int) override;
//	virtual int GetWidth() override;
//	virtual int GetHeight() override;
//	// !Унаследовано через XApplet
//
//private:
//
//protected:
//	friend class XApplication;
//
//	// Унаследовано через XApplet
//	virtual void SetApplet(HWND, int, int) override;
//	// !Унаследовано через XApplet

class XButton : public XApplet
{
public:
	XButton() {
		this->currentId = idBtn;
		++idBtn;
	}

	//~XButton();

	void setMargins(int, int, int, int);

	void setText(LPCSTR);
	
	virtual XTypes::XSize iconSize() override;
	virtual void setWindowTitle(XString) override;
	virtual XString windowTitle() override;
	virtual void setWindowState(XTypes::XWindowState) override;
	virtual XTypes::XSize size() override;
	virtual XTypes::XSize sizeIncrement() override;
	virtual void setBaseSize(XTypes::XSize) override;
	virtual void setBaseSize(int, int) override;
	virtual XTypes::XWindowFlags windowFlags() override;
	virtual XTypes::XIcon windowIcon() override;
	virtual float windowOpacity() override;
	virtual XTypes::XWindowState windowState() override;
	virtual XTypes::XWindowType windowType() override;
	virtual void setWindowIcon(XTypes::XIcon) override;
	virtual void setWindowOpacity(float) override;
	virtual void setFixedHeight(int) override;
	virtual void setFixedSize(XTypes::XSize) override;
	virtual void setFixedSize(int, int) override;
	virtual void activateWindow() override;
	virtual void setApplet(HWND, int&, int&, int&, int&, int, int, int) override;

	virtual int width() override;
	virtual int height() override;

private:
	static int idBtn;
	int currentId;

	std::map<int, bool> baseInfo;

protected:
	friend class XApplication;
	friend class XHLayout;
	friend class XVLayout;
};