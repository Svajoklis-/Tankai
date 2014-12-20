#include <iostream>

#include "StateTest.h"

#include "globals.h"
#include "Game.h"
#include "GameData.h"

StateTest::StateTest()
{
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
				gameData->oldRank = gameData->rank;
				gameData->newRank = 0;
				break;

			case sf::Keyboard::Num2:
				gameData->oldRank = gameData->rank;
				gameData->newRank = 1;
				break;

			case sf::Keyboard::Num3:
				gameData->oldRank = gameData->rank;
				gameData->newRank = 2;
				break;

			case sf::Keyboard::Num4:
				gameData->oldRank = gameData->rank;
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
	
	if (gameData->oldRank != gameData->newRank)
	{
		if (gameData->repeats >= 0)
		{
			if (gameData->repeats % 25 >= 25/2)
				gameData->dispRank = gameData->oldRank;
			else
				gameData->dispRank = gameData->newRank;
			gameData->repeats--;
		}
		else
		{
			gameData->oldRank = gameData->newRank;
			gameData->dispRank = gameData->rank;
			gameData->repeats = 100;
		}
	}
}

void StateTest::render()
{
	sPlayerOne.setTextureRect(sf::IntRect(gameData->direction*32, gameData->dispRank*16, 16, 16));
	sPlayerOne.setPosition(gameData->x, gameData->y);
	window->draw(sPlayerOne);
}

StateTest::~StateTest()
{

}