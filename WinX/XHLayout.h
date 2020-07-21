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
	~XHLayout() = default;

	int beginWidth = 0;

	template <class T>
	void addApplet(T* object) {
		if (std::is_same<T, XButton>::value) {
			++_count;
			waitingButtonts.emplace_back(object);
			
			XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		}
		else if (std::is_same<T, XComboBox>::value) {
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

