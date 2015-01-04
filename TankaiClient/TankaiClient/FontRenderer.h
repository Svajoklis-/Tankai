#ifndef H_FONT_RENDERER
#define H_FONT_RENDERER

#include "globals.h"
#include <SFML/Graphics.hpp>

class FontRenderer
{
public:
	FontRenderer(std::string fontBmp);
	int width(std::string text);
	int height(std::string text);
	void render(std::string text, int x, int y);

private:
	sf::Texture font;
	sf::Sprite letter;

	coord chrSize;
};

#endif