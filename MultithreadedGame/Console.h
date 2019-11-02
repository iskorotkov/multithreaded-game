#pragma once
#include <utility>
#include "Score.h"

class Console
{
public:
	void WriteAt(int x, int y, char c);
	void WriteAt(std::pair<int, int> position, char c);

	void ShowScore(Score score);
	
	void Clear();
};
