#pragma once
class XSize
{
public:
	XSize();
	XSize(unsigned, unsigned);
	~XSize();

	int height();
	int width();

	void setHeight(int);
	void setWidth(int);

private:
	int _height = 0;
	int _width = 0;

};

