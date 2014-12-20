/*
*
*	GameData.h
*	A class that holds essential game data generated locally or received from server,
*
*/

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "globals.h"
#include "Game.h"

#ifndef H_GAME_DATA
#define H_GAME_DATA

class GameData
{
private:
	bool local = true;

	Game *game;
public:

	GameData(Game *game){ this->game = game; }

	// ---- remote data to be received
	void receive();

	int x = 0;
	int y = 0;
	int direction = 0;
	int rank = 0;

	// ---- local data to be sent
	void send();

	int newDirection = 0;
	int newRank = 0;

	// ---- local data

	int oldRank = 0;
	int dispRank = 0;

	int repeats = 100;
};

#endif