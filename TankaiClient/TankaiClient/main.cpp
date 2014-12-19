/*
*
*	Main file. It runs and controls GameStates, initializes and deinitializes SDL.
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

gameStates state = st_null;
GameState *current_state;

// used by frame limiter
sf::Clock fps_clock;

int main(int argc, char *argv[])
{
	if (init() != 0)
		return 2;

	// you can set initial state here
	current_state = new StateTest();

	while (state != st_exit)
	{
		fps_clock.restart();

		current_state->events();
		current_state->logic();

		// states render to window texture
		window->clear();
		current_state->render();
		window->display();

		// check if state hasn't changed
		state = current_state->getState();

		if (state != st_null)
		{
			switch (state)
			{
			case st_exit:
				delete current_state;
				break;
			case st_test:
				delete current_state;
				current_state = new StateTest();
				break;
			default:
				state = st_null;
				break;
			}
		}
		// delay if frame finished fast enough
		if (fps_clock.getElapsedTime().asMilliseconds() < 1000 / screenFPS)
			sf::sleep(sf::milliseconds((1000 / screenFPS) - fps_clock.getElapsedTime().asMilliseconds()));
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
