#include <cmath>

#include "Game.h"

Game::Game()
{
	local = true;
}

void Game::tick()
{
	if (entityClock.getElapsedTime().asMilliseconds() > tickDuration)
	{
		entityClock.restart();

		direction = newDirection;

		if (rankClock.getElapsedTime().asMilliseconds() > 500)
		{
			rankClock.restart();
			rank++;
			if (rank >= 4)
			{
				rank = 0;
			}
		}

		x = int(0 + abs((13 * 16 - 16) * sin((degrees)*PI / 180)));
		y = int(0 + abs((13 * 16 - 16) * cos((degrees2)*PI / 180)));
		
		degrees += 0.25;
		degrees2 += 1;
	}
}