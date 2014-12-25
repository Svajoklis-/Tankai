/*
*
*	Map.h
*	A class that holds all map data and rendering.
*
*/

#include "globals.h"

#ifndef H_MAP
#define H_MAP

enum tileType
{
	TILE_AIR = -1,
	TILE_BRICK = 0,
	TILE_CONCRETE,
	TILE_WATER,
	TILE_GRASS,
	TILE_ICE
};

class Map
{
public:

	Map();

	void renderOver(coord fieldOffset);
	void renderUnder(coord fieldOffset);

private:

	sf::Texture tileTexture;
	sf::Sprite singleTile;

	tileType **typeMap;
	coord typeMapSize;

};


#endif