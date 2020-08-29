#include "XMainWindow.h"
#define XDebug

//#include "XThread.h"

class WindowsMetrics : public XApplet
{
public:
	WindowsMetrics(XApplication* parent) {
		Application = parent;

		trackCaptionHeight = new XTrackbar();
		trackCaptionWidth = new XTrackbar();
		lbCaptionHeight = new XLabel();
		lbCaptionWidth = new XLabel();
		verticalLayout = new XVLayout();

		this->Application = Application;

		paramCaptionHeight = L"CaptionHeight";
		paramCaptionWidth = L"CaptionWidth";

		lResult = RegOpenKeyEx(HKEY_CURRENT_USER, L"Control Panel\\Desktop\\WindowMetrics", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);

		if (lResult != ERROR_SUCCESS) {
			RegCloseKey(hKey);
		}

		trackCaptionHeight->setMinimumSize(200, 20);
		trackCaptionHeight->setRange(500);

		lbCaptionHeight->setWindowName(L"Height: 0");
		lbCaptionHeight->setMinimumSize(200, 20);

		lbCaptionWidth->setWindowName(L"Width: 0");
		lbCaptionWidth->setMinimumSize(200, 20);

		trackCaptionWidth->setMinimumSize(200, 20);
		trackCaptionWidth->setRange(500);

		verticalLayout->addApplet<XLabel>(lbCaptionHeight);
		verticalLayout->addApplet<XTrackbar>(trackCaptionHeight);
		verticalLayout->addApplet<XLabel>(lbCaptionWidth);
		verticalLayout->addApplet<XTrackbar>(trackCaptionWidth);

		Application->setLayout(verticalLayout);
	}

	void setWindowCaptionHeight() {
		RegSetValueExW(
			hKey,
			paramCaptionHeight,
			0,
			REG_SZ,
			(BYTE*)this->captionHeight.c_str(),
			this->captionHeight.length() * sizeof(TCHAR)
		);
	}

	void setWindowCaptionWidth() {
		RegSetValueExW(
			hKey,
			paramCaptionWidth,
			0,
			REG_SZ,
			(BYTE*)this->captionWidth.c_str(),
			this->captionWidth.length() * sizeof(TCHAR)
		);
	}

	void changeLabelCaptionHeight(int captionHeight) {
		this->captionHeight = std::to_wstring(-captionHeight);
		lbCaptionHeight->setWindowName(L"Height: " + this->captionHeight);
	}

	void changeLabelCaptionWidth(int captionWidth) {
		this->captionWidth = std::to_wstring(-captionWidth);
		lbCaptionWidth->setWindowName(L"Width: " + this->captionWidth);
	}

	~WindowsMetrics();

private:
	XTrackbar* trackCaptionHeight;
	XTrackbar* trackCaptionWidth;
	HKEY hKey;
	std::wstring captionHeight;
	std::wstring captionWidth;
	LPCWSTR paramCaptionHeight;
	LPCWSTR paramCaptionWidth;
	XLabel* lbCaptionHeight;
	XLabel* lbCaptionWidth;
	XVLayout* verticalLayout;
	XApplication* Application;
	LONG lResult;

protected:
	friend class XApplication;
	friend class XApplicationProc;
	friend class XMainWindow;
};

WindowsMetrics::~WindowsMetrics()
{
	RegCloseKey(hKey);
}


XMainWindow::XMainWindow(XParams xParams) {
	Application = new XApplication(xParams);
	Application->setMaximumSize(215, 135);
	Application->setMinimumSize(215, 135);

	XButton* setRegValues = new XButton();
	XVLayout* verticalLayout = new XVLayout();
	XHLayout* horizontalLayout = new XHLayout();
	WindowsMetrics* winMetrics = new WindowsMetrics(Application);

	setRegValues->setMinimumSize(50, 20);
	setRegValues->setWindowName(L"Set");

	Application->connect(SIGNAL(setRegValues, &XButton::clicked), SLOT(winMetrics, &WindowsMetrics::setWindowCaptionHeight));
	Application->connect(SIGNAL(setRegValues, &XButton::clicked), SLOT(winMetrics, &WindowsMetrics::setWindowCaptionWidth));

	Application->connect<int>(SIGNAL(winMetrics->trackCaptionWidth, &XTrackbar::changedValue), SLOT_P(winMetrics, &WindowsMetrics::changeLabelCaptionWidth));
	Application->connect<int>(SIGNAL(winMetrics->trackCaptionHeight, &XTrackbar::changedValue), SLOT_P(winMetrics, &WindowsMetrics::changeLabelCaptionHeight));

	horizontalLayout->addApplet<XButton>(setRegValues);

	Application->setCursor(CURSOR_CROSSHAIR);
	Application->setLayout(verticalLayout);
	Application->setLayout(horizontalLayout);

	Application->windowUpdate();
}