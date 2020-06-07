#include "XMainWindow.h"
#include "XParams.h"

#include "Base.h"

void foo2() {
	OutputDebugStringA("Clicked2\r\n");
}

class MyClass : public Base
{
public:
	MyClass(XApplication& parent);
	~MyClass();
	
	void clicked() override {
		OutputDebugStringA("Clicked\r\n");
	}
};

class MyClass2 : public Base
{
public:
	MyClass2(XApplication& parent);
	~MyClass2();

	void clicked() override {
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


	XButton* btn = new XButton();
	XButton* btn2 = new XButton();
	//XComboBox* comboBox = new XComboBox();

	MyClass* m = new MyClass(*Application);
	MyClass2* m2 = new MyClass2(*Application);

	//comboBox->SetMinimumHeight(50);
	//comboBox->SetMinimumWidth(200);

	btn->SetMinimumHeight(50);
	btn->SetMinimumWidth(200);
	btn->SetText((LPWSTR)L"Something");

	btn2->SetMinimumHeight(50);
	btn2->SetMinimumWidth(200);
	btn2->SetText((LPWSTR)L"Something2");
	
	Application->AppendApplet<XButton>(btn);
	Application->AppendApplet<XButton>(btn2);
	Application->SetClickedEvent<XButton, MyClass>(*btn, m, &MyClass::clicked);
	Application->SetClickedEvent<XButton, MyClass2>(*btn2, m2, &MyClass2::clicked);
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

	Application->WindowUpdate();
}