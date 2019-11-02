#include "Enemy.h"
#include <iostream>
#include <utility>

Enemy::Enemy(
	const Direction spawnDirection,
	const int row,
	const int width,
	std::string looks
) :
	_movementDirection(spawnDirection),
	_y(row),
	_width(width),
	_looks(std::move(looks))
{
	switch (_movementDirection)
	{
		case Direction::LeftToRight:
			_x = 0;
			break;
		case Direction::RightToLeft:
			_x = width - 1;
			break;
		default: std::cerr << "Unknown movement type";
	}
}

void Enemy::Move()
{
	switch (_movementDirection)
	{
		case Direction::LeftToRight:
			_x += 1;
			break;
		case Direction::RightToLeft:
			_x -= 1;
			break;
		default: std::cerr << "Unknown movement type";
	}
}

void Enemy::ChangeLook()
{
	_lookIndex = (_lookIndex + 1) % _looks.size();
}

void Enemy::Hit()
{
	_wasHit = true;
}

char Enemy::GetLook() const
{
	return _looks.at(_lookIndex);
}

std::pair<int, int> Enemy::GetPosition() const
{
	return { _x, _y };
}

int Enemy::GetWidth() const
{
	return _width;
}

bool Enemy::WasHit() const
{
	return _wasHit;
}
