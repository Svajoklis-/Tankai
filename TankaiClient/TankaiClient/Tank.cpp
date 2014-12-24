#include "Tank.h"

bool Tank::checkTankCollision(coord newCoords, Tank *otherTank)
{
	if (this->ID == otherTank->ID)
		return false;

	if (newCoords.x <= otherTank->coords.x - 16)
		return false;

	if (newCoords.x >= otherTank->coords.x + 16)
		return false;

	if (newCoords.y <= otherTank->coords.y - 16)
		return false;

	if (newCoords.y >= otherTank->coords.y + 16)
		return false;

	return true;
}