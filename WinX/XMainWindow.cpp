#include "XMainWindow.h"
#include "XParams.h"

#define XDebug

#include "XMainWindow.h"

#include "XVLayout.h"
#include "XObject.h"

//using namespace XTypes;

void foo2() {
	OutputDebugStringA("Clicked2\r\n");
}

class ExplorerDialog : public XObject
{
public:
	ExplorerDialog(XApplication& parent);
	~ExplorerDialog() = default;

	void clicked() override {
		OutputDebugStringA("Clicked1\r\n");
		
	}

	void released() override {

	}
};

class MyClass2 : public XObject
{
public:
	MyClass2(XApplication& parent);
	~MyClass2() = default;

	void clicked() override {
		OutputDebugStringA("Clicked2\r\n");
	}

	void released() override {

	}
};

class MyClass3 : public XObject
{
public:
	MyClass3(XApplication& parent);
	~MyClass3() = default;

	void clicked() override {
		OutputDebugStringA("Clicked3\r\n");
	}

	void released() override {

	}
};

ExplorerDialog::ExplorerDialog(XApplication& parent)// : parent(parent)
{

}

MyClass2::MyClass2(XApplication& parent)// : parent(parent)
{

}

MyClass3::MyClass3(XApplication& parent)// : parent(parent)
{

}

XMainWindow::XMainWindow(XParams xParams) {
	Application = new XApplication(xParams);
	//Application->setWindowOpacity(0.2);

	ExplorerDialog* explorerDialog = new ExplorerDialog(*Application);
	MyClass2* m = new MyClass2(*Application);
	MyClass3* m2 = new MyClass3(*Application);
	
	XButton* btn4 = new XButton();
	XButton* btn5 = new XButton();
	XButton* btn = new XButton();
	XButton* btn7 = new XButton();
	XButton* btn2 = new XButton();
	XButton* btn6 = new XButton();
	XButton* btn3 = new XButton();

	XLabel* lb1 = new XLabel();

	lb1->setMinimumSize(50, 20);
	lb1->setWindowName(L"Some text:");

	btn->setMinimumSize(200, 20);
	btn->setWindowName(L"Open explorer");

	//btn->setWindowOpacity(0.9);

	btn2->setMinimumSize(200, 234);
	btn2->setWindowName(L"btn2");

	btn3->setMinimumSize(500, 50);
	btn3->setWindowName(L"btn3");

		btn4->setMinimumSize(250, 123);
		btn4->setWindowName(L"btn4");

	btn5->setMinimumSize(200, 50);
	btn5->setWindowName(L"btn5");

		btn6->setMinimumSize(500, 126);
		btn6->setWindowName(L"btn6");

		btn7->setMinimumSize(500, 126);
		btn7->setWindowName(L"btn7");

	btn->setMargins(0, 10, 0, 30);
	btn2->setMargins(0, 10, 0, 10);
	btn3->setMargins(0, 20, 0, 5);

		btn4->setMargins(0, 30, 0, 30);
	btn5->setMargins(0, 40, 0, 25);
		btn6->setMargins(0, 50, 0, 10);
		btn7->setMargins(0, 10, 0, 15);

	XVLayout* lv = new XVLayout();
	lv->addApplet<XButton>(btn);
	lv->addApplet<XButton>(btn2);
	lv->addApplet<XButton>(btn3);
	lv->addApplet<XLabel>(lb1);

	XVLayout* lv2 = new XVLayout();
	lv2->addApplet<XButton>(btn5);
	lv2->addApplet<XButton>(btn6);
	lv2->addApplet<XButton>(btn4);

	XHLayout* lv3 = new XHLayout();
	lv3->addApplet<XButton>(btn7);
	lv3->addApplet<XButton>(btn6);
	lv3->addApplet<XButton>(btn4);

	XVLayout* lv6 = new XVLayout();
	lv6->addApplet<XButton>(btn7);
	lv6->addApplet<XButton>(btn6);
	lv6->addApplet<XButton>(btn4);

	XHLayout* lv5 = new XHLayout();
	lv5->addApplet<XButton>(btn6);
	lv5->addApplet<XButton>(btn4);
	lv5->addApplet<XButton>(btn7);

	//XVLayout* lv4 = new XVLayout();
	//lv4->addApplet<XButton>(btn7);
	//lv4->addApplet<XButton>(btn6);
	//lv4->addApplet<XButton>(btn4);

	//Application->appendApplet(btn);

	Application->setCursor(CURSOR_CROSSHAIR);
	
	Application->setClickedEvent<XButton, ExplorerDialog>(*btn, explorerDialog, &ExplorerDialog::clicked);
	Application->setClickedEvent<XButton, MyClass3>(*btn3, m2, &MyClass3::clicked);
	Application->setClickedEvent<XButton, MyClass2>(*btn2, m, &MyClass2::clicked);

	//Application->setClickedEvent<XButton, MyClass2>(*btn, m, &MyClass2::clicked);
	//Application->setClickedEvent<XButton, ExplorerDialog>(*btn2, explorerDialog, &ExplorerDialog::clicked);
	//Application->setClickedEvent<XButton, ExplorerDialog>(*btn3, explorerDialog, &ExplorerDialog::clicked);

	Application->setLayout(lv);
	//Application->setLayout(lv2);
	Application->setLayout(lv3);
	//Application->setLayout(lv6);
	Application->setLayout(lv5);
	//Application->setLayout(lv4);

	Application->windowUpdate();
}