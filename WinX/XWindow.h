#pragma once

#include <Windows.h>
#include <commctrl.h>
#include <atlbase.h>
#include <stdexcept>

#include "Dispether.h"
#include "XString.h"
#include "XLayout.h"
#include "xhandle.h"
#include "XTypes.h"

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
	virtual void setPosition(int x, int y) = 0;

	/// <summary>
	/// The minimum height is a initial size of some applet.
	/// </summary>
	/// <param name="height">Height in pixels</param>
	virtual void setMinimumHeight(int height) = 0;

	/// <summary>
	/// The maximum height is a size which the height can increase.
	/// </summary>
	/// <param name="height">Height in pixels</param>
	virtual void setMaximumHeight(int height) = 0;

	/// <summary>
	/// The minimum width is a initial size of some applet.
	/// </summary>
	/// <param name="height">Width in pixels</param>
	virtual void setMinimumWidth(int width) = 0;
	
	/// <summary>
	/// The maximum width is a size which the height can increase.
	/// </summary>
	/// <param name="height">Width in pixels</param>
	virtual void setMaximumWidth(int width) = 0;

	/// <summary>
	/// The minimum is a initial size of some applet. This data type contains widht and height.
	/// </summary>
	/// <param name="size">Data type of size (width, height)</param>
	virtual void setMinimumSize(XSize size) = 0;

	/// <summary>
	/// The minimum is a initial size of some applet.
	/// </summary>
	/// <param name="width">Width in pixels</param>
	/// <param name="height">Height in pixels</param>
	virtual void setMinimumSize(int width, int height) = 0;

	/// <summary>
	/// The maximum is the size which it can expand.
	/// </summary>
	/// <param name="size">Data type of size (width, height)</param>
	virtual void setMaximumSize(XSize size) = 0;

	/// <summary>
	/// The maximum is the size which it can expand.
	/// </summary>
	/// <param name="width">Width in pixels</param>
	/// <param name="height">Height in pixels</param>
	virtual void setMaximumSize(int, int) = 0;

	virtual int minimumHeight() = 0;								//Get minimum height <-(int).
	virtual int maximumHeight() = 0;								//Get maximum height <-(int).

	virtual int minimumWidth() = 0;									//Get minimum width <-(int).
	virtual int maximumWidth() = 0;									//Get maximum width <-(int).

	virtual XSize minimumSize() = 0;								//Get minimum size <-(XSize).
	virtual XSize maximumSize() = 0;								//Get maximum size <-(XSize).

	virtual void setWindowName(XString) = 0;								//Set text (such as XButton, etc.).
	virtual bool isFullScreen() = 0;								//Get fullscreen state.
	virtual bool isActiveWindow() = 0;								//Get active state.

	virtual void setOpacity(float) = 0;

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

	virtual bool windowHasMaximumSize() = 0;

	virtual XMargins margins() = 0;							//Get margins of current window <-(XMargins).
	virtual void setMargins(int, int, int, int) = 0;

protected:
	bool enabled;											//Applet state, clickability.
	bool focus;												//Focus state.
	bool fixedPosition;										//Fixed position state.
	bool fixedSizeState;									//Fixed size state.
	bool fixedHeightState;									//Fixed height state.
	bool fixedWidthState;									//Fixed width state.
	bool _isFullScreen;
	bool _isActiveWindow;
	bool _windowHasMaximumSize;
	XWindowFlags flags;
	XWindowType type;
	XString className;
	XString windowName;
	XRect rect;
	XTypes::XPoint pos;										//Postion of something (x, y).
	bool visible;											//Visible state.

};

