#include <iostream>

#include "StateTest.h"

#include "globals.h"

StateTest::StateTest() :
	shape(125.f)
{
	shape.setFillColor(sf::Color::Green);
	if (!tPlayerOne.loadFromFile(".\\Resources\\Images\\Player1.png"))
	{
		std::cout << "Error loading Player 1 texture";
	}

	sPlayerOne.setTexture(tPlayerOne);
	sPlayerOne.setTextureRect(sf::IntRect(0, 0, 16, 16));
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

}

void StateTest::render()
{
	window->draw(shape);
	window->draw(sPlayerOne);
}

StateTest::~StateTest()
{

}