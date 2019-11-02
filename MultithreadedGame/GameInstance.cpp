#include "GameInstance.h"
#include <memory>

void GameInstance::StartGame(const int rows, const int columns)
{
	_gameState = std::make_shared<GameState>(rows, columns);
	_console = std::make_shared<Console>();
	_enemySpawner = std::make_shared<EnemySpawner>();
}

std::shared_ptr<GameState> GameInstance::GetGameState() const
{
	return _gameState;
}

std::shared_ptr<Console> GameInstance::GetConsole() const
{
	return _console;
}

std::shared_ptr<EnemySpawner> GameInstance::GetEnemySpawner() const
{
	return _enemySpawner;
}

std::shared_ptr<GameSettings> GameInstance::GetGameSettings() const
{
	return _gameSettings;
}
