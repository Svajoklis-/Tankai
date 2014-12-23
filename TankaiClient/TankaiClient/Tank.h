/*
*
*	Tank.h
*	An abstract tank class
*
*/

#include "globals.h"

#include "Entity.h"

#include <iostream>

#ifndef H_TANK
#define H_TANK

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

	virtual int getDirection(){ return direction; }
	virtual int getRank(){ return rank; };

	virtual void render(coord){ std::cout << "Rendering tank..." << std::endl; };

protected:

	// int x, y ;
	int rank;
	directions direction;

};


#endif