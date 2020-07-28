#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <type_traits>
#include "XApplication.h"

#include "XLayout.h"
#include "XLabel.h"
#include "XTypes.h"


class XVLayout : protected XLayout
{
public:
	XVLayout();
	~XVLayout() = default;

	int _count;

	template <class T>
	void addApplet(T* object) {
		if (std::is_same<T, XButton>::value) {
			++_count;
			waitingButtonts.emplace_back(reinterpret_cast<XButton*>(object));

			XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		}
		else if (std::is_same<T, XLabel>::value) {
			++_count;
			waitingLabels.emplace_back(reinterpret_cast<XLabel*>(object));

			XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		}
		else if (std::is_same<T, XComboBox>::value) {
			++_count;
			waitingComboBox.emplace_back(reinterpret_cast<XComboBox*>(object));

			XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		}
	}

	// Inherited from XLayout
	virtual void deleteApplet(int) override;
	virtual void destroyedLayout() override;
	virtual void activate() override;
	virtual void addSpacing(int) override;
	//virtual int count() override;
	
private:
	std::vector<XButton*> waitingButtonts;
	std::vector<XLabel*> waitingLabels;
	std::vector<XComboBox*> waitingComboBox;

protected:
	friend class XApplication;
};

