#pragma once
#include <memory>
#include <condition_variable>
#include "EnemyThreadPool.h"
#include <atomic>

class GameInstance;

class EnemySpawner
{
public:
	void StartGame();
	void StartSpawning(std::shared_ptr<GameInstance> gameInstance);
	void DecrementSpawnDelay();
	
	[[nodiscard]] int GetSpawnDelay() const;
	
private:
	std::atomic<int> _spawnDelay = 7;
	bool _gameStarted = false;
	std::mutex _m;
	std::condition_variable _cv;
	std::unique_ptr<EnemyThreadPool> _threadPool;
};
