#pragma once
#include <random>

class Random
{
public:
	explicit Random(int min, int max);
	explicit Random(int max);

	int operator()();

private:
	std::random_device _rd{};
	std::mt19937 _generator;
	std::uniform_int_distribution<int> _distribution{};
};
