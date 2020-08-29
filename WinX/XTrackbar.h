#pragma once
#include "XApplet.h"

class XTrackbar : public XApplet
{
public:
	XTrackbar();

	void setRange(int range) {
		waitingRanges.emplace_back(applet, range);
	}

	//int currentValue() {
	//	return _currentValue;
	//}

	int changedValue() {
		return SendMessageW(applet->windowHWND(), TBM_GETPOS, 0, 0);
	}

	~XTrackbar();

private:
	WNDCLASSW wc = { 0 };
	int _currentValue;
	static std::vector<std::pair<XHANDLE*, int>> waitingRanges;

	static void applyTrackConfiguration() {
		for (int i = 0; i < waitingRanges.size(); i++) {
			SendMessage(waitingRanges.at(i).first->windowHWND(), TBM_SETRANGE, TRUE, MAKELONG(0, waitingRanges.at(i).second));
		}
	}

	

protected:
	friend class XApplication;
	friend class XApplicationProc;
};
