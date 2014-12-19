/*
*
*	GameLocal.h
*	A class that holds all of the game's logic. This can be later used to port the game to the server.
*
*/

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "globals.h"

#ifndef H_GAME_LOCAL
#define H_GAME_LOCAL

class GameLocal
{
private:
	sf::Clock entityClock;
	bool entitesPaused = false;

public:
	
};

#endif