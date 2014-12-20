#include <cmath>

#include "Game.h"

Game::Game()
{;
	local = true;
}

void Game::tick()
{
	if (entityClock.getElapsedTime().asMilliseconds() > tickDuration)
	{
		entityClock.restart();
		x = int(117 + 117 * sin((degrees)*PI / 180));
		y = int(117 + 117 * cos((degrees2)*PI / 180));
		
		degrees += 1;
		degrees2 += 6;
	}
}