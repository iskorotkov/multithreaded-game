#pragma once
#include <atomic>

class Score
{
public:
	Score(int hits, int misses);

	void AddHit();
	void AddMiss();

	[[nodiscard]] int Hits() const;
	[[nodiscard]] int Misses() const;
	[[nodiscard]] int Total() const;

private:
	std::atomic<int> _hits;
	std::atomic<int> _misses;
};
