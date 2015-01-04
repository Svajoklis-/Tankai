/*
*
*	Globals.h
*	All the global variables (screen dimensions, data that is shared between states)
*	should be declared here.
*
*/

#ifndef H_GLOBALS
#define H_GLOBALS

#include <SFML/Graphics.hpp>

extern int TILE_SIZE;

const int screenFPS = 120;

extern sf::RenderWindow *window;
extern sf::View *view;

struct coord
{
	int x;
	int y;
};

enum directions
{
	DIR_UP = 0,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_NO = -1
};

extern int viewScale;
extern coord screenSize;
extern coord windowSize;


#endif