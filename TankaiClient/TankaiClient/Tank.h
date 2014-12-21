/*
*
*	Tank.h
*	An abstract tank class
*
*/

#include "globals.h"

#include "Entity.h"

#ifndef H_TANK
#define H_TANK

class Tank : public Entity
{
public:

	virtual void setCoords(coord coords)
	{
		x = coords.x;
		y = coords.y;
	};

	virtual void setDirection(int direction)
	{
		this->direction = direction;
	};

	virtual void setRank(int rank)
	{
		this->rank = rank;
	};

protected:

	// int x, y ;
	int rank;
	int direction;

};


#endif