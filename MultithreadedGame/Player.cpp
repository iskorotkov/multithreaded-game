#include "Player.h"

Player::Player(const int x, const int y) :
	_x(x),
	_y(y)
{
}

void Player::MoveRight()
{
	++_x;
}

void Player::MoveLeft()
{
	--_x;
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
