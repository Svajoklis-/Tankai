#include <iostream>

#include "StateTest.h"

#include "globals.h"
#include "Game.h"
#include "GameData.h"

StateTest::StateTest()
{
	fieldOffset = { 16, 10 };
	fieldSize = { 13 * 16, 13 * 16 };
	shBackground = *(new sf::RectangleShape(sf::Vector2<float>((float)screenSize.x, (float)screenSize.y)));
	shFieldBackground = *(new sf::RectangleShape(sf::Vector2<float>((float)fieldSize.x, (float)fieldSize.y)));

	if (!tPlayerOne.loadFromFile(".\\Resources\\Images\\Player1.png"))
	{
		std::cout << "Error loading Player 1 texture";
	}

	sPlayerOne.setTexture(tPlayerOne);
	sPlayerOne.setTextureRect(sf::IntRect(0, 0, 16, 16));

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

			case sf::Keyboard::Num1:
				gameData->newRank = 0;
				break;

			case sf::Keyboard::Num2:
				gameData->newRank = 1;
				break;

			case sf::Keyboard::Num3:
				gameData->newRank = 2;
				break;

			case sf::Keyboard::Num4:
				gameData->newRank = 3;
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
}

void StateTest::render()
{
	window->draw(shBackground);
	window->draw(shFieldBackground);

	sPlayerOne.setTextureRect(sf::IntRect(gameData->direction*32, gameData->rank*16, 16, 16));
	sPlayerOne.setPosition((float)gameData->x + fieldOffset.x, (float)gameData->y + fieldOffset.y);
	window->draw(sPlayerOne);
}

StateTest::~StateTest()
{

}