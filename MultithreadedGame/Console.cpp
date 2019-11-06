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

void Console::WriteAt(const int x, const int y, char c) const
{
	const COORD pos = { static_cast<short>(x), static_cast<short>(y) };
	DWORD res;

	std::lock_guard lock(_m);
	WriteConsoleOutputCharacterA(_cout, &c, 1, pos, &res);
}

void Console::WriteAt(const std::pair<int, int> position, const char c) const
{
	WriteAt(position.first, position.second, c);
}

void Console::ClearAt(const int x, const int y) const
{
	WriteAt(x, y, ' ');
}

void Console::ClearAt(const std::pair<int, int> position) const
{
	WriteAt(position, ' ');
}

void Console::SetCursorVisibility(const bool visible) const
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = visible;

	std::lock_guard lock(_m);
	SetConsoleCursorInfo(_cout, &cursorInfo);
}

void Console::ShowScore(const Score& score) const
{
	TCHAR s[128];
	wsprintf(s, L"Thread War! Попаданий: %d, Промахов: %d", score.Hits(), score.Misses());

	{
		std::lock_guard lock(_m);
		SetConsoleTitle(s);

		if (score.Misses() >= 30)
		{
			MessageBox(nullptr, L"Game Over!", L"Thread War",MB_OK | MB_SETFOREGROUND);
			ExitProcess(0);
		}
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

	std::lock_guard lock(_m);
	FillConsoleOutputCharacter(
		_cin,
		' ',
		gameSettings->Rows() * gameSettings->Width(),
		org,
		&res);
}

Dimensions Console::GetConsoleDimensions() const
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(_cout, &info);
	const auto height = info.srWindow.Bottom - info.srWindow.Top + 1;
	const auto width = info.srWindow.Right - info.srWindow.Left + 1;
	return Dimensions(width, height);
}
