/*
*
*	Game.h
*	A class that holds all of the game's logic. This can be later used to port the game to the server.
*
*/

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#ifndef H_GAME
#define H_GAME

namespace nsGame
{
	struct coord
	{
		int x;
		int y;
	};
}

#define PI 3.14159265

class Game
{
private:

	nsGame::coord fieldSize;

	sf::Clock entityClock;
	sf::Clock rankClock;
	int tickDuration = 16;
	bool entitesPaused = false;

	// true if it is local, if on server - false;
	bool local;

public:
	Game();
	void tick();

	// ---- server data that is sent

	int x = 0;
	int y = 0;

	int direction = 0;
	int rank = 0;

	// ---- additional game-related data

	double degrees = 0;
	double degrees2 = 0;

	// ---- incoming data

	int newDirection = 0;
};

#endif