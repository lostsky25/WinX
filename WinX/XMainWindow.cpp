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
	/*btn1 = new XButton();
	comboBox1 = new XComboBox();

	btn1->SetMinimumHeight(50);
	btn1->SetMinimumWidth(200);
	btn1->SetText((LPWSTR)L"jnfskajndjs");

	comboBox1->SetMinimumHeight(50);
	comboBox1->SetMinimumWidth(200);

<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
	parent.AppendApplet<XButton>(btn1);
	parent.AppendApplet<XComboBox>(comboBox1);
	parent.AppendApplet<XComboBox>(comboBox1);
	parent.AppendApplet<XComboBox>(comboBox1);*/
	
	//CONNECT(XButton, btn1, lala);
}

MyClass::~MyClass()
{
}

MyClass2::MyClass2(XApplication& parent)// : parent(parent)
{
	/*btn1 = new XButton();
	comboBox1 = new XComboBox();

	btn1->SetMinimumHeight(50);
	btn1->SetMinimumWidth(200);
	btn1->SetText((LPWSTR)L"jnfskajndjs");

	comboBox1->SetMinimumHeight(50);
	comboBox1->SetMinimumWidth(200);

<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
	parent.AppendApplet<XButton>(btn1);
	parent.AppendApplet<XComboBox>(comboBox1);
	parent.AppendApplet<XComboBox>(comboBox1);
	parent.AppendApplet<XComboBox>(comboBox1);*/

	//CONNECT(XButton, btn1, lala);
}

MyClass2::~MyClass2()
{
}

XMainWindow::XMainWindow(XParams xParams) {
	Application = new XApplication(xParams);

	//XButton* btn = new XButton();
	//XButton* btn2 = new XButton();
	//XComboBox* comboBox = new XComboBox();

	XButton* btn = new XButton();
	XButton* btn2 = new XButton();
	XButton* btn3 = new XButton();
	
	XButton* btn4 = new XButton();
	XButton* btn5 = new XButton();
	XButton* btn6 = new XButton();

	XButton* btn7 = new XButton();
	XButton* btn8 = new XButton();

	XButton* btn9 = new XButton();
	XButton* btn10 = new XButton();
	XButton* btn11 = new XButton();
	//XButton* btn7 = new XButton();

	//* m = new MyClass(*Application);
	//MyClass2* m2 = new MyClass2(*Application);
	
	//Application->AppendApplet<XButton>(btn);
	//Application->AppendApplet<XButton>(btn2);
	//Application->SetClickedEvent<XButton, MyClass>(*btn, m, &MyClass::clicked);
	//Application->SetClickedEvent<XButton, MyClass2>(*btn2, m2, &MyClass2::clicked);

	/*btn->setMargins(10, 10, 0, 0);
	btn2->setMargins(10, 100, 0, 10);
	btn3->setMargins(15, 5, 0, 0);*/
	btn4->setMargins(10, 10, 0, 10);
	btn5->setMargins(10, 100, 0, 10);
	btn6->setMargins(15, 5, 0, 0);

	btn7->setMargins(10, 100, 10, 10);
	btn8->setMargins(10, 110, 110, 10);

	btn9->setMargins(100, 0, 25, 0);
	btn10->setMargins(0, 150, 0, 0);
	btn11->setMargins(0, 0, 0, 0);

	btn->setMargins(0, 0, 0, 0);
	btn2->setMargins(0, 0, 0, 0);
	btn3->setMargins(0, 0, 0, 0);

	//btn4->setMargins(0, 0, 0, 0);
	//btn5->setMargins(0, 0, 0, 0);
	//btn6->setMargins(0, 0, 0, 0);
	//btn7->setMargins(0, 0, 0, 0);

	btn->setMinimumSize(200, 20);
	btn->setText("btn");
	
	btn2->setMinimumSize(200, 20);
	btn2->setText("btn2");

	btn3->setMinimumSize(200, 20);
	btn3->setText("btn3");
	
	btn4->setMinimumSize(200, 20);
	btn4->setText("btn4");

	btn5->setMinimumSize(200, 20);
	btn5->setText("btn5");

	btn6->setMinimumSize(200, 20);
	btn6->setText("btn6");

	btn7->setMinimumSize(200, 20);
	btn7->setText("btn7");

	btn8->setMinimumSize(200, 20);
	btn8->setText("btn8");

	btn9->setMinimumSize(300, 20);
	btn9->setText("btn9");

	btn10->setMinimumSize(300, 20);
	btn10->setText("btn10");

	btn11->setMinimumSize(400, 50);
	btn11->setText("btn11");

	//btn7->setMinimumSize(200, 20);
	//btn7->setText("btn7");

	//XWindowState wndSt;
	//wndSt.overlapped(true);

	Application->setCursor(CURSOR_CROSSHAIR);

	//Application->setIcon();
	//Application->setCursor(btn6->windowHandle(), CURSOR_CROSSHAIR);
	//btn6->setWindowState(wndSt);

	Application->appendApplet<XButton>(btn);
	Application->appendApplet<XButton>(btn2);
	Application->appendApplet<XButton>(btn3);

	Application->appendApplet<XButton>(btn4);
	//Application->appendApplet<XButton>(btn5);
	//Application->appendApplet<XButton>(btn6);
	//Application->appendApplet<XButton>(btn7);

	XVLayout* lv = new XVLayout();
	lv->addApplet<XButton>(btn5);
	lv->addApplet<XButton>(btn6);

	XHLayout* lv2 = new XHLayout();
	lv2->addApplet<XButton>(btn7);
	lv2->addApplet<XButton>(btn8);

	XHLayout* lv3 = new XHLayout();
	lv3->addApplet<XButton>(btn9);
	lv3->addApplet<XButton>(btn10);
	lv3->addApplet<XButton>(btn11);

	/*Application->setClickedEvent<XButton, MyClass>(*btn, m, &MyClass::clickEvent);
	Application->setClickedEvent<XButton, MyClass>(*btn2, m, &MyClass::clickEvent);
	Application->setClickedEvent<XButton, MyClass>(*btn3, m, &MyClass::clickEvent);
	Application->setClickedEvent<XButton, MyClass>(*btn4, m, &MyClass::clickEvent);
	Application->setClickedEvent<XButton, MyClass>(*btn5, m, &MyClass::clickEvent);
	Application->setClickedEvent<XButton, MyClass>(*btn6, m, &MyClass::clickEvent);
	Application->setClickedEvent<XButton, MyClass>(*btn7, m, &MyClass::clickEvent);*/

	//Application->setClickedEvent<XButton, MyClass2>(*btn2, m2, &MyClass2::clickEvent);
	//Application->AppendApplet<XButton>(btn2);

	//MyClass* myClass = new MyClass(*Application);
	//Application->SetClickedEvent<XButton>(btn2, ::foo2);

	//CONNECT(XButton, btn2, ::foo2);

	//Application->AppendApplet<XButton>(btn);
	//btn->SetMinimumHeight(25);
	//btn->SetMinimumWidth(100);
	//
	//Application->AppendApplet<XButton>(btn);
	//btn->SetMinimumHeight(50);
	//btn->SetMinimumWidth(100);

	//comboBox->AppendItem((LPWSTR)L"text1");
	//comboBox->AppendItem((LPWSTR)L"text2");
	//comboBox->AppendItem((LPWSTR)L"text3");
	//comboBox->AppendItem((LPWSTR)L"text4");
	//comboBox->AppendItem((LPWSTR)L"text5");
	//
	//Application->AppendApplet<XComboBox>(comboBox);

	Application->setLayout(lv);
	Application->setLayout(lv2);
	Application->setLayout(lv3);

	Application->WindowUpdate();
}