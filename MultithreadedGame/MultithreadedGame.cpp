#include "GameInstance.h"
#include "Player.h"
#include "InputComponent.h"
#include "GameSettings.h"
#include "Console.h"
#include <thread>

int main()
{
	GameInstance game;
	game.StartGame(10, 50);

	const auto gameSettings = game.GetGameSettings();

	Player player(
		gameSettings->Width() / 2,
		gameSettings->GetMaxRow() - 1
	);

	InputComponent inputComponent;
	inputComponent.AddBinding(
		"space",
		[&player]
		{
			using namespace std::chrono_literals;
			player.Shoot();
			std::this_thread::sleep_for(100ms);
		}
	);
	inputComponent.AddBinding("left", [&player] { player.MoveLeft(); });
	inputComponent.AddBinding("right", [&player] { player.MoveRight(); });

	const auto console = game.GetConsole();

	for (;;)
	{
		console->WriteAt(player.GetPosition(), player.GetLook());

		inputComponent.ProcessInput();
	}
}
