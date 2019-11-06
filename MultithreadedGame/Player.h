#pragma once
#include <utility>
#include <memory>

class GameInstance;
class InputComponent;
class Console;

class Player
{
public:
	explicit Player(std::shared_ptr<GameInstance> game);

	void MoveRight();
	void MoveLeft();
	void Shoot(std::shared_ptr<GameInstance> gameInstance) const;
	void Tick(std::shared_ptr<GameInstance> game) const;
	void Render(std::shared_ptr<Console> console) const;

	[[nodiscard]] std::pair<int, int> GetPosition() const;
	[[nodiscard]] char GetLook() const;
	
private:
	int _width;
	int _x, _y;
	char _look = '|';
	std::shared_ptr<InputComponent> _inputComponent;

	void AddBindings(std::shared_ptr<GameInstance> game);
};
