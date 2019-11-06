#include "GameInstance.h"
#include "Player.h"
#include "InputComponent.h"
#include "GameSettings.h"
#include "Console.h"
#include <thread>
#include "EnemySpawner.h"

int main()
{
	const auto game = GameInstance::Create(10, 50);

	const auto gameSettings = game->GetGameSettings();

	Player player(
		gameSettings->Width() / 2,
		gameSettings->PlayerRow(),
		gameSettings->Width()
	);

	InputComponent inputComponent;
	inputComponent.AddBinding(
		"space",
		[&player, &game]
		{
			using namespace std::chrono_literals;
			player.Shoot(game);
			std::this_thread::sleep_for(200ms);
		}
	);
	inputComponent.AddBinding("left", [&player, &game]
	{
		game->GetConsole()->ClearAt(player.GetPosition());
		player.MoveLeft();
		game->Start();
	});
	inputComponent.AddBinding("right", [&player, &game]
	{
		game->GetConsole()->ClearAt(player.GetPosition());
		player.MoveRight();
		game->Start();
	});

	const auto console = game->GetConsole();

	for (;;)
	{
		console->WriteAt(player.GetPosition(), player.GetLook());

		inputComponent.ProcessInput();
	}
}
