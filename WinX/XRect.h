#pragma once
class XRect
{
public:
	XRect() = default;
	XRect(int, int, int, int);
	~XRect() = default;

	void setRect(int, int, int, int);
	XRect rect();

	int x();
	int y();
	int right();
	int bottom();

	void setX(int);
	void setY(int);
	void setRight(int);
	void setBottom(int);

private:
	int _x;
	int _y;
	int _right;
	int _bottom;
};

