#pragma once
#include <utility>

class Player
{
public:
	Player(int x, int y);

	void MoveRight();
	void MoveLeft();
	void Shoot();

	[[nodiscard]] std::pair<int, int> GetPosition() const;
	[[nodiscard]] char GetLook() const;
	
private:
	int _x, _y;
	char _look = '^';
};
