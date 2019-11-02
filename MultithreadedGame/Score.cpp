#include "Score.h"

Score::Score(const int hits, const int misses)
{
	_hits.store(hits);
	_misses.store(misses);
}

void Score::AddHit()
{
	++_hits;
}

void Score::AddMiss()
{
	++_misses;
}

int Score::Hits() const
{
	return _hits.load();
}

int Score::Misses() const
{
	return _misses.load();
}

int Score::Total() const
{
	return Hits() + Misses();
}
