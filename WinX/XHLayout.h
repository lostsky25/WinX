#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "XApplication.h"

#include "XLayout.h"

class XHLayout : protected XLayout
{
public:
	XHLayout();
	~XHLayout();

	int _beginWidth = 0;

	template <class T>
	void addApplet(T* _applet) {
		if (std::is_same<T, XButton>::value) {
			++_count;
			waitingButtonts.push_back(reinterpret_cast<XButton*>(_applet));
			
			/*XLayout::_beginWidth += _applet->_minimumWidth;
			this->_beginWidth = XLayout::_beginWidth;*/
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

