#pragma once
#include <memory>
#include "EnemyThreadPool.h"
#include <condition_variable>
#include <atomic>

class GameInstance;
class SpawnerActivity;

class EnemySpawner
{
public:
	void StartSpawning();
	void PrepareForSpawning(std::shared_ptr<GameInstance> gameInstance);
	void DecrementSpawnDelay();

	[[nodiscard]] int GetSpawnDelay() const;

private:
	std::atomic<int> _spawnDelay = 7;
	bool _gameStarted = false;
	std::condition_variable _cv;
	std::unique_ptr<EnemyThreadPool> _threadPool;
	std::mutex _m;

	void Activity(std::shared_ptr<GameInstance> gameInstance);
};
