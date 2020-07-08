#include "XMainWindow.h"
#include "XParams.h"

#define XDebug

#include "XMainWindow.h"

#include "XVLayout.h"
#include "XEvent.h"

using namespace XTypes;


void foo2() {
	OutputDebugStringA("Clicked2\r\n");
}

class MyClass : public XEvent
{
public:
	MyClass(XApplication& parent);
	~MyClass();

	void clickEvent() override {
		OutputDebugStringA("Clicked\r\n");
	}
};

class MyClass2 : public XEvent
{
public:
	MyClass2(XApplication& parent);
	~MyClass2();

	void clickEvent() override {
		OutputDebugStringA("Clicked2\r\n");
	}
};

MyClass::MyClass(XApplication& parent)// : parent(parent)
{

}

MyClass::~MyClass()
{
}

MyClass2::MyClass2(XApplication& parent)// : parent(parent)
{

}

MyClass2::~MyClass2()
{
}

XMainWindow::XMainWindow(XParams xParams) {
	Application = new XApplication(xParams);

	//XButton* btn = new XButton();
	//XButton* btn2 = new XButton();
	//XComboBox* comboBox = new XComboBox();
	
	XButton* btn4 = new XButton();
	XButton* btn5 = new XButton();
	XButton* btn = new XButton();
	XButton* btn7 = new XButton();

	XButton* btn2 = new XButton();
	XButton* btn6 = new XButton();

	XButton* btn3 = new XButton();

	/*
	XButton* btn4 = new XButton();
	XButton* btn5 = new XButton();
	XButton* btn6 = new XButton();*/

	btn->setMinimumSize(200, 20);
	btn->setText("btn");

	btn2->setMinimumSize(200, 234);
	btn2->setText("btn2");

	btn3->setMinimumSize(500, 50);
	btn3->setText("btn3");

	btn4->setMinimumSize(250, 123);
	btn4->setText("btn4");

	btn5->setMinimumSize(200, 50);
	btn5->setText("btn5");

	btn6->setMinimumSize(500, 126);
	btn6->setText("btn6");

	btn7->setMinimumSize(500, 126);
	btn7->setText("btn7");

	btn->setMargins(0, 0, 0, 0);
	btn2->setMargins(0, 0, 0, 0);
	btn3->setMargins(0, 0, 0, 0);

	btn4->setMargins(0, 0, 0, 0);
	btn5->setMargins(0, 0, 0, 0);
	btn6->setMargins(0, 0, 0, 0);
	btn7->setMargins(0, 0, 0, 0);

	/*btn4->setMargins(0, 0, 0, 0);
	btn5->setMargins(0, 0, 0, 0);
	btn6->setMargins(0, 0, 0, 0);*/


	//btn4->setMinimumSize(200, 100);
	//btn4->setText("btn4");

	//btn5->setMinimumSize(200, 30);
	//btn5->setText("btn5");

	//btn6->setMinimumSize(500, 100);
	//btn6->setText("btn6");

	XVLayout* lv = new XVLayout();
	lv->addApplet<XButton>(btn);
	lv->addApplet<XButton>(btn2);
	lv->addApplet<XButton>(btn3);

	XVLayout* lv2 = new XVLayout();
	lv2->addApplet<XButton>(btn5);
	lv2->addApplet<XButton>(btn6);
	lv2->addApplet<XButton>(btn4);

	XHLayout* lv3 = new XHLayout();
	lv3->addApplet<XButton>(btn7);
	lv3->addApplet<XButton>(btn6);
	lv3->addApplet<XButton>(btn4);

	XVLayout* lv4 = new XVLayout();
	lv4->addApplet<XButton>(btn7);
	lv4->addApplet<XButton>(btn6);
	lv4->addApplet<XButton>(btn4);

	/*lv3->addApplet<XButton>(btn4);*/

	//XHLayout* lh = new XHLayout();
	//lh->addApplet<XButton>(btn);
	//lh->addApplet<XButton>(btn2);
	//lh->addApplet<XButton>(btn3);

	//XHLayout* lh2 = new XHLayout();
	//lh2->addApplet<XButton>(btn4);
	//lh2->addApplet<XButton>(btn5);
	//lh2->addApplet<XButton>(btn6);

	Application->setCursor(CURSOR_CROSSHAIR);

	Application->setLayout(lv);
	Application->setLayout(lv3);
	Application->setLayout(lv4);
	//Application->setLayout(lv2);

//	MyClass* m = new MyClass(*Application);
//	//MyClass2* m2 = new MyClass2(*Application);
//	
//	//Application->AppendApplet<XButton>(btn);
//	//Application->AppendApplet<XButton>(btn2);
//	//Application->SetClickedEvent<XButton, MyClass>(*btn, m, &MyClass::clicked);
//	//Application->SetClickedEvent<XButton, MyClass2>(*btn2, m2, &MyClass2::clicked);
//
//	/*btn->setMargins(10, 10, 0, 0);
//	btn2->setMargins(10, 100, 0, 10);
//	btn3->setMargins(15, 5, 0, 0);*/
//	btn4->setMargins(10, 10, 0, 10);
//	btn5->setMargins(10, 100, 0, 10);
//	btn6->setMargins(15, 5, 0, 0);
//
//	btn7->setMargins(10, 0, 0, 0);
//	btn8->setMargins(0, 0, 0, 0);
//
////////////////////////////////////////////////////////////////
//	btn9->setMargins(15, 0, 0, 0);
//	btn10->setMargins(20, 0, 0, 0);
//	btn11->setMargins(0, 0, 0, 0);
//
//	btn12->setMargins(0, 0, 0, 0);
//	btn13->setMargins(0, 0, 0, 0);
//	btn14->setMargins(0, 0, 0, 0);
////////////////////////////////////////////////////////////////
//
//	btn->setMargins(0, 0, 0, 0);
//	btn2->setMargins(0, 0, 0, 0);
//	btn3->setMargins(0, 0, 0, 0);
//
//	btn->setMinimumSize(200, 20);
//	btn->setText("btn");
//	
//	btn2->setMinimumSize(200, 20);
//	btn2->setText("btn2");
//
//	btn3->setMinimumSize(200, 20);
//	btn3->setText("btn3");
//	
//	btn4->setMinimumSize(200, 20);
//	btn4->setText("btn4");
//
//	btn5->setMinimumSize(200, 20);
//	btn5->setText("btn5");
//
//	btn6->setMinimumSize(200, 20);
//	btn6->setText("btn6");
//
//	btn7->setMinimumSize(100, 20);
//	btn7->setText("btn7");
//
//	btn8->setMinimumSize(700, 20);
//	btn8->setText("btn8");
//
//	btn9->setMinimumSize(300, 20);
//	btn9->setText("btn9");
//
//	btn10->setMinimumSize(100, 100);
//	btn10->setText("btn10");
//
//	btn11->setMinimumSize(200, 250);
//	btn11->setText("btn11");
//
//	btn12->setMinimumSize(300, 200);
//	btn12->setText("btn12");
//
//	btn13->setMinimumSize(100, 20);
//	btn13->setText("btn13");
//
//	btn14->setMinimumSize(200, 200);
//	btn14->setText("btn14");
//
//	//btn7->setMinimumSize(200, 20);
//	//btn7->setText("btn7");
//
//	//XWindowState wndSt;
//	//wndSt.overlapped(true);
//
//	Application->setCursor(CURSOR_CROSSHAIR);
//
//	//Application->setIcon();
//	//Application->setCursor(btn6->windowHandle(), CURSOR_CROSSHAIR);
//	//btn6->setWindowState(wndSt);
//
//	Application->appendApplet<XButton>(btn);
//	Application->appendApplet<XButton>(btn2);
//	Application->appendApplet<XButton>(btn5);
//
//	Application->appendApplet<XButton>(btn4);
//
//	XVLayout* lv = new XVLayout();
//	lv->addApplet<XButton>(btn3);
//	lv->addApplet<XButton>(btn6);
//
//	XHLayout* lv2 = new XHLayout();
//	lv2->addApplet<XButton>(btn7);
//	lv2->addApplet<XButton>(btn8);
//
//	XHLayout* lv3 = new XHLayout();
//	lv3->addApplet<XButton>(btn9);
//	lv3->addApplet<XButton>(btn10);
//	lv3->addApplet<XButton>(btn11);
//
//	XHLayout* lv4 = new XHLayout();
//	lv4->addApplet<XButton>(btn12);
//	lv4->addApplet<XButton>(btn13);
//	lv4->addApplet<XButton>(btn14);
//
//	Application->setClickedEvent<XButton, MyClass>(*btn, m, &MyClass::clickEvent);
//	/*Application->setClickedEvent<XButton, MyClass>(*btn2, m, &MyClass::clickEvent);
//	Application->setClickedEvent<XButton, MyClass>(*btn3, m, &MyClass::clickEvent);
//	Application->setClickedEvent<XButton, MyClass>(*btn4, m, &MyClass::clickEvent);
//	Application->setClickedEvent<XButton, MyClass>(*btn5, m, &MyClass::clickEvent);
//	Application->setClickedEvent<XButton, MyClass>(*btn6, m, &MyClass::clickEvent);
//	Application->setClickedEvent<XButton, MyClass>(*btn7, m, &MyClass::clickEvent);*/
//
//	Application->setLayout(lv);
//	Application->setLayout(lv2);
//	Application->setLayout(lv3);
//	Application->setLayout(lv4);

	Application->WindowUpdate();
}