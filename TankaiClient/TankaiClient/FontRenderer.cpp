#include "FontRenderer.h"

#include <iostream>

FontRenderer::FontRenderer(std::string fontFile)
{
	if (!font.loadFromFile(fontFile))
	{
		std::cout << "Error loading tank texture" << std::endl;
	}

	chrSize.x = font.getSize().x / 16;
	chrSize.y = font.getSize().y / 16;

	letter.setTexture(this->font);	
}

int FontRenderer::width(std::string text)
{
	return text.length() * chrSize.x;
}

int FontRenderer::height(std::string text)
{
	return chrSize.y;
}

void FontRenderer::render(std::string text, int x, int y)
{
	int chr;
	
	for (unsigned i = 0; i < text.length(); i++)
	{
		chr = text[i];
		if (chr < 0 || chr > 255)
		{
			chr = 32;
		}

		letter.setTextureRect(sf::IntRect((chr % 16) * chrSize.x, (chr / 16) * chrSize.y, chrSize.x, chrSize.y));
		letter.setPosition((float)x + i * chrSize.x, (float)y);

		window->draw(letter);
	}
}
