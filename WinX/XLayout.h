#pragma once
#include <map>
#include <queue>

#include "XApplet.h"
#include "XTypes.h"

class XButton;
class XComboBox;

enum class LayoutDirection {
	Vertical = 0,
	Horizontal = 1,
	None = 2,
};

class XLayout
{
public:
	static std::vector<std::pair<XRect, XMargins>> properties;					//Window margins (left, top, right, bottom).	

protected:
	friend class XApplication;
	friend class XButton;
	friend class XLabel;

	static int beginHeight;
	static int beginWidth;
	static int beginHeightMargins;
	static int beginWidthMargins;

	static int betweenVeticalApplets;
	static int betweenHorizontalApplets;
	static int appletId;

	int count = 0;
	static int layoutId;

	int id = 0;

	static std::vector<int> beginVerticalLayout;
	static std::vector<int> beginHorizontalLayout;
	static std::vector<int> maxHorizontalElement;
	static std::vector<int> maxVerticalElement;

	LayoutDirection dir = LayoutDirection(0);													//Current direction.
	virtual void deleteApplet(int) = 0;															//Delete some applet by id.
	virtual void destroyedLayout() = 0;															//Clear layout and freeing up memory.
	virtual void activate() = 0;																//By default -> true;
	virtual void addSpacing(int) = 0;															//Set spacing between applets.
	
	//virtual int count() = 0;																	//Get count of applets in the layout.
};
