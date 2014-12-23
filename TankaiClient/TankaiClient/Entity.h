/*
*
*	Entity.h
*	An abstract entity class
*
*/

#include "globals.h"

#ifndef H_ENTITY
#define H_ENTITY

class Entity
{
public:

	virtual void render(coord fieldOffset) = 0;
	

protected:

	coord coords;

};


#endif