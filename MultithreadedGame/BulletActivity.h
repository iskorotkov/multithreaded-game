#pragma once
#include <mutex>

class GameInstance;

class BulletActivity
{
public:
	void operator()(int x, int y, std::shared_ptr<GameInstance> gameInstance) const;

private:
	mutable std::mutex _m;

	// TODO: Pass game instance by pointer or by reference.
	static bool IsBulletOnScreen(int x, int y, std::shared_ptr<GameInstance> gameInstance);
};
