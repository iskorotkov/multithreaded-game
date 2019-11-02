#pragma once
#include <memory>
#include "GameState.h"
#include "Console.h"
#include "EnemySpawner.h"
#include "GameSettings.h"

class GameInstance
{
public:
	void StartGame(int rows, int columns);

	[[nodiscard]] std::shared_ptr<GameState> GetGameState() const;
	[[nodiscard]] std::shared_ptr<Console> GetConsole() const;
	[[nodiscard]] std::shared_ptr<EnemySpawner> GetEnemySpawner() const;
	[[nodiscard]] std::shared_ptr<GameSettings> GetGameSettings() const;

private:
	std::shared_ptr<GameState> _gameState;
	std::shared_ptr<Console> _console;
	std::shared_ptr<EnemySpawner> _enemySpawner;
	std::shared_ptr<GameSettings> _gameSettings;
};
