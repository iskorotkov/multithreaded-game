#pragma once
#include <memory>
#include "GameInstance.h"

class BulletActivity
{
public:
	void operator()(int x, int y, std::shared_ptr<GameInstance> gameInstance);

private:
	std::mutex _m;

	// TODO: Pass game instance by pointer or by reference.
	static bool IsBulletOnScreen(int x, int y, const std::shared_ptr<GameInstance>& gameInstance);
};
