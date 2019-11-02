#pragma once

class GameSettings
{
public:
	// TODO: Add methods to change fields' values.
	
	[[nodiscard]] int GetMinRow() const;
	[[nodiscard]] int GetMaxRow() const;
	[[nodiscard]] int Rows() const;
	[[nodiscard]] int Width() const;
	
private:
	int _minRow = 0;
	int _rows = 10;
	int _width = 50;
};
