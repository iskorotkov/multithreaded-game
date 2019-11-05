#pragma once
#include <utility>
#include "Score.h"
#include <memory>
#include "Windows.h"
#include <mutex>

class GameInstance;

class Console
{
public:
	explicit Console(std::shared_ptr<GameInstance> gameInstance);
	
	void WriteAt(int x, int y, char c);
	void WriteAt(std::pair<int, int> position, char c);

	void ClearAt(int x, int y);
	void ClearAt(std::pair<int, int> position);

	void SetCursorVisibility(bool visible) const;

	void ShowScore(const Score& score) const;
	
	void Clear() const;

private:
	std::shared_ptr<GameInstance> _gameInstance;
	std::mutex _m;
	
	HANDLE _cin;
	HANDLE _cout;
};
