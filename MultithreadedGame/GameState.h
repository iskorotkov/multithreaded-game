#pragma once
#include <vector>
#include <shared_mutex>
#include "State.h"
#include "Score.h"

class GameState
{
public:
	GameState(int rows, int columns);

	void Set(int x, int y, State newState);
	void Set(std::pair<int, int> position, State newState);

	void Clear(std::pair<int, int> position);
	void Clear(int x, int y);

	Score& GetScore();
	const Score& GetScore() const;

	[[nodiscard]] State At(std::pair<int, int> position) const;
	[[nodiscard]] State At(int x, int y) const;

private:
	std::vector<std::vector<State>> _state;
	std::shared_mutex _m;
	Score _score{ 0, 0 };
};
