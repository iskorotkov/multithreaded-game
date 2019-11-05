#include "Console.h"
#include "Windows.h"
#include "GameSettings.h"
#include "GameInstance.h"
#include "GameState.h"
#include "EnemySpawner.h"

Console::Console(std::shared_ptr<GameInstance> gameInstance) :
	_gameInstance(std::move(gameInstance))
{
	_cin = GetStdHandle(STD_INPUT_HANDLE);
	_cout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::WriteAt(int x, int y, char c)
{
	std::lock_guard lock(_m);
	const COORD pos = { x, y };
	DWORD res;
	WriteConsoleOutputCharacterA(_cout, &c, 1, pos, &res);
}

void Console::WriteAt(const std::pair<int, int> position, const char c)
{
	WriteAt(position.first, position.second, c);
}

void Console::ClearAt(const int x, const int y)
{
	WriteAt(x, y, ' ');
}

void Console::ClearAt(const std::pair<int, int> position)
{
	WriteAt(position, ' ');
}

void Console::SetCursorVisibility(const bool visible) const
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(_cout, &cursorInfo);
}

void Console::ShowScore(const Score& score) const
{
	TCHAR s[128];
	wsprintf(s, L"Thread War! Попаданий: %3d, Промахов: %3d", score.Hits(), score.Misses());
	SetConsoleTitle(s);

	if (score.Misses() >= 30)
	{
		// TODO: Stop the main thread.
		MessageBox(nullptr, L"Game Over!", L"Thread War",MB_OK | MB_SETFOREGROUND);
		ExitProcess(0);
	}

	if (score.Total() % 20 == 0)
	{
		_gameInstance->GetEnemySpawner()->DecrementSpawnDelay();
	}
}

void Console::Clear() const
{
	const auto gameSettings = _gameInstance->GetGameSettings();
	const COORD org = { 0, 0 };
	DWORD res;
	FillConsoleOutputCharacter(
		_cin,
		' ',
		gameSettings->Rows() * gameSettings->Width(),
		org,
		&res);
}
