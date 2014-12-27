#include "Map.h"

#include <iostream>

Map::Map()
{
	tileMapSize = { 13, 13 };

	tileMap = new tile*[tileMapSize.x];

	for (int i = 0; i < tileMapSize.x; i++)
	{
		tileMap[i] = new tile[tileMapSize.y];
		for (int j = 0; j < tileMapSize.y; j++)
		{
			tileMap[i][j].type = TILE_AIR;
			tileMap[i][j].unit = -1;
			tileMap[i][j].integrity = new bool[1];
			tileMap[i][j].integrity[0] = true;
		}
			
	}

	setType(0, 0, TILE_CONCRETE);
	setType(1, 1, TILE_GRASS);

	if (!tileTexture.loadFromFile(".\\Resources\\Images\\Tiles.png"))
	{
		std::cout << "Error loading tile texture" << std::endl;
	}

	singleTile.setTexture(this->tileTexture);
	singleTile.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

// grass, air
void Map::renderOver(coord fieldOffset)
{
	for (int i = 0; i < tileMapSize.x; i++)
	{
		for (int j = 0; j < tileMapSize.y; j++)
		{
			if (tileMap[i][j].type == TILE_AIR ||
				tileMap[i][j].type == TILE_BRICK ||
				tileMap[i][j].type == TILE_CONCRETE ||
				tileMap[i][j].type == TILE_WATER ||
				tileMap[i][j].type == TILE_ICE)
				continue;

			singleTile.setTextureRect(sf::IntRect(tileMap[i][j].type * 16, 0, 16, 16));
			singleTile.setPosition((float)i * 16 + fieldOffset.x, (float)j * 16 + fieldOffset.y);

			window->draw(singleTile);
		}
	}
}

// brick, concrete, water, ice
void Map::renderUnder(coord fieldOffset)
{
	for (int i = 0; i < tileMapSize.x; i++)
	{
		for (int j = 0; j < tileMapSize.y; j++)
		{
			if (tileMap[i][j].type == TILE_GRASS ||
				tileMap[i][j].type == TILE_AIR)
				continue;

			singleTile.setTextureRect(sf::IntRect(tileMap[i][j].type * 16, 0, 16, 16));
			singleTile.setPosition((float)i * 16 + fieldOffset.x, (float)j * 16 + fieldOffset.y);

			window->draw(singleTile);
		}
	}
}

collision Map::checkTankCollision(Tank *tank, coord newCoords)
{
	collision collides = COLL_YES;

	for (int i = 0; i < tileMapSize.x; i++)
	{
		for (int j = 0; j < tileMapSize.y; j++)
		{
			collides = COLL_NO;

			if (tileMap[i][j].type == TILE_CONCRETE)
			{
				collides = COLL_YES;

				if (newCoords.x <= i * 16 - 16)
					collides = COLL_NO;
				if (newCoords.x >= i * 16 + 16)
					collides = COLL_NO;
				if (newCoords.y <= j * 16 - 16)
					collides = COLL_NO;
				if (newCoords.y >= j * 16 + 16)
					collides = COLL_NO;
			}

			if (collides == COLL_YES)
				break;
		}

		if (collides == COLL_YES)
			break;
	}

	if (collides == COLL_YES)
		return COLL_YES;
	else
		return COLL_NO;
}

void Map::setType(int x, int y, tileType type)
{
	if (tileMap[x][y].type == type)
		return;

	delete[] tileMap[x][y].integrity;

	tileMap[x][y].type = type;

	switch (type)
	{
	case TILE_AIR:
		tileMap[x][y].unit = 1;
		tileMap[x][y].integrity = new bool[tileMap[x][y].unit * tileMap[x][y].unit];
		break;
	case TILE_BRICK:
		tileMap[x][y].unit = 4;
		tileMap[x][y].integrity = new bool[tileMap[x][y].unit * tileMap[x][y].unit];
		break;
	case TILE_CONCRETE:
		tileMap[x][y].unit = 2;
		tileMap[x][y].integrity = new bool[tileMap[x][y].unit * tileMap[x][y].unit];
		break;
	case TILE_WATER:
		tileMap[x][y].unit = 1;
		tileMap[x][y].integrity = new bool[tileMap[x][y].unit * tileMap[x][y].unit];
		break;
	case TILE_GRASS:
		tileMap[x][y].unit = 1;
		tileMap[x][y].integrity = new bool[tileMap[x][y].unit * tileMap[x][y].unit];
		break;
	case TILE_ICE:
		tileMap[x][y].unit = 1;
		tileMap[x][y].integrity = new bool[tileMap[x][y].unit * tileMap[x][y].unit];
		break;
	}

	for (int i = 0; i < tileMap[x][y].unit; i++)
	{
		for (int j = 0; j < tileMap[x][y].unit; j++)
		{
			tileMap[x][y].integrity[j * tileMap[x][y].unit + i] = true;
		}
	}
}