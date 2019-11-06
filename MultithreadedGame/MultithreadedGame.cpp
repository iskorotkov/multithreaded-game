#include "GameInstance.h"
#include "Player.h"

int main()
{
	const auto game = GameInstance::Create();

	const auto gameSettings = game->GetGameSettings();

	const Player player(game);
	for (;;)
	{
		player.Render(game->GetConsole());
		player.Tick();
	}
}
