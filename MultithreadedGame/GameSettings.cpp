#include "GameSettings.h"

GameSettings::GameSettings(const int rows, const int columns) :
	_rows(rows),
	_width(columns)
{
}

int GameSettings::GetMinRow() const
{
	return _minRow;
}

int GameSettings::GetMaxRow() const
{
	return GetMinRow() + Rows();
}

int GameSettings::Rows() const
{
	return _rows;
}

int GameSettings::Width() const
{
	return _width;
}
