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
	int _count;

	template <class T>
	void addApplet(T* object) {
		//if (std::is_same<T, XButton>::value) {
			++_count;
			//waitingButtonts.emplace_back(object);

			XWaiting.emplace_back(reinterpret_cast<XApplet*>(object));
			XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		//}
		//else if (std::is_same<T, XLabel>::value) {
		//	++_count;
		//	//waitingLabels.emplace_back(reinterpret_cast<XLabel*>(object));

		//	XWaiting.emplace_back(reinterpret_cast<XApplet*>(object));
		//	XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		//}
		//else if (std::is_same<T, XComboBox>::value) {
		//	++_count;
		//	//waitingComboBox.emplace_back(reinterpret_cast<XComboBox*>(object));

		//	XWaiting.emplace_back(reinterpret_cast<XApplet*>(object));
		//	XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		//}
		//else if (std::is_same<T, XTextBox>::value) {
		//	++_count;
		//	//waitingComboBox.emplace_back(reinterpret_cast<XComboBox*>(object));

		//	XWaiting.emplace_back(reinterpret_cast<XApplet*>(object));
		//	XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		//}
	}

	// Inherited from XLayout
	virtual void deleteApplet(int) override;
	virtual void destroyedLayout() override;
	virtual void activate() override;
	virtual void addSpacing(int) override;

protected:
	friend class XApplication;
};

