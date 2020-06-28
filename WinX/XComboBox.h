#pragma once

#include "XApplet.h"
#include <vector>

<<<<<<< Updated upstream
class XComboBox : XApplet
=======
class XComboBox //: XApplet
>>>>>>> Stashed changes
{
public:
	XComboBox();

	void AppendItem(LPWSTR);
	//int SelectedIndex();
	
	// Унаследовано через XApplet
<<<<<<< Updated upstream
	virtual void SetMinimumWidth(int) override;
	virtual void SetMinimumHeight(int) override;
	virtual int GetWidth() override;
	virtual int GetHeight() override;
=======
	//virtual void SetMinimumWidth(int) override;
	//virtual void SetMinimumHeight(int) override;
	//virtual int GetWidth() override;
	//virtual int GetHeight() override;
>>>>>>> Stashed changes
	// !Унаследовано через XApplet

private:
	std::vector<LPWSTR> messages;

protected:
	friend class XApplication;
	// Унаследовано через XApplet
<<<<<<< Updated upstream
	virtual void SetApplet(HWND, int, int) override;
=======
	//virtual void SetApplet(HWND, int, int) override;
>>>>>>> Stashed changes
	// !Унаследовано через XApplet

};