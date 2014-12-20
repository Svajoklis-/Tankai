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
	}
}

void StateTest::logic()
{
	if (local)
	{
		game->tick();
	}

	gameData->receive();
}

void StateTest::render()
{
	sPlayerOne.setPosition(gameData->x, gameData->y);
	window->draw(sPlayerOne);
}

StateTest::~StateTest()
{

}