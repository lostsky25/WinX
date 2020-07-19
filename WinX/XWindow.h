#pragma once
#include "XTypes.h"
#include "xhandle.h"

class XWindow
{
public:
	//XWindow();

	virtual XHANDLE* windowHandle() = 0;							//Get handle of current window.
	virtual void windowUpdate() = 0;								//Update current window. It's just call updateWindow() from Windows.h.
	virtual void updateSize() = 0;									//Update geometry of current window.
	
	/// <summary>
	/// You can use fixed postion for some applet, but you will not have the ability
	/// to put this into a layout. _fixedPosition will be "true" after the first call.
	/// </summary>
	/// <param name="x">X position</param>
	/// <param name="y">Y position</param>
	virtual void setPosition(int, int) = 0;							//Set fixed position.
	virtual void setMinimumWidth(int) = 0;							//Set minimum width (int).
	virtual void setMinimumHeight(int) = 0;							//Set minimum height (int).
	virtual void setMaximumHeight(int) = 0;							//Set maximum height (int).
	virtual void setMaximumSize(XSize) = 0;							//Set maximum size (XSize).
	virtual void setMaximumSize(int, int) = 0;						//Set maximum size (int, int).
	virtual void setMaximumWidth(int) = 0;							//Set maximum width (int).
	virtual void setMinimumSize(int, int) = 0;						//Set minimum size (int, int).
	virtual void setMinimumSize(XSize) = 0;							//Set minimum size (XSize).
	virtual int maximumHeight() = 0;								//Get maximum height <-(int).
	virtual XSize maximumSize() = 0;								//Get maximum size <-(XSize).
	virtual int maximumWidth() = 0;									//Get maximum width <-(int).
	virtual int minimumHeight() = 0;								//Get minimum height <-(int).
	virtual XSize minimumSize() = 0;								//Get minimum size <-(XSize).
	virtual int minimumWidth() = 0;									//Get minimum width <-(int).
	virtual XTypes::XRect frameGeomtry() = 0;						//Get frame geometry <-(XRect).
	virtual void setText(XString) = 0;								//Set text (such as XButton, etc.).
	virtual bool isFullScreen() = 0;								//Get fullscreen state.
	virtual bool isActiveWindow() = 0;								//Get active state.
	virtual bool isWindow() = 0;									//Is it window? <-(bool)
	virtual int width() = 0;										//Get width <-(int). It's minimum width.
	virtual int height() = 0;										//Get height <-(int). It's minimum height.
	virtual XTypes::XMargins margins() = 0;							//Get margins of current window <-(XMargins).
	virtual void setWindowOpacity(float) = 0;
	virtual float windowOpacity() = 0;
	virtual void setMargins(int, int, int, int) = 0;

protected:
	bool _enabled = 0;												//Applet state, clickability.
	bool _focus = 0;												//Focus state.
	bool _fixedPosition = false;									//Fixed position state.
	bool _fixedSizeState = false;									//Fixed size state.
	bool _fixedHeightState = false;									//Fixed height state.
	bool _fixedWidthState = false;									//Fixed width state.
	XWindowFlags _flags = XWindowFlags();
	XWindowType _type = XWindowType(0);
	XTypes::XFocusPolicy _focusPolicy = XTypes::XFocusPolicy();		//
	XTypes::XWindowState _windowState = XTypes::XWindowState();		//Window state.
	bool _isWindow = 0;												//Window or not.
	XTypes::XRect _frameGeometry = XTypes::XRect();					//Applet geometry.
	XSize _frameSize = XSize();										//Applet frame size.
	bool _fullScreen = false;										//Applet screen type, if it is equal true, it'll show in full screen.
	XTypes::XRect _geometry = XTypes::XRect();						//Applet geometry (x, y, right, bottom).
	bool _isActiveWindow = false;									//Applet state, active or off.
	bool _maximized = false;										//Maximized state.

	XTypes::XPalette _palette = XTypes::XPalette();					//...
	XTypes::XPoint _pos = XTypes::XPoint();							//Window postion (x, y).
	XSize _sizeIncrement = XSize();									//When you want to change window size.
	bool _visible = false;											//Visible state.
	XTypes::XIcon _windowIcon = XTypes::XIcon();					//Window icon.
	double _windowOpacity = 0.0f;									//Window opacity.
	XString _windowTitle = L"";										//Window title.
	
	int _width = 0;													//Applet width.
	int _height = 0;												//Applet height.
	int _x = 0;														//X coordinate.
	int _y = 0;														//Y coordinate.
};

