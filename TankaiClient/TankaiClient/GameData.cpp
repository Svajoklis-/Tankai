#include "GameData.h"

void GameData::receive()
{
	if (local)
	{
		this->x = game->x;
		this->y = game->y;
		this->direction = game->direction;
		this->rank = game->rank;
	}
}

void GameData::send()
{
	if (local)
	{
		game->newDirection = newDirection;
		game->newRank = newRank;
	}
}