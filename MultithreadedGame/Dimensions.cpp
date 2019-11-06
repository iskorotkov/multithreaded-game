#include "Dimensions.h"
#include <stdexcept>

Dimensions::Dimensions(const int width, const int height)
{
	if (width < 0)
	{
		throw std::logic_error("Width can't be negative.");
	}
	if (height < 0)
	{
		throw std::logic_error("Height can't be negative.");
	}
	_width = width;
	_height = height;
}

int Dimensions::Width() const
{
	return _width;
}

int Dimensions::Height() const
{
	return _height;
}
