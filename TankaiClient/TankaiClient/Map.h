/*
*
*	Map.h
*	A class that holds all map data and rendering.
*
*/

#ifndef H_MAP
#define H_MAP

#include "globals.h"

class Tank;


enum tileType
{
	TILE_AIR = -1,
	TILE_BRICK = 0,
	TILE_CONCRETE,
	TILE_WATER,
	TILE_GRASS,
	TILE_ICE
};

enum collision
{
	COLL_NO,
	COLL_YES,
	COLL_WATER
};

struct tile
{
	tileType type;
	int unit; // how many parts, 1 is full block, 2 is for concrete, 4 is for bricks
	bool *integrity; // unit * y + x
};

class Map
{
public:

	Map();

	void renderOver(coord fieldOffset);
	void renderUnder(coord fieldOffset);

	collision checkTankCollision(Tank *tank, coord newCoords);

private:

	sf::Texture tileTexture;
	sf::Sprite singleTile;

	tile **tileMap;
	coord tileMapSize;

	void setType(int x, int y, tileType type);
};

#include "Tank.h"

#endif