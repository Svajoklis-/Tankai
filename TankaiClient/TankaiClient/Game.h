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
#include "Tank.h"
#include "Map.h"

#ifndef H_GAME
#define H_GAME

#define PI 3.14159265

class Game
{
private:
	coord fieldSize;

	sf::Clock entityClock;
	sf::Clock rankClock;
	int tickDuration = 16;
	bool entitesPaused = false;

	// true if it is local, if on server - false;
	bool local;

public:
	Game();
	void tick();

	Tank *playerOne;
	Tank *playerTwo;

	Tank *tanks[64];
	int maxTankCount = 64;

	Map *map;
};

#endif