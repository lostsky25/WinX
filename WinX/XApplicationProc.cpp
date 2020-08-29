#include "XApplicationProc.h"

std::pair<HINSTANCE, LPCWSTR>					XApplicationProc::mainCursor;
std::queue<std::pair<XHANDLE*, float>>			XApplicationProc::waitingOpacity;
std::vector<std::tuple<XApplet*, std::function<int(void)>, std::function<void(int)>>> XApplicationProc::bunchSignalSlotInteger;
std::vector<std::tuple<XApplet*, std::function<void(void)>, std::function<void(void)>>> XApplicationProc::bunchSignalSlotNonParams;
//std::vector<std::tuple<XApplet*, std::function<void*(void)>, std::function<void(void*)>>> XApplicationProc::bunchSignalSlotVoidPointer;

HWND XApplicationProc::CurrentHandle;
std::vector<std::pair<XHANDLE*, std::function<void(void)>>> XApplicationProc::XCallback;
std::vector<XApplet*> XApplicationProc::XApplets;