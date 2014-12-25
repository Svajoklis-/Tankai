#include <cmath>

#include "Game.h"
#include "PlayerTank.h"

Game::Game()
{
	local = true;

	fieldSize = { 13 * 16, 13 * 16 };

	playerOne = new PlayerTank(".\\Resources\\Images\\Player1.png");
	playerTwo = new PlayerTank(".\\Resources\\Images\\Player2.png");

	for (int i = 0; i < 64; i++)
	{
		tanks[i] = nullptr;
	}

	tanks[0] = playerOne;
	playerOne->setID(0);
	tanks[1] = playerTwo;
	playerTwo->setID(1);

	playerTwo->setCoords({ 32, 32 });

	map = new Map();
}

void Game::tick()
{
	if (entityClock.getElapsedTime().asMilliseconds() > tickDuration)
	{
		entityClock.restart();

		for (int i = 0; i < 64; i++)
		{
			if (tanks[i] != nullptr)
			{
				tanks[i]->move(fieldSize, tanks, maxTankCount);
			}
		}
	}
}