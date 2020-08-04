#include "XApplicationProc.h"

HWND XApplicationProc::CurrentHandle;

//template <class U>
//std::vector<std::tuple<XHANDLE*, U*, void (U::*)()>> XApplicationProc::XMapMessages;
std::pair<HINSTANCE, LPCWSTR> XApplicationProc::mainCursor;
std::queue<std::pair<XHANDLE*, float>> XApplicationProc::waitingOpacity;
std::vector<std::pair<XHANDLE*, std::unique_ptr<XApplet>>> XApplicationProc::XTypes;
std::vector<XApplet*> XApplicationProc::XMessages;
/*
std::vector<XHANDLE*> XApplicationProc::XButtonMessages;
std::vector<XHANDLE*> XApplicationProc::XLabelMessages;
std::vector<XHANDLE*> XApplicationProc::XComboBoxMessages;*/