#include "GameSettings.h"

GameSettings::GameSettings(const int rows, const int columns) :
	_rows(rows),
	_width(columns)
{
}

int GameSettings::MinRow() const
{
	return _minRow;
}

int GameSettings::MaxRow() const
{
	return MinRow() + Rows() - 1;
}

int GameSettings::Rows() const
{
	return _rows;
}

int GameSettings::Width() const
{
	return _width;
}

int GameSettings::PlayerRow() const
{
	return MaxRow();
}

int GameSettings::MinEnemyRow() const
{
	return MinRow();
}

int GameSettings::MaxEnemyRow() const
{
	return MaxRow() - 1;
}
