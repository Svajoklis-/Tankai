#include <cmath>

#include "Game.h"
#include "PlayerTank.h"

Game::Game()
{
	local = true;

	fieldSize = { 13 * 16, 13 * 16 };

	playerOne = new PlayerTank(".\\Resources\\Images\\Player1.png");
}

void Game::tick()
{
	if (entityClock.getElapsedTime().asMilliseconds() > tickDuration)
	{
		entityClock.restart();
		
		coord c = playerOne->getCoords();
		switch (playerOne->getDirection())
		{
		case DIR_UP: // up
			if (c.y > 0)
				c.y--;
			break;
		case DIR_RIGHT: // up
			if (c.x < fieldSize.x - 16)
				c.x++;
			break;
		case DIR_DOWN: // up
			if (c.y < fieldSize.y - 16)
				c.y++;
			break;
		case DIR_LEFT: // up
			if (c.x > 0)
				c.x--;
			break;
		case DIR_NO:
			break;
		}
		playerOne->setCoords(c);
	}
}