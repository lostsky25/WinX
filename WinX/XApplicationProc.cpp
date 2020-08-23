#include "XApplicationProc.h"

std::pair<HINSTANCE, LPCWSTR>					XApplicationProc::mainCursor;
std::queue<std::pair<XHANDLE*, float>>			XApplicationProc::waitingOpacity;
std::vector<std::pair<XApplet*, std::pair<std::function<int(HWND)>, std::function<void(int)>>>> XApplicationProc::bunchSignalSlot;

HWND XApplicationProc::CurrentHandle;
std::vector<std::pair<XHANDLE*, std::function<void(void)>>> XApplicationProc::XCallback;
std::vector<XApplet*> XApplicationProc::XApplets;