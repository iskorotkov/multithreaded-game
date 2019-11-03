#pragma once
#include <memory>

class Enemy;
class GameInstance;
class GameState;
class GameSettings;

class EnemyActivity
{
public:
	void operator()(Enemy enemy, std::shared_ptr<GameInstance> gameInstance) const;

private:
	static void HitEnemy(Enemy& enemy);
	[[nodiscard]] static bool IsEnemyStillOnScreen(const Enemy& enemy, std::shared_ptr<GameSettings> gameSettings);
	static bool CheckForEnemyHit(const std::shared_ptr<GameState>& gameState, Enemy& enemy);
};
