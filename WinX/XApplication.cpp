#include "XApplication.h"
#include "XApplicationProc.h"

LRESULT CALLBACK XApplicationProc::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	int index = 0;
	char buff[128];
	int idx_row;

	NMHDR* h = reinterpret_cast<NMHDR*>(lParam);
	//Base* b = types[0]();
	
	switch (uMsg) {
	case WM_NOTIFY:
		
		break;
	
	case WM_COMMAND:
		for (int i = 0; i < XApplicationProc::XComboBoxMessages.size(); i++) {
			switch (HIWORD(wParam))
			{
			case CBN_SELCHANGE:
				if(XApplicationProc::XComboBoxMessages.at(i) != NULL){
					index = SendMessage(XApplicationProc::XComboBoxMessages.at(i), CB_GETCURSEL, 0, 0);
				}
				break;
			default:
				break;
			}
			break;
		}

		//event click
		switch (LOWORD(wParam))
		{
		case BN_CLICKED:
			for (int i = 0; i < XTypes.size(); i++) {
				if (CurrentHandle == XTypes.at(i).first) {
					XTypes.at(i).second->clicked();
				}
			}
			//b->clicked();
			//for (int type_id = 0; type_id < XTypesMessages.size(); type_id++) {
				//typedef std::remove_reference<decltype(XApplicationProc::XTypesMessages[type_id])>::type XType;
					//for (auto& elem : XMapMessages<XType>) {
						//if (CurrentHandle == elem._Myfirst._Val) {
						//	OutputDebugStringA("OOOAFKDSMFL");
					//	}
				//}
			//}
			//std::unique_ptr<Base> temp = qwe[0]();



			//if (CurrentHandle == XMapMessages<MyClass>.operator[]<0>(0)) {
			//	//void (*pProc)() = XMapMessages.at(i).second;
			//	//if ((*pProc) != nullptr)
			//		//(*pProc)();
			//}
			break;
		default:
			break;
		}

		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		DrawText(hDC, L"Hello, World!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

XApplication::XApplication() {

}

XApplication::XApplication(XParams xParams) {
	// Ensure that the common control DLL is loaded. 
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
	icex.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icex);

	offsetX = 0;
	offsetY = 0;

	WndClassEx.cbSize = sizeof(WndClassEx);
	WndClassEx.lpfnWndProc = ::XApplicationProc::WndProc;
	WndClassEx.style = CS_HREDRAW | CS_VREDRAW; //---> ��������������� ����������� ����� (bit flags), ��� ��� ������ ���� ������ ���������� � ��������� ��������.
	
	/*
		CS_GLOBALCLASS - ������� �����, ��������� ���� �����������. ������ ���� ����� ����������� ��� �������� ������������ ������������� ��������� ���������� � DLL.
		CS_HREDRAW - �������������� ��� ����, ���� ������� ������ �� �����������.
		CS_NOCLOSE - ��������� ������� Close � ��������� ����.
		CS_OWNDC - �������� ���������� �������� ���������� ��� ������� ����, ���������� ��� ������ ����� ������.
		CS_VREDRAW - �������������� ��� ����, ���� ������� ������ �� ���������.
	*/

	WndClassEx.cbClsExtra = 0;
	WndClassEx.cbWndExtra = 0;
	WndClassEx.hInstance = xParams.hInstance;
	WndClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClassEx.lpszMenuName = NULL;
	WndClassEx.lpszClassName = szClassName;
	WndClassEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	//!��������� ��������� ����

	if (!RegisterClassEx(&WndClassEx)) {
		//return EXIT_FAILURE;
	}

	XApplicationMainWindow = CreateWindow(szClassName, L"Window title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, (HWND)NULL, (HMENU)NULL, (HINSTANCE)xParams.hInstance, NULL);


	/*
		CS_ - ����� ����� ������
		CW_ - ����� �������� ����
		DT_ - ����� ��������� ������
		IDC_ - ������������� ����������������� �������
		IDI_ - �������������� ���������������� ������ (�����������)
		WM_ - ��������� ����
		WS_ - ����� ����
	*/

	if (!XApplicationMainWindow) {
		//return EXIT_FAILURE;
	}

	ShowWindow(XApplicationMainWindow, xParams.nCmdShow);

	//auto lambdaWindowUpdate = [=] { WindowUpdate(); };
	//std::thread XApplicationWindowUpdate(lambdaWindowUpdate);
	//
	//std::thread t2(&XApplication::WindowUpdate, this);
	//t2.join();

	//return XApplicationMessage.wParam;
}

//template <class T>
//void XApplication::AppendApplet(T btn)
//{	
//	btn.appendApplet(XApplicationMainWindow);
//}

HWND XApplication::GetMainWindowHandle() {
	return XApplicationMainWindow;
}

void XApplication::WindowUpdate(void) {
	while (GetMessage(&XApplicationMessage, NULL, 0, 0)) {
		XApplicationProc::CurrentHandle = XApplicationMessage.hwnd;
		TranslateMessage(&XApplicationMessage);
		DispatchMessage(&XApplicationMessage);
	}
}

XApplication::~XApplication(){
	delete XApplicationMainWindow;
	delete szClassName;
}

