#pragma once

#ifdef XDebug
	#include <iostream>
	#include <Windows.h>
	__forceinline void OutLine(LPCSTR dBuff) {
		//sprintf(dBuff + strlen(dBuff), " Function: %20s Line: %20d", __FUNCTION__, __LINE__);
		OutputDebugStringA(dBuff);
	}
#else
	#include <Windows.h>
	__forceinline void OutLine(LPCSTR dBuff) {
		return;
	}
#endif