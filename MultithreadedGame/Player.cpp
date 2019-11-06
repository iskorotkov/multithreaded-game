#include "Player.h"
#include <thread>
#include "BulletActivity.h"
#include "GameInstance.h"
#include "InputComponent.h"
#include "Console.h"
#include "GameSettings.h"

void Player::AddBindings(std::shared_ptr<GameInstance> game)
{
	_inputComponent->AddBinding("space", [this, game]
		{
			using namespace std::chrono_literals;
			Shoot(game);
			std::this_thread::sleep_for(200ms);
		}
	);
	_inputComponent->AddBinding("left", [this, game]
	{
		game->GetConsole()->ClearAt(GetPosition());
		MoveLeft();
		game->Start();
	});
	_inputComponent->AddBinding("right", [this, game]
	{
		game->GetConsole()->ClearAt(GetPosition());
		MoveRight();
		game->Start();
	});
}

Player::Player(const std::shared_ptr<GameInstance> game)
{
	_inputComponent = std::make_shared<InputComponent>();
	AddBindings(game);

	const auto gameSettings = game->GetGameSettings();
	_x = gameSettings->Width() / 2;
	_y = gameSettings->PlayerRow();
	_width = gameSettings->Width();
}

void Player::MoveRight()
{
	if (_x < _width - 1)
	{
		++_x;
	}
}

void Player::MoveLeft()
{
	if (_x > 0)
	{
		--_x;
	}
}

void Player::Shoot(std::shared_ptr<GameInstance> gameInstance) const
{
	const auto f = [x = _x, y = _y, gameInstance = std::move(gameInstance)]
	{
		const BulletActivity activity;
		activity(x, y - 1, gameInstance);
	};
	std::thread t(f);
	t.detach();
}

void Player::Tick() const
{
	_inputComponent->ProcessInput();
}

void Player::Render(const std::shared_ptr<Console> console) const
{
	console->WriteAt(GetPosition(), GetLook());
}

std::pair<int, int> Player::GetPosition() const
{
	return { _x, _y };
}

char Player::GetLook() const
{
	return _look;
}
