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

	template <class T>
	void addApplet(T* applet) {

		if (std::is_same<T, XButton>::value) {
			++_count;
			waitingButtonts.push(reinterpret_cast<XButton*>(applet));

			if (firstElement) {
				applet->baseInfo.insert(std::make_pair(applet->currentId, true));
				firstElement = !firstElement;
			}
			else {
				applet->baseInfo.insert(std::make_pair(applet->currentId, false));
			}
		}
		else if (std::is_same<T, XComboBox>::value) {
			++_count;
			waitingComboBox.push(reinterpret_cast<XComboBox*>(applet));
		}
		/*a<T>.push_back(&T::setApplet);
		b<T>.push_back(applet);

		for (int i = 0; i < a.size(); i++) {
			(b<T>[i]->a<T>[i])(XApplication::XApplicationMainWindow,
				XApplication::offsetX,
				XApplication::offsetY);
		}*/
		/*
		applet->setApplet(XApplication::XApplicationMainWindow,
			XApplication::offsetX,
			XApplication::offsetY);*/

			//pushApplet(applet, XApplication::offsetX, XApplication::offsetY);
			//applets<T>.push_back(applet);
			//offsets.push_back(std::make_pair(XApplication::offsetX, XApplication::offsetY));
	}

	//template <class T>
	//void pp(void (*function)()) {
	//	a.emplace_back<T>(function);
	//}
	// Inherited from XLayout
	virtual void deleteApplet(int) override;
	virtual void destroyedLayout() override;
	virtual void activate() override;
	virtual void addSpacing(int) override;
	virtual int count() override;
	
	//template <class U>
	//static std::vector<std::unique_ptr<U>> applets;
private:
	bool firstElement = true;
	//template <class T>
	//static std::vector<T*> applets;

	//std::vector<std::pair<int, int>> offsets;

	/*template <typename T>
	void pushApplet(T* applet, int offsetX, int offsetY) {
		applets.emplace_back(std::make_tuple(applet, offsetX, offsetY));
	}*/

protected:
	friend class XApplication;
};

