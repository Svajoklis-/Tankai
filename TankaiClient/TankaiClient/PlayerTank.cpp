#include "globals.h"

#include "PlayerTank.h"

#include <iostream>

PlayerTank::PlayerTank(std::string textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		std::cout << "Error loading tank texture" << std::endl;
	}

	direction = DIR_NO;
	rank = 0;

	sprite.setTexture(this->texture);
	sprite.setTextureRect(sf::IntRect(DIR_UP * 32, rank * 16, 16, 16));
	size = { 16, 16 };
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
		sprite.setTextureRect(sf::IntRect(direction * 32 + frame * 16, rank * 16, 16, 16));
}

void PlayerTank::setRank(int rank)
{
	this->rank = rank;
	sprite.setTextureRect(sf::IntRect(direction * 32 + frame * 16, rank * 16, 16, 16));
}

void PlayerTank::setCoords(coord coords)
{
	this->coords = coords;
	if (frame == 0)
		frame = 1;
	else
		frame = 0;
}

bool PlayerTank::move(coord fieldSize, Tank *otherTanks[], int maxTankCount, Map *map)
{
	coord c = getCoords();

	// if stuck
	// jis niekada ne stuck �iaip, nes juda  visada � korekti�k� pad�t� ir tik po vien�
		// if stuck on entity
			// transparent to entities
		// if stuck on level
			// transparent to level

	// check if needs to be transparent to level

	collision col = map->checkTankCollision(this, c);

	transparentToLevel = false;
	if (col != COLL_NO)
	{
		transparentToLevel = true;
	}

	// check if needs to be transparent to tanks

	transparentToTanks = false;
	for (int i = 0; i < maxTankCount; i++)
	{
		if (otherTanks[i] != nullptr)
		{
			if (checkTankCollision(c, otherTanks[i]))
			{
				transparentToTanks = true;
				break;
			}
		}
	}

	// move a single tick

	switch (getDirection())
	{
	case DIR_UP:
		if (c.y > 0)
			c.y--;
		break;

	case DIR_RIGHT:
		if (c.x < fieldSize.x - 16)
			c.x++;
		break;

	case DIR_DOWN:
		if (c.y < fieldSize.y - 16)
			c.y++;
		break;

	case DIR_LEFT:
		if (c.x > 0)
			c.x--;
		break;

	case DIR_NO:
		break;
	}

	// snap if tank changes direction

	if (direction == DIR_UP || direction == DIR_DOWN)
	{
		if (c.x % 8 < 4)
		{
			c.x = (c.x / 8) * 8;
		}
		else
		{
			c.x = (c.x / 8) * 8 + 8;
		}
	}
	else if (direction == DIR_LEFT || direction == DIR_RIGHT)
	{
		if (c.y % 8 < 4)
		{
			c.y = (c.y / 8) * 8;
		}
		else
		{
			c.y = (c.y / 8) * 8 + 8;
		}
	}

	// check for collision with tanks

	if (!transparentToTanks)
	{
		for (int i = 0; i < maxTankCount; i++)
		{
			if (otherTanks[i] != nullptr)
			{
				if (checkTankCollision(c, otherTanks[i]))
					return false;
			}
		}
	}

	// check for collision with level

	if (!transparentToLevel)
	{
		col = map->checkTankCollision(this, c);
		if (col != COLL_NO)
			return false;
	}

	// check if moved at all
	// if not - we don't need to set coordinates

	coord oldC = getCoords();
	if (oldC.x == c.x && oldC.y == c.y)
		return false;
	
	setCoords(c);

	return true;
}