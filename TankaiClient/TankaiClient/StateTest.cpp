#include <iostream>

#include "StateTest.h"

#include "globals.h"
#include "Game.h"
#include "GameData.h"

StateTest::StateTest()
{
	playerOne = new PlayerTank(".\\Resources\\Images\\Player1.png");

	fieldOffset = { 16, 10 };
	fieldSize = { 13 * 16, 13 * 16 };
	shBackground = *(new sf::RectangleShape(sf::Vector2<float>((float)screenSize.x, (float)screenSize.y)));
	shFieldBackground = *(new sf::RectangleShape(sf::Vector2<float>((float)fieldSize.x, (float)fieldSize.y)));
	 
	if (local)
	{
		game = new Game();
		gameData = new GameData(game);
	}
	
	shBackground.setFillColor(sf::Color(102, 102, 102, 255));

	shFieldBackground.setPosition(sf::Vector2<float>((float)fieldOffset.x, (float)fieldOffset.y));
	shFieldBackground.setFillColor(sf::Color(0, 0, 0, 255));
}

void StateTest::events()
{
	if (!window->isOpen())
		state = stExit;

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::A:
				gameData->newDirection += 1;
				if (gameData->newDirection >= 4)
					gameData->newDirection = 0;
				break;
			}
		}
	}
}

void StateTest::logic()
{
	if (local)
	{
		game->tick();
	}

	gameData->send();
	gameData->receive();

	playerOne->setCoords({ gameData->x, gameData->y });
	playerOne->setDirection(gameData->direction);
	playerOne->setRank(gameData->rank);
}

void StateTest::render()
{
	window->draw(shBackground);
	window->draw(shFieldBackground);

	playerOne->render(fieldOffset);
}

StateTest::~StateTest()
{

}