#pragma once
#include "XTypes.h"

class XWindow
{
public:

	virtual HWND windowHandle() = 0;					//Get handle of current window.
	virtual void windowUpdate() = 0;					//Update current window. It's just call updateWindow() from Windows.h.
	virtual void updateSize();							//Update geometry of current window.
	virtual void setMinimumWidth(int) = 0;				//Set minimum width (int).
	virtual void setMinimumHeight(int) = 0;				//Set minimum height (int).
	virtual void setMaximumHeight(int) = 0;				//Set maximum height (int).
	virtual void setMaximumSize(XTypes::XSize) = 0;		//Set maximum size (XSize).
	virtual void setMaximumSize(int, int) = 0;			//Set maximum size (int, int).
	virtual void setMaximumWidth(int) = 0;				//Set maximum width (int).
	virtual void setMinimumSize(int, int) = 0;			//Set minimum size (int, int).
	virtual void setMinimumSize(XTypes::XSize) = 0;		//Set minimum size (XSize).
	virtual int maximumHeight() = 0;					//Get maximum height <-(int).
	virtual XTypes::XSize maximumSize() = 0;			//Get maximum size <-(XSize).
	virtual int maximumWidth() = 0;						//Get maximum width <-(int).
	virtual int minimumHeight() = 0;					//Get minimum height <-(int).
	virtual XTypes::XSize minimumSize() = 0;			//Get minimum size <-(XSize).
	virtual int minimumWidth() = 0;						//Get minimum width <-(int).
	virtual XTypes::XRect frameGeomtry() = 0;			//Get frame geometry <-(XRect).
	virtual void setText(LPCSTR) = 0;					//Set text (such as XButton, etc.).
	virtual bool isFullScreen() = 0;					//Get fullscreen state.
	virtual bool isActiveWindow() = 0;					//Get active state.
	virtual bool isWindow() = 0;						//Is it window? <-(bool)
	virtual int width() = 0;							//Get width <-(int). It's minimum width.
	virtual int height() = 0;							//Get height <-(int). It's minimum height.
	virtual XTypes::XMargins margins() = 0;				//Get margins of current window <-(XMargins).

protected:

	bool _enabled;										//Applet state, clickability.
	bool _focus;										//Focus state.
	XTypes::XFocusPolicy _focusPolicy;					//
	XTypes::XWindowState _windowState;					//Window state.
	XTypes::XSize _baseSize;							//Initial applet size.
	bool _isWindow;										//Window or not.
	XTypes::XRect _frameGeometry;						//Applet geometry.
	XTypes::XSize _frameSize;							//Applet frame size.
	bool _fullScreen;									//Applet screen type, if it is equal true, it'll show in full screen.
	XTypes::XRect _geometry;							//Applet geometry (x, y, right, bottom).
	bool _isActiveWindow;								//Applet state, active or off.
	bool _maximized;									//Maximized state.

	XTypes::XPalette _palette;							//...
	XTypes::XPoint _pos;								//Window postion (x, y).
	XTypes::XSize _sizeIncrement;						//When you want to change window size.
	bool _visible;										//Visible state.
	XTypes::XIcon _windowIcon;							//Window icon.
	double _windowOpacity;								//Window opacity.
	//XString _windowTitle;								//Window title.
	XTypes::XRect _rect;								//Window rectangle (x, y, right, bottom).
	XTypes::XMargins _margins;							//Window margins (left, top, right, bottom).

	int _maximumHeight;									//Maximum window height.
	int _maximumWidth;									//Maximum window width.
	int _minimumHeight;									//Minimum window height.
	int _minimumWidth;									//Minimum window width.
	int _width;											//Applet width.
	int _height;										//Applet height.
	int _x;												//X coordinate.
	int _y;												//Y coordinate.
};

