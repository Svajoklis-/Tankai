#include <cmath>

#include "Game.h"
#include "PlayerTank.h"

Game::Game()
{
	local = true;

	fieldSize = { 13 * 16, 13 * 16 };

	playerOne = new PlayerTank(".\\Resources\\Images\\Player1.png");
	playerTwo = new PlayerTank(".\\Resources\\Images\\Player2.png");
}

void Game::tick()
{
	if (entityClock.getElapsedTime().asMilliseconds() > tickDuration)
	{
		entityClock.restart();
		

		// ========================= PLAYER ONE ===================================
		coord c = playerOne->getCoords();
		switch (playerOne->getDirection())
		{
		case DIR_UP: // up

			/*
			if ((playerOne->getOldDirection() == DIR_LEFT) || (playerOne->getOldDirection() == DIR_RIGHT))
			{
				std::cout << "Adjusting..." << std::endl;*/
			if (c.x % 8 < 4)
			{
				c.x = (c.x / 8) * 8;
			}
			else
			{
				c.x = (c.x / 8) * 8 + 8;
			}
			//}

			if (c.y > 0)
				c.y--;
			break;
		case DIR_RIGHT: // up

			if (c.y % 8 < 4)
			{
				c.y = (c.y / 8) * 8;
			}
			else
			{
				c.y = (c.y / 8) * 8 + 8;
			}

			if (c.x < fieldSize.x - 16)
				c.x++;
			break;
		case DIR_DOWN: // up

			if (c.x % 8 < 4)
			{
				c.x = (c.x / 8) * 8;
			}
			else
			{
				c.x = (c.x / 8) * 8 + 8;
			}

			if (c.y < fieldSize.y - 16)
				c.y++;
			break;
		case DIR_LEFT: // up

			if (c.y % 8 < 4)
			{
				c.y = (c.y / 8) * 8;
			}
			else
			{
				c.y = (c.y / 8) * 8 + 8;
			}

			if (c.x > 0)
				c.x--;
			break;
		case DIR_NO:
			break;
		}
		playerOne->setCoords(c);

		// ========================= PLAYER TWO ===================================
		c = playerTwo->getCoords();
		switch (playerTwo->getDirection())
		{
		case DIR_UP: // up

			/*
			if ((playerOne->getOldDirection() == DIR_LEFT) || (playerOne->getOldDirection() == DIR_RIGHT))
			{
			std::cout << "Adjusting..." << std::endl;*/
			if (c.x % 8 < 4)
			{
				c.x = (c.x / 8) * 8;
			}
			else
			{
				c.x = (c.x / 8) * 8 + 8;
			}
			//}

			if (c.y > 0)
				c.y--;
			break;
		case DIR_RIGHT: // up

			if (c.y % 8 < 4)
			{
				c.y = (c.y / 8) * 8;
			}
			else
			{
				c.y = (c.y / 8) * 8 + 8;
			}

			if (c.x < fieldSize.x - 16)
				c.x++;
			break;
		case DIR_DOWN: // up

			if (c.x % 8 < 4)
			{
				c.x = (c.x / 8) * 8;
			}
			else
			{
				c.x = (c.x / 8) * 8 + 8;
			}

			if (c.y < fieldSize.y - 16)
				c.y++;
			break;
		case DIR_LEFT: // up

			if (c.y % 8 < 4)
			{
				c.y = (c.y / 8) * 8;
			}
			else
			{
				c.y = (c.y / 8) * 8 + 8;
			}

			if (c.x > 0)
				c.x--;
			break;
		case DIR_NO:
			break;
		}
		playerTwo->setCoords(c);
	}
}