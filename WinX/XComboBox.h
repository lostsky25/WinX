#pragma once
#include "XApplet.h"

class XComboBox : public XApplet
{
public:
	XComboBox();
	void addItem(std::wstring);

	int selectedIndex() {
		return _selectedIndex;
	}

	static void applyItems() {
		for (int i = 0; i < waitingItems.size(); i++) {
			SendMessage(waitingItems.at(i).first->windowHWND(), CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(waitingItems.at(i).second.c_str()));
		}
	}

	~XComboBox();

private:
	int _selectedIndex;
	static std::vector<std::pair<XHANDLE*, std::wstring>> waitingItems;

protected:
	friend class XApplicationProc;
};