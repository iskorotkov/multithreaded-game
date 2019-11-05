#include "Player.h"

Player::Player(const int x, const int y, const int width) :
	_width(width),
	_x(x),
	_y(y)
{
}

void Player::MoveRight()
{
	if (_x < _width - 1)
	{
		++_x;
	}
}

void Player::MoveLeft()
{
	if (_x > 0)
	{
		--_x;
	}
}

void Player::Shoot()
{
	// TODO: spawn bullet thread;
}

std::pair<int, int> Player::GetPosition() const
{
	return { _x, _y };
}

char Player::GetLook() const
{
	return _look;
}
