#include "EnemySpawner.h"
#include "Random.h"
#include <memory>

void EnemySpawner::StartGame()
{
	_gameStarted = true;
	_cv.notify_all();
}

void EnemySpawner::StartSpawning(std::shared_ptr<GameInstance> gameInstance)
{
	using namespace std::chrono_literals;
	std::unique_lock lock(_m);
	_cv.wait_for(lock, 15s, [this] { return _gameStarted; });

	_threadPool = std::make_unique<EnemyThreadPool>(gameInstance);
	const auto& score = gameInstance->GetGameState()->GetScore();
	Random random;
	for (;;)
	{
		if (random() < score.Total() / 25 + 20)
		{
			const auto gameSettings = gameInstance->GetGameSettings();
			auto enemy = [gameSettings]
			{
				Random randomDirection(0, 2);
				Random randomRow(gameSettings->GetMinRow(), gameSettings->GetMaxRow());
				// TODO: Remove cast from random int to enum.
				const auto direction = static_cast<Direction>(randomDirection());
				return Enemy(
					direction,
					randomRow(),
					gameSettings->Width()
				);
			}();
			_threadPool->AddNewEnemy(std::move(enemy));

			std::this_thread::sleep_for(1s);
		}
	}
}

int EnemySpawner::GetSpawnDelay() const
{
	return _spawnDelay;
}
