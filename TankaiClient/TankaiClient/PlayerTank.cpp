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
	sprite.setTextureRect(sf::IntRect(DIR_UP * 32, rank * 16, 16, 16));
}

void PlayerTank::render(coord fieldOffset)
{
	sprite.setPosition((float)coords.x + fieldOffset.x, (float)coords.y + fieldOffset.y);
	window->draw(sprite);
}

void PlayerTank::setDirection(directions direction)
{
	this->direction = direction;
	if (direction != DIR_NO)
		sprite.setTextureRect(sf::IntRect(direction * 32, rank * 16, 16, 16));
}

void PlayerTank::setRank(int rank)
{
	this->rank = rank;
	sprite.setTextureRect(sf::IntRect(direction * 32, rank * 16, 16, 16));
}