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
		++_count;
		XWaiting.emplace_back(reinterpret_cast<XApplet*>(object));
		object->disp->setSubClass(object->applet, standartProc);
		XLayout::properties.push_back(std::make_pair(object->applet->window->rect, object->applet->window->margins));
		applets.emplace_back(object);
	}

	// Inherited from XLayout
	virtual void deleteApplet(int) override;
	virtual void destroyedLayout() override;
	virtual void activate() override;
	virtual void addSpacing(int) override;

protected:
	friend class XApplication;
};

