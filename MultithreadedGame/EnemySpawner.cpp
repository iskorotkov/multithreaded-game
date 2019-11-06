#include "EnemySpawner.h"
#include <memory>
#include "GameInstance.h"
#include "Random.h"
#include "GameState.h"
#include "GameSettings.h"

void EnemySpawner::StartSpawning()
{
	std::lock_guard lock(_m);
	_gameStarted = true;
	_cv.notify_all();
}

void EnemySpawner::PrepareForSpawning(std::shared_ptr<GameInstance> gameInstance)
{
	std::thread t(&EnemySpawner::Activity, this, gameInstance);
	t.detach();
}

void EnemySpawner::DecrementSpawnDelay()
{
	--_spawnDelay;
}

int EnemySpawner::GetSpawnDelay() const
{
	return _spawnDelay.load();
}

void EnemySpawner::Activity(std::shared_ptr<GameInstance> gameInstance)
{
	using namespace std::chrono_literals;
	std::unique_lock lock(_m);
	_cv.wait_for(lock, 15s, [this] { return _gameStarted; });

	_threadPool = std::make_unique<EnemyThreadPool>(gameInstance);
	Random random(100);
	for (;;)
	{
		const auto& score = gameInstance->GetGameState()->GetScore();
		if (random() < score.Total() / 25 + 20)
		{
			auto enemy = CreateNewEnemy(gameInstance->GetGameSettings());
			_threadPool->AddNewEnemy(std::move(enemy));
		}
		std::this_thread::sleep_for(1s);
	}
}

Enemy EnemySpawner::CreateNewEnemy(std::shared_ptr<GameSettings> settings)
{
	Random randomDirection(0, 2);
	Random randomRow(settings->MinEnemyRow(), settings->MaxEnemyRow() + 1);

	// TODO: Remove cast from random int to enum.
	const auto direction = static_cast<Direction>(randomDirection());
	return Enemy(
		direction,
		randomRow(),
		settings->Width()
	);
}
