#include "XApplicationProc.h"

HWND XApplicationProc::CurrentHandle;
<<<<<<< Updated upstream
 
template <class U>
std::vector<std::tuple<HWND, U*, void (U::*)()>> XApplicationProc::XMapMessages;
//std::vector<std::reference_wrapper<const std::type_info>> XApplicationProc::XTypesMessages;
std::vector<std::pair<HWND, std::unique_ptr<Base>>> XApplicationProc::XTypes;
=======
std::pair<HINSTANCE, LPCWSTR> XApplicationProc::mainCursor;
//std::vector<std::pair<HWND, LPCWSTR>> XApplicationProc::cursorsForWindows;

template <class U>
std::vector<std::tuple<HWND, U*, void (U::*)()>> XApplicationProc::XMapMessages;
//std::vector<std::reference_wrapper<const std::type_info>> XApplicationProc::XTypesMessages;
std::vector<std::pair<HWND, std::unique_ptr<XEvent>>> XApplicationProc::XTypes;
>>>>>>> Stashed changes

//std::map<std::pair<HWND, int>, std::string> XApplicationProc::XMapMessages;
std::vector<HWND> XApplicationProc::XButtonMessages;
std::vector<HWND> XApplicationProc::XComboBoxMessages;