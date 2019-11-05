#pragma once
#include <memory>

class GameState;
class Console;
class EnemySpawner;
class GameSettings;

class GameInstance : public std::enable_shared_from_this<GameInstance>
{
public:
	static std::shared_ptr<GameInstance> Create(int rows, int columns);
	
	void Start();

	[[nodiscard]] std::shared_ptr<GameState> GetGameState() const;
	[[nodiscard]] std::shared_ptr<Console> GetConsole() const;
	[[nodiscard]] std::shared_ptr<EnemySpawner> GetEnemySpawner() const;
	[[nodiscard]] std::shared_ptr<GameSettings> GetGameSettings() const;

protected:
	GameInstance() = default;
	
	void Initialize(int rows, int columns);

private:
	std::shared_ptr<GameState> _gameState;
	std::shared_ptr<Console> _console;
	std::shared_ptr<EnemySpawner> _enemySpawner;
	std::shared_ptr<GameSettings> _gameSettings;
	bool _isGameStarted = false;
};
