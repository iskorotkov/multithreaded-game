#include "GameState.h"
#include <mutex>

GameState::GameState(const int rows, const int columns)
{
	std::lock_guard lock(_m);
	_state.resize(columns, std::vector<State>(rows));
}

void GameState::Set(const int x, const int y, const State newState)
{
	std::lock_guard lock(_m);
	_state[x][y] = newState;
}

void GameState::Set(const std::pair<int, int> position, const State newState)
{
	Set(position.first, position.second, newState);
}

void GameState::Clear(const std::pair<int, int> position)
{
	Clear(position.first, position.second);
}

void GameState::Clear(const int x, const int y)
{
	Set(x, y, State::Empty);
}

State GameState::At(const std::pair<int, int> position) const
{
	return At(position.first, position.second);
}

State GameState::At(const int x, const int y) const
{
	std::shared_lock lock(_m);
	return _state[x][y];
}

Score& GameState::GetScore()
{
	return _score;
}

const Score& GameState::GetScore() const
{
	return _score;
}
