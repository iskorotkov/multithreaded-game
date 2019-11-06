#pragma once
#include <utility>
#include "Score.h"
#include <memory>
#include "Windows.h"
#include <mutex>
#include "Dimensions.h"

class GameInstance;

class Console
{
public:
	explicit Console(std::weak_ptr<GameInstance> gameInstance);
	
	void WriteAt(int x, int y, char c) const;
	void WriteAt(std::pair<int, int> position, char c) const;

	void ClearAt(int x, int y) const;
	void ClearAt(std::pair<int, int> position) const;

	void SetCursorVisibility(bool visible) const;

	void ShowScore(const Score& score) const;
	
	void Clear() const;

	Dimensions GetConsoleDimensions() const;

private:
	std::weak_ptr<GameInstance> _gameInstance;
	mutable std::mutex _m;
	
	HANDLE _cin;
	HANDLE _cout;
};
