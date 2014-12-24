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

	void setDirection(directions direction);

	void setRank(int rank);

	void setCoords(coord coords);

	bool move(coord fieldSize, Tank *otherTanks[], int maxTankCount);

	int frame = 0;

private:

	sf::Texture texture;
	sf::Sprite sprite;
};


#endif