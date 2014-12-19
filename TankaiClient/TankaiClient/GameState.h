/*
*
*	GameState.h
*	This is the header file for abstract class GameState used in the main application for switching
*	between various "screens" of the game
*
*/

#ifndef H_GAME_STATE
#define H_GAME_STATE

enum gameStates
{
	stExit,
	stNull,

	stTest
};

class GameState
{
public:
	virtual void events() = 0;
	virtual void logic() = 0;
	virtual void render() = 0;
	virtual ~GameState(){};

	gameStates getState(){ return state; };

protected:
	gameStates state = stNull;
};

#endif // H_GAME_STATE

