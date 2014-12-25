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
				if (direction != DIR_UP)
					direction = DIR_UP;
				break;

			case sf::Keyboard::Right:
				if (direction != DIR_RIGHT)
					direction = DIR_RIGHT;
				break;

			case sf::Keyboard::Down:
				if (direction != DIR_DOWN)
					direction = DIR_DOWN;
				break;

			case sf::Keyboard::Left:
				if (direction != DIR_LEFT)
					direction = DIR_LEFT;
				break;

			case sf::Keyboard::W:
				if (direction2 != DIR_UP)
					direction2 = DIR_UP;
				break;

			case sf::Keyboard::D:
				if (direction2 != DIR_RIGHT)
					direction2 = DIR_RIGHT;
				break;

			case sf::Keyboard::S:
				if (direction2 != DIR_DOWN)
					direction2 = DIR_DOWN;
				break;

			case sf::Keyboard::A:
				if (direction2 != DIR_LEFT)
					direction2 = DIR_LEFT;
				break;

			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (direction == DIR_UP)
					direction = DIR_NO;
				break;

			case sf::Keyboard::Right:
				if (direction == DIR_RIGHT)
					direction = DIR_NO;
				break;

			case sf::Keyboard::Down:
				if (direction == DIR_DOWN)
					direction = DIR_NO;
				break;

			case sf::Keyboard::Left:
				if (direction == DIR_LEFT)
					direction = DIR_NO;
				break;


			case sf::Keyboard::W:
				if (direction2 == DIR_UP)
					direction2 = DIR_NO;
				break;

			case sf::Keyboard::D:
				if (direction2 == DIR_RIGHT)
					direction2 = DIR_NO;
				break;

			case sf::Keyboard::S:
				if (direction2 == DIR_DOWN)
					direction2 = DIR_NO;
				break;

			case sf::Keyboard::A:
				if (direction2 == DIR_LEFT)
					direction2 = DIR_NO;
				break;

			}
		}
	}
}

void StateTest::logic()
{
	game->playerOne->setDirection(direction);
	game->playerTwo->setDirection(direction2);

	game->tick();
}

void StateTest::render()
{
	window->draw(shBackground);
	window->draw(shFieldBackground);

	game->map->renderUnder(fieldOffset);

	game->playerOne->render(fieldOffset);
	game->playerTwo->render(fieldOffset);

	game->map->renderOver(fieldOffset);
}

StateTest::~StateTest()
{

}