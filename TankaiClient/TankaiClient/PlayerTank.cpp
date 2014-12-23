#include "globals.h"

#include "PlayerTank.h"

#include <iostream>

PlayerTank::PlayerTank(std::string textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		std::cout << "Error loading Player 1 texture" << std::endl;
	}

	direction = DIR_NO;
	rank = 0;

	sprite.setTexture(this->texture);

}

void PlayerTank::render(coord fieldOffset)
{
	sprite.setPosition((float)coords.x + fieldOffset.x, (float)coords.y + fieldOffset.y);
	window->draw(sprite);
}