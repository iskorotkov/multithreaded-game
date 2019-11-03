#pragma once
#include <thread>
#include <memory>
#include <vector>
#include "Enemy.h"

class GameInstance;

class EnemyThreadPool
{
public:
	explicit EnemyThreadPool(std::shared_ptr<GameInstance> gameInstance);
	
	void AddNewEnemy(Enemy enemy);

	template <typename T>
	void AddNewEnemies(T&& enemies);

private:
	std::vector<std::thread> _threads;
	std::shared_ptr<GameInstance> _gameInstance;
};

template <typename T>
void EnemyThreadPool::AddNewEnemies(T&& enemies)
{
	for (const auto enemy : enemies)
	{
		AddNewEnemy(enemy);
	}
}
