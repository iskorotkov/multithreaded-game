#pragma once
#include "Direction.h"
#include <string>
#include <utility>

class Enemy
{
public:
	explicit Enemy(Direction spawnDirection, int row, int width, std::string looks = R"(-\|/)");

	void Move();
	void ChangeLook();
	void Hit();

	[[nodiscard]] char GetLook() const;
	[[nodiscard]] std::pair<int, int> GetPosition() const;
	[[nodiscard]] int GetWidth() const;
	[[nodiscard]] bool WasHit() const;

private:
	const Direction _movementDirection;
	int _x, _y;
	int _lookIndex = 0;
	int _width;
	const std::string _looks;
	bool _wasHit = false;
};
