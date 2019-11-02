#include "GameSettings.h"

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
