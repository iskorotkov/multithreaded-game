#include "BulletActivity.h"
#include "GameInstance.h"
#include "State.h"
#include "GameState.h"
#include "GameSettings.h"
#include "Console.h"

void BulletActivity::operator()(const int x, int y, std::shared_ptr<GameInstance> gameInstance) const
{
	const auto gameState = gameInstance->GetGameState();
	const auto console = gameInstance->GetConsole();

	if (gameState->At(x, y) == State::Bullet)
	{
		return;
	}

	const std::unique_lock lock(_m, std::try_to_lock);
	if (lock.owns_lock())
	{
		while (IsBulletOnScreen(x, y, gameInstance))
		{
			using namespace std::chrono_literals;

			gameState->Set(x, y, State::Bullet);
			console->WriteAt(x, y, '*');
			std::this_thread::sleep_for(100ms);
			gameState->Clear(x, y);
			console->ClearAt(x, y);

			// TODO: Bullet isn't moving anywhere? (Solved - see below)
			// TODO: Encapsulate movement logic.
			--y;
		}
	}
}

bool BulletActivity::IsBulletOnScreen(int x, const int y, std::shared_ptr<GameInstance> gameInstance)
{
	const auto gameSettings = gameInstance->GetGameSettings();
	return y >= gameSettings->MinRow() && y <= gameSettings->MaxRow();
}
