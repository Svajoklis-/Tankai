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

const int screenFPS = 120;

extern sf::RenderWindow *window;
extern sf::View *view;

#endif