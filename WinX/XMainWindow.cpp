#include "XMainWindow.h"
#define XDebug

//Temp
#include "XThread.h"

void foo2() {
	OutputDebugStringA("Clicked2\r\n");
}

class ExplorerDialog : public XApplet
{
public:
	ExplorerDialog(XApplication& parent);
	~ExplorerDialog() = default;

	//static LRESULT CALLBACK OwnerDrawButtonProc(HWND hWnd, UINT uMsg, WPARAM wParam,
	//	LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
	//{
	//	switch (uMsg)
	//	{
	//	case WM_GETMINMAXINFO:
	//	{
	//		GetWindowRect(XApplication::);
	//		LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
	//			lpMMI->ptMinTrackSize.x = 200;
	//			lpMMI->ptMinTrackSize.y = 20;

	//			lpMMI->ptMaxTrackSize.x = 500;
	//			lpMMI->ptMaxTrackSize.y = 500;
	//	}
	//	case WM_MOUSEMOVE:
	//		//SetCursor(LoadCursor(NULL, IDC_HAND));
	//		break;

	//	case WM_LBUTTONDOWN:
	//		//MessageBoxA(hWnd, "Button down!", 0, 0);
	//		OutputDebugStringA("adsad");
	//		break;

	//	case WM_NCDESTROY:
	//		RemoveWindowSubclass(hWnd, &OwnerDrawButtonProc, uIdSubclass);
	//		break;
	//	}

	//	return DefSubclassProc(hWnd, uMsg, wParam, lParam);
	//}
};

class MyClass2 : public XApplet, public XThread
{
public:
	MyClass2(XApplication& parent);
	~MyClass2() = default;

	friend class XApplicationProc;
	friend class XApplication;


	// Унаследовано через XThread
	static DWORD __stdcall run(LPVOID)
	{
		while (1) {
			OutputDebugStringA("XThread\n");
			Sleep(100);
		}
		return 0;
	}
};

class MyClass3 : public XApplet
{
public:
	MyClass3(XApplication* parent) { Application = parent; }
	~MyClass3() = default;

	void create_btn() {

		track = new XTrackbar();
		track2 = new XTrackbar();
		box1 = new XComboBox();
		btn = new XButton();
		label = new XLabel();

		track->setMinimumSize(150, 40);
		track2->setMinimumSize(150, 40);

		label->setMinimumSize(100, 20);
		label->setWindowName(L"Some text:");

		btn->setMinimumSize(200, 40);
		btn->setWindowName(L"Get index");

		box1->setMinimumSize(100, 50);
		box1->addItem(L"qwerty1");
		box1->addItem(L"qwerty2");
		box1->addItem(L"qwerty3");

		XVLayout* lv = new XVLayout();
		lv->addApplet<XButton>(btn);
		lv->addApplet<XTrackbar>(track);
		lv->addApplet<XTrackbar>(track2);
		lv->addApplet<XComboBox>(box1);
		lv->addApplet<XLabel>(label);

		//Application->connect<XButton, MyClass3>(btn, XButton::clicked, this, &MyClass3::smth_for_click);

		Application->connect<XTrackbar, MyClass3>(SIGNAL(track, &XTrackbar::changedValue), SLOT(this, &MyClass3::slot_smth));
		Application->connect<XTrackbar, MyClass3>(SIGNAL(track2, &XTrackbar::changedValue), SLOT(this, &MyClass3::slot_smth2));
		Application->setLayout(lv);
	}

	void slot_smth(int val) {
		wchar_t buf[16];
		wsprintf(buf, L"slider: %d\n", val);
		XString bb = buf;
		label->setWindowName(bb);
	}

	void slot_smth2(int val) {
		char buf[16];
		sprintf(buf, "slider2: %d\n", val);
		OutputDebugStringA(buf);
	}

	void smth_for_click() {
		char buf[16];
		sprintf(buf, "index: %d\n", box1->selectedIndex());
		OutputDebugStringA(buf);
	}

private:
	XApplication* Application;
	XLabel* label;
	XComboBox* box1;
	XTrackbar* track;
	XTrackbar* track2;
	XButton* btn;
};

ExplorerDialog::ExplorerDialog(XApplication& parent)// : parent(parent)
{

}

MyClass2::MyClass2(XApplication& parent)// : parent(parent)
{

}


XMainWindow::XMainWindow(XParams xParams) {
	Application = new XApplication(xParams);
	//Application->setOpacity(0.9);
	Application->setMaximumSize(2000, 2000);
	Application->setMinimumSize(1600, 900);

	ExplorerDialog* explorerDialog = new ExplorerDialog(*Application);
	MyClass2* m = new MyClass2(*Application);
	MyClass3* m2 = new MyClass3(Application);
	m2->create_btn();

	XButton* btn = new XButton();

	XLabel* lb1 = new XLabel();
	XComboBox* box1 = new XComboBox();
	XTextBox* textBox = new XTextBox();

	textBox->setMinimumSize(200, 20);
	textBox->setWindowName(L"Some text");
	textBox->setBorder();

	lb1->setMinimumSize(50, 20);
	lb1->setWindowName(L"Some text:");

	box1->setMinimumSize(100, 50);
	box1->addItem(L"qwerty1");
	box1->addItem(L"qwerty2");
	box1->addItem(L"qwerty3");
	
	//box1->setWindowName(L"Box");

	btn->setMinimumSize(200, 40);
	btn->setWindowName(L"Open explorer");
	
    //btn->setWindowOpacity(0.9);
	//btn->disp->setSubClass(btn->windowHandle(), ExplorerDialog::OwnerDrawButtonProc);

	Application->setPosition(10,10);


	XVLayout* lv = new XVLayout();
	//lv->addApplet<XTextBox>(textBox);
	//lv->addApplet<XButton>(btn);
	//lv->addApplet<XLabel>(lb1);
	lv->addApplet<XComboBox>(box1);

	//Application->appendApplet(btn);
	//btn->setOpacity(0.9);

	Application->setCursor(CURSOR_CROSSHAIR);


	Application->setLayout(lv);

	Application->windowUpdate();
}