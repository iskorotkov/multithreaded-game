#include "GameInstance.h"
#include <memory>
#include "GameState.h"
#include "Console.h"
#include "EnemySpawner.h"
#include "GameSettings.h"

void GameInstance::StartGame(const int rows, const int columns)
{
	_gameState = std::make_shared<GameState>(rows, columns);
	_console = std::make_shared<Console>();
	_enemySpawner = std::make_shared<EnemySpawner>();
	_gameSettings = std::make_shared<GameSettings>(rows, columns);

	// BUG: Pass by ref or by pointer. It's the only place where we have shared ptr to GameInstance.
	_enemySpawner->StartSpawning(std::shared_ptr<GameInstance>(this));
	// TODO: Where do I need to call spawner->StartGame()?
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
