#pragma once
#include <memory>
#include <condition_variable>
#include "EnemyThreadPool.h"

class GameInstance;

class EnemySpawner
{
public:
	void StartGame();
	void StartSpawning(std::shared_ptr<GameInstance> gameInstance);
	
	[[nodiscard]] int GetSpawnDelay() const;
	
private:
	int _spawnDelay = 7;
	bool _gameStarted = false;
	std::mutex _m;
	std::condition_variable _cv;
	std::unique_ptr<EnemyThreadPool> _threadPool;
};
