/*
*
*	PlayerTank.h
*	Player tank class
*
*/

#include "globals.h"
#include "Tank.h"

#include <iostream>
#include <string>

#ifndef H_PLAYER_TANK
#define H_PLAYER_TANK

class PlayerTank : public Tank
{
public:

	// int x, y ;
	// int rank;
	// int direction;
	PlayerTank(std::string textureLocation);
	void render(coord fieldOffset);

	void setDirection(directions direction)
	{
		this->direction = direction;
		if (direction != DIR_NO)
			sprite.setTextureRect(sf::IntRect(direction * 32, rank * 16, 16, 16));
	}

	void setRank(int rank)
	{
		this->rank = rank;
		sprite.setTextureRect(sf::IntRect(direction * 32, rank * 16, 16, 16));
	}

private:

	sf::Texture texture;
	sf::Sprite sprite;
};


#endif