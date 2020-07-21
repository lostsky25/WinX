#include "XApplicationProc.h"

HWND XApplicationProc::CurrentHandle;

template <class U>
std::vector<std::tuple<XHANDLE*, U*, void (U::*)()>> XApplicationProc::XMapMessages;
std::pair<HINSTANCE, LPCWSTR> XApplicationProc::mainCursor;
std::vector<std::pair<XHANDLE*, std::unique_ptr<XObject>>> XApplicationProc::XTypes;
std::vector<XHANDLE*> XApplicationProc::XButtonMessages;
std::vector<XHANDLE*> XApplicationProc::XComboBoxMessages;