#pragma once
#include <random>

class Random
{
public:
	explicit Random(int min = 0, int max = 100);

	int operator()();

private:
	std::random_device _rd{};
	std::mt19937 _generator;
	std::uniform_int_distribution _distribution{};
};
