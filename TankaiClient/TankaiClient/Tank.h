/*
*
*	Tank.h
*	An abstract tank class
*
*/

#ifndef H_TANK
#define H_TANK

class Map;

#include "globals.h"

#include "Entity.h"

#include <iostream>

class Tank : public Entity
{
public:

	virtual void setCoords(coord coords)
	{
		this->coords = coords;
	};

	virtual void setDirection(directions direction)
	{
		this->direction = direction;
	};

	virtual void setRank(int rank)
	{
		this->rank = rank;
	};

	virtual coord getCoords()
	{
		return coords;
	}

	virtual directions getDirection(){ return direction; }
	virtual int getRank(){ return rank; };
	virtual bool move(coord fieldSize, Tank *otherTanks[], int maxTankCount, Map *map){ return true; };

	virtual void render(coord){ std::cout << "Rendering tank..." << std::endl; };

	virtual bool checkTankCollision(coord newCoords, Tank *otherTank);

	virtual void setID(int ID){ this->ID = ID; };
	virtual int getID(){ return this->ID; };

protected:

	// int x, y ;
	int rank;
	directions direction;

	bool transparentToLevel = false, transparentToTanks = false;
	int ID;

};

#include "Map.h"

#endif