#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <type_traits>
#include "XApplication.h"

#include "XLayout.h"


class XVLayout : protected XLayout
{
public:
	XVLayout();
	~XVLayout();

	static int _beginHeight;

	template <class T>
	void addApplet(T* _applet) {

		if (std::is_same<T, XButton>::value) {
			++_count;
			waitingButtonts.push_back(reinterpret_cast<XButton*>(_applet));

			//XLayout::_beginHeight += _applet->_minimumHeight;
			//this->_beginHeight = XLayout::_beginHeight;
		}
		else if (std::is_same<T, XComboBox>::value) {
			//
		}
	}

	// Inherited from XLayout
	virtual void deleteApplet(int) override;
	virtual void destroyedLayout() override;
	virtual void activate() override;
	virtual void addSpacing(int) override;
	virtual int count() override;
	
private:
	std::vector<XButton*> waitingButtonts;
	std::vector<XComboBox*> waitingComboBox;

protected:
	friend class XApplication;
};

