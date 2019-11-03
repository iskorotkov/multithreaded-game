#include "BulletActivity.h"

void BulletActivity::operator()(const int x, const int y, std::shared_ptr<GameInstance> gameInstance)
{
	const auto gameState = gameInstance->GetGameState();

	if (gameState->At(x, y) == State::Bullet)
	{
		return;
	}

	if (_m.try_lock())
	{
		std::lock_guard lock(_m, std::adopt_lock);

		while (IsBulletOnScreen(x, y, gameInstance))
		{
			using namespace std::chrono_literals;
			gameState->Set(x, y, State::Bullet);
			std::this_thread::sleep_for(100ms);
			gameState->Clear(x, y);
			// TODO: Bullet isn't moving anywhere?
		}
	}
}

bool BulletActivity::IsBulletOnScreen(int x, int y, const std::shared_ptr<GameInstance>& gameInstance)
{
	const auto gameSettings = gameInstance->GetGameSettings();
	return y >= gameSettings->GetMinRow()
	&& y < gameSettings->GetMaxRow();
}
