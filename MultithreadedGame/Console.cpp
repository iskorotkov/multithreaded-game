#include "Console.h"

void Console::WriteAt(int x, int y, char c)
{
	// TODO
}

void Console::WriteAt(const std::pair<int, int> position, const char c)
{
	WriteAt(position.first, position.second, c);
}

void Console::ShowScore(Score score)
{
	// TODO
}

void Console::Clear()
{
	// TODO
}
