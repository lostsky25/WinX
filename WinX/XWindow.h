#pragma once
#include "XTypes.h"
#include "xhandle.h"

class XWindow
{
public:
	virtual XHANDLE* windowHandle() = 0;							//Get handle of current window.
	
	/// <summary>
	/// You can use fixed postion for some applet, but you will not have the ability
	/// to put this into a layout. _fixedPosition will be "true" after the first call.
	/// </summary>
	/// <param name="x">X position</param>
	/// <param name="y">Y position</param>
	virtual void setPosition(int, int) = 0;							//Set fixed position.

	virtual void setMinimumHeight(int) = 0;							//Set minimum height (int).
	virtual void setMaximumHeight(int) = 0;							//Set maximum height (int).

	virtual void setMinimumWidth(int) = 0;							//Set minimum width (int).
	virtual void setMaximumWidth(int) = 0;							//Set maximum width (int).

	virtual void setMinimumSize(XSize) = 0;							//Set minimum size (XSize).
	virtual void setMinimumSize(int, int) = 0;						//Set minimum size (int, int).

	virtual void setMaximumSize(XSize) = 0;							//Set maximum size (XSize).
	virtual void setMaximumSize(int, int) = 0;						//Set maximum size (int, int).
	
	virtual int minimumHeight() = 0;								//Get minimum height <-(int).
	virtual int maximumHeight() = 0;								//Get maximum height <-(int).

	virtual int minimumWidth() = 0;									//Get minimum width <-(int).
	virtual int maximumWidth() = 0;									//Get maximum width <-(int).

	virtual XSize minimumSize() = 0;								//Get minimum size <-(XSize).
	virtual XSize maximumSize() = 0;								//Get maximum size <-(XSize).

	virtual void setText(XString) = 0;								//Set text (such as XButton, etc.).
	virtual bool isFullScreen() = 0;								//Get fullscreen state.
	virtual bool isActiveWindow() = 0;								//Get active state.

	/// <summary>
	/// This getter needs for information about (minimum) width of applet.
	/// </summary>
	/// <returns>width of appplet</returns>
	virtual int width() = 0;

	/// <summary>
	/// This getter needs for information about (minimum) height of applet.
	/// </summary>
	/// <returns>height of appplet</returns>
	virtual int height() = 0;

	virtual XMargins margins() = 0;							//Get margins of current window <-(XMargins).
	virtual void setMargins(int, int, int, int) = 0;

protected:
	bool enabled;												//Applet state, clickability.
	bool focus;													//Focus state.
	bool fixedPosition;										//Fixed position state.
	bool fixedSizeState;									//Fixed size state.
	bool fixedHeightState;									//Fixed height state.
	bool fixedWidthState;									//Fixed width state.
	XWindowFlags flags;
	XWindowType type;
	XRect rect;
	//bool isWindow;												//Window or not.
	//bool isFullScreen;										//Applet screen type, if it is equal true, it'll show in full screen.
	//bool isActiveWindow;									//Applet state, active or off.
	XTypes::XPoint pos;							//Postion of something (x, y).
	bool visible;											//Visible state.
};

