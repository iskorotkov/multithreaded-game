#include "GameInstance.h"
#include <memory>
#include "GameState.h"
#include "Console.h"
#include "EnemySpawner.h"
#include "GameSettings.h"
#include "AudioManager.h"

void GameInstance::Start()
{
	if (!_isGameStarted)
	{
		_enemySpawner->StartSpawning();
	}
	_isGameStarted = true;
}

std::shared_ptr<GameInstance> GameInstance::Create()
{
	const auto game = std::shared_ptr<GameInstance>(new GameInstance);
	game->Initialize();
	return game;
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

std::shared_ptr<AudioManager> GameInstance::GetAudioManager() const
{
	return _audioManager;
}

void GameInstance::CreateGameComponents()
{
	_console = std::make_shared<Console>(weak_from_this());
	const auto dimensions = _console->GetConsoleDimensions();
	
	_gameState = std::make_shared<GameState>(dimensions.Height(), dimensions.Width());
	_enemySpawner = std::make_shared<EnemySpawner>();
	_audioManager = std::make_shared<AudioManager>();
	_gameSettings = std::make_shared<GameSettings>(dimensions.Height(), dimensions.Width());
}

void GameInstance::Initialize()
{
	CreateGameComponents();

	_console->SetCursorVisibility(false);
	_console->ShowScore(_gameState->GetScore());
	_enemySpawner->PrepareForSpawning(shared_from_this());
}
