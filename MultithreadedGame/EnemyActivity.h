#pragma once
#include "Enemy.h"
#include <memory>
#include "GameInstance.h"

class EnemyActivity
{
public:
	void operator()(Enemy enemy, std::shared_ptr<GameInstance> gameInstance) const;

private:
	static void HitEnemy(Enemy& enemy);
	[[nodiscard]] static bool IsEnemyStillOnScreen(const Enemy& enemy);
	static bool CheckForEnemyHit(const std::shared_ptr<GameState>& gameState, Enemy& enemy);
};
