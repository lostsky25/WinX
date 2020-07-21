#pragma once
class XMargins
{
public:
	XMargins() = default;
	XMargins(int, int, int, int);
	~XMargins() = default;

	void setMargins(int, int, int, int);
	XMargins margins();

	int left();
	int top();
	int right();
	int bottom();

	void setLeft(int);
	void setTop(int);
	void setRight(int);
	void setBottom(int);

private:
	int _left;
	int _top;
	int _right;
	int _bottom;

};

