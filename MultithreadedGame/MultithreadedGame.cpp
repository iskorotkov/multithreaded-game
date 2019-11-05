#include "GameInstance.h"
#include "Player.h"
#include "InputComponent.h"
#include "GameSettings.h"
#include "Console.h"
#include <thread>
#include "EnemySpawner.h"

int main()
{
	const auto game = std::make_shared<GameInstance>();
	game->StartGame(10, 50);

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
			std::this_thread::sleep_for(100ms);
		}
	);
	inputComponent.AddBinding("left", [&player, &game]
	{
		game->GetConsole()->ClearAt(player.GetPosition());
		player.MoveLeft();
		game->GetEnemySpawner()->StartSpawning();
	});
	inputComponent.AddBinding("right", [&player, &game]
	{
		game->GetConsole()->ClearAt(player.GetPosition());
		player.MoveRight();
		game->GetEnemySpawner()->StartSpawning();
	});

	const auto console = game->GetConsole();

	for (;;)
	{
		console->WriteAt(player.GetPosition(), player.GetLook());

		inputComponent.ProcessInput();
	}
}
