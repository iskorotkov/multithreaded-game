#pragma once

class Dimensions
{
public:
	Dimensions(int width, int height);

	[[nodiscard]] int Width() const;
	[[nodiscard]] int Height() const;

private:
	int _width;
	int _height;
};