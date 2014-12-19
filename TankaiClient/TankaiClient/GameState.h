#ifndef H_GAME_STATE
#define H_GAME_STATE

enum gameStates
{
	st_exit,
	st_null,

	st_test
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
	gameStates state = st_null;
};

#endif // H_GAME_STATE

