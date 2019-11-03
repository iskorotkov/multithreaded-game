#pragma once

class GameSettings
{
public:
	GameSettings(int rows, int columns);
	
	[[nodiscard]] int GetMinRow() const;
	[[nodiscard]] int GetMaxRow() const;
	[[nodiscard]] int Rows() const;
	[[nodiscard]] int Width() const;
	
private:
	int _minRow = 0;
	int _rows;
	int _width;
};
