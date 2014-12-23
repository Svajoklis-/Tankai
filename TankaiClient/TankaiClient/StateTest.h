/*
*
*	StateTest.h
*	StateTest implements the GameState interface,
*	This state is used for temporary work, learning.
*
*/

#include "GameState.h"

#include "globals.h"
#include "Game.h"

#include "PlayerTank.h"

#ifndef H_STATE_TEST
#define H_STATE_TEST

class StateTest : public GameState
{
public:
	StateTest();
	void events();
	void logic();
	void render();

	~StateTest();

private:
	sf::RectangleShape shBackground;
	sf::RectangleShape shFieldBackground;

	sf::Texture tPlayerOne;
	sf::Sprite sPlayerOne;

	Game *game;

	// sizes of the game field
	coord fieldOffset;
	coord fieldSize;

	directions direction = DIR_NO;
	directions direction2 = DIR_NO;
};

#endif // H_BRANCH_TEST
