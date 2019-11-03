#include "EnemyActivity.h"
#include <chrono>
#include "State.h"
#include "Enemy.h"
#include "GameSettings.h"
#include "GameState.h"
#include "GameInstance.h"
#include "Console.h"
#include "EnemySpawner.h"

bool EnemyActivity::IsEnemyStillOnScreen(const Enemy& enemy, std::shared_ptr<GameSettings> gameSettings)
{
	const auto position = enemy.GetPosition();
	const auto width = gameSettings->Width();
	return position.first >= 0 && position.first < width;
}

void EnemyActivity::HitEnemy(Enemy& enemy)
{
	enemy.Hit();
}

bool EnemyActivity::CheckForEnemyHit(const std::shared_ptr<GameState>& gameState, Enemy& enemy)
{
	if (gameState->At(enemy.GetPosition()) == State::Bullet)
	{
		HitEnemy(enemy);
		return true;
	}
	return false;
}

void EnemyActivity::operator()(Enemy enemy, std::shared_ptr<GameInstance> gameInstance) const
{
	const auto gameState = gameInstance->GetGameState();
	const auto console = gameInstance->GetConsole();
	const auto enemySpawner = gameInstance->GetEnemySpawner();
	const auto gameSettings = gameInstance->GetGameSettings();

	while (IsEnemyStillOnScreen(enemy, gameSettings)
		&& !enemy.WasHit())
	{
		CheckForEnemyHit(gameState, enemy);

		console->WriteAt(enemy.GetPosition(), enemy.GetLook());
		enemy.ChangeLook();

		CheckForEnemyHit(gameState, enemy);

		const auto delay = enemySpawner->GetSpawnDelay();
		const auto count = [delay]()
		{
			if (delay < 3)
			{
				return 3;
			}
			return delay + 3;
		}();

		for (auto i = 0; i < count; ++i)
		{
			using namespace std::chrono_literals;
			std::this_thread::sleep_for(40ms);
			if (CheckForEnemyHit(gameState, enemy))
			{
				break;
			}
		}

		console->WriteAt(enemy.GetPosition(), enemy.GetLook());

		CheckForEnemyHit(gameState, enemy);

		enemy.Move();
	}

	if (enemy.WasHit())
	{
	}
}
