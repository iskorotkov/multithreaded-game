#pragma once
#include <mutex>

class GameInstance;

class BulletActivity
{
public:
	void operator()(int x, int y, std::shared_ptr<GameInstance> gameInstance) const;

private:
	mutable std::mutex _m;

	static bool IsBulletOnScreen(int x, int y, std::shared_ptr<GameInstance> gameInstance);
};
