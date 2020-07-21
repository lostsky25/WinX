#pragma once
class XSize
{
public:
	XSize();
	XSize(unsigned, unsigned);
	~XSize();

	unsigned height();
	unsigned width();

	void setHeight(unsigned);
	void setWidth(unsigned);

private:
	unsigned _height = 0;
	unsigned _width = 0;

};

