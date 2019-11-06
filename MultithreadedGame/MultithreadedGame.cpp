#include "GameInstance.h"
#include "Player.h"

int main()
{
	const auto game = GameInstance::Create();
	const Player player(game);
	
	for (;;)
	{
		player.Tick(game);
	}
}
