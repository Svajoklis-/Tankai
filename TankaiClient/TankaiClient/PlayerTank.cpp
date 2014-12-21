#include "globals.h"

#include "PlayerTank.h"

#include <iostream>

PlayerTank::PlayerTank(std::string textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		std::cout << "Error loading Player 1 texture" << std::endl;
	}

	direction = 0;
	rank = 0;

	sprite.setTexture(this->texture);

}

void PlayerTank::render(coord fieldOffset)
{
	sprite.setPosition((float)x + fieldOffset.x, (float)y + fieldOffset.y);
	window->draw(sprite);
}