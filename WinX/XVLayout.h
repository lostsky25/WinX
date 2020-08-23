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
		++_count;
		XWaiting.emplace_back(reinterpret_cast<XApplet*>(object));

		XApplicationProc::XApplets.emplace_back(reinterpret_cast<XApplet*>(object));

		object->disp->setSubClass(object->applet, standartProc);
		XLayout::properties.push_back(std::make_pair(object->applet->windowRect(), object->applet->windowMargins()));
		applets.emplace_back(object, LayoutDirection::Vertical);
	}

	// Inherited from XLayout
	virtual void deleteApplet(int) override;
	virtual void destroyedLayout() override;
	virtual void activate() override;
	virtual void addSpacing(int) override;
protected:
	friend class XApplication;
};

