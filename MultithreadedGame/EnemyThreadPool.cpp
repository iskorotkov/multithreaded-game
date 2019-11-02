#include "EnemyThreadPool.h"

#include <utility>
#include "EnemyActivity.h"

EnemyThreadPool::EnemyThreadPool(std::shared_ptr<GameInstance> gameInstance) :
	_gameInstance(std::move(gameInstance))
{
}

void EnemyThreadPool::AddNewEnemy(Enemy enemy)
{
	std::thread t(EnemyActivity(), std::move(enemy), _gameInstance);
	t.detach();
	_threads.emplace_back(std::move(t));
}
