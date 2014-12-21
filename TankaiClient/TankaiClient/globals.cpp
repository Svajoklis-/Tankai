#include "globals.h"

#include <SFML/Graphics.hpp>

sf::RenderWindow *window = nullptr;
sf::View *view = nullptr;

int viewScale = 2;
coord screenSize = { 256, 230 };
coord windowSize = { screenSize.x * viewScale, screenSize.y * viewScale };