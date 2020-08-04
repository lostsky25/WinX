#include "Dispether.h"

std::queue<std::pair<XHANDLE*, LRESULT(*)(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR)>> Dispether::waitingSubclasses;
unsigned Dispether::subProcId;

Dispether::Dispether()
{
}

Dispether::~Dispether()
{
}
