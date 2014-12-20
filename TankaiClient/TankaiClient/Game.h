/*
*
*	Game.h
*	A class that holds all of the game's logic. This can be later used to port the game to the server.
*
*/

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "globals.h"

#ifndef H_GAME
#define H_GAME

#define PI 3.14159265

class Game
{
private:
	sf::Clock entityClock;
	int tickDuration = 16;
	bool entitesPaused = false;

	// true if it is local, if on server - false;
	bool local;

public:
	Game();
	void tick();

	int x = 0;
	int y = 0;
	int degrees = 0;
	int degrees2 = 0;
};

#endif