#pragma once

class GameSettings
{
public:
	GameSettings(int rows, int columns);
	
	[[nodiscard]] int MinRow() const;
	[[nodiscard]] int MaxRow() const;
	[[nodiscard]] int Rows() const;
	[[nodiscard]] int Width() const;

	[[nodiscard]] int PlayerRow() const;
	[[nodiscard]] int MinEnemyRow() const;
	[[nodiscard]] int MaxEnemyRow() const;
	
private:
	int _minRow = 0;
	int _rows;
	int _width;
};
