/*
*
*	Main file. It runs and controls GameStates, initializes and deinitializes SFML.
*
*/

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <INIReader.h>

#include "globals.h"

#include "GameState.h"
#include "StateTest.h"

int init();
void quit();

gameStates state = stNull;
GameState *currentState;

// used by frame limiter
sf::Clock fpsClock;

int main(int argc, char *argv[])
{
	if (init() != 0)
	{
		std::cout << "Init failed..." << std::endl;
		return 2;
	}

	std::cout << "Init succesful..." << std::endl;

	// you can set initial state here
	currentState = new StateTest();

	while (state != stExit)
	{
		fpsClock.restart();

		currentState->events();
		currentState->logic();

		// states render to window texture
		window->clear();
		currentState->render();
		window->display();

		// check if state hasn't changed
		state = currentState->getState();

		if (state != stNull)
		{
			switch (state)
			{
			case stExit:
				delete currentState;
				break;
			case stTest:
				delete currentState;
				currentState = new StateTest();
				break;
			default:
				state = stNull;
				break;
			}
		}
		// delay if frame finished fast enough
		if (fpsClock.getElapsedTime().asMilliseconds() < 1000 / screenFPS)
			sf::sleep(sf::milliseconds((1000 / screenFPS) - fpsClock.getElapsedTime().asMilliseconds()));
	}

	quit();

	return 0;
}

int init()
{
	window = new sf::RenderWindow(sf::VideoMode(500, 500), "SFML works!");
	view = new sf::View();
	view->reset(sf::FloatRect(0, 0, 250, 250));
	window->setView(*view);

	return 0;
}

void quit()
{
	
}
