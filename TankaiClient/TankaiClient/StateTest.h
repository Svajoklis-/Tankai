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
#include "GameData.h"

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

	bool local = true;

	Game *game;
	GameData *gameData;

	// sizes of the game field
	coord fieldOffset;
	coord fieldSize;

	Tank *playerOne;
};

#endif // H_BRANCH_TEST
