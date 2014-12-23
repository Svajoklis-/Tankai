#include <iostream>

#include "StateTest.h"

#include "globals.h"
#include "Game.h"

StateTest::StateTest()
{
	fieldOffset = { 16, 10 };
	fieldSize = { 13 * 16, 13 * 16 };
	shBackground = *(new sf::RectangleShape(sf::Vector2<float>((float)screenSize.x, (float)screenSize.y)));
	shFieldBackground = *(new sf::RectangleShape(sf::Vector2<float>((float)fieldSize.x, (float)fieldSize.y)));
	 
	game = new Game();
	
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
			case sf::Keyboard::Up:
				direction = DIR_UP;
				break;

			case sf::Keyboard::Right:
				direction = DIR_RIGHT;
				break;

			case sf::Keyboard::Down:
				direction = DIR_DOWN;
				break;

			case sf::Keyboard::Left:
				direction = DIR_LEFT;
				break;

			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
			case sf::Keyboard::Right:
			case sf::Keyboard::Down:
			case sf::Keyboard::Left:
				direction = DIR_NO;
				break;
			}
		}
	}
}

void StateTest::logic()
{
	game->playerOne->setDirection(direction);

	game->tick();
}

void StateTest::render()
{
	window->draw(shBackground);
	window->draw(shFieldBackground);

	game->playerOne->render(fieldOffset);
}

StateTest::~StateTest()
{

}