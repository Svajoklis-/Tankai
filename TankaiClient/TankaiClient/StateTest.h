#include "GameState.h"

#include "globals.h"

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
	sf::CircleShape shape;
	sf::Texture tPlayerOne;
	sf::Sprite sPlayerOne;
};

#endif // H_BRANCH_TEST
