#include "Map.h"

#include <iostream>
#include <fstream>

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

	char mapChar;
	std::ifstream failas(".\\Resources\\map.txt");

	for (int y = 0; y < tileMapSize.y; y++)
	{
		for (int x = 0; x < tileMapSize.x; x++)
		{
			failas >> mapChar;
			std::cout << mapChar;
			switch (mapChar)
			{
			case 'A':
				setType(x, y, TILE_AIR);
				break;
			case 'B':
				setType(x, y, TILE_BRICK);
				break;
			case 'C':
				setType(x, y, TILE_CONCRETE);
				break;
			case 'W':
				setType(x, y, TILE_WATER);
				break;
			case 'G':
				setType(x, y, TILE_GRASS);
				break;
			case 'I':
				setType(x, y, TILE_ICE);
				break;
			}
		}
		std::cout << std::endl;
		//failas >> mapChar;
	}

	if (!tileTexture.loadFromFile(".\\Resources\\Images\\Tiles.png"))
	{
		std::cout << "Error loading tile texture" << std::endl;
	}

	singleTile.setTexture(this->tileTexture);
	singleTile.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

// grass, air
void Map::render(coord fieldOffset, int plane)
{
	for (int i = 0; i < tileMapSize.x; i++)
	{
		for (int j = 0; j < tileMapSize.y; j++)
		{
			if (plane == 1)
				if (tileMap[i][j].type == TILE_AIR ||
					tileMap[i][j].type == TILE_BRICK ||
					tileMap[i][j].type == TILE_CONCRETE ||
					tileMap[i][j].type == TILE_WATER ||
					tileMap[i][j].type == TILE_ICE)
					continue;

			if (plane == 0)
				if (tileMap[i][j].type == TILE_GRASS ||
					tileMap[i][j].type == TILE_AIR)
					continue;

			for (int y = 0; y < tileMap[i][j].unit; y++)
			{
				for (int x = 0; x < tileMap[i][j].unit; x++)
				{
					if (tileMap[i][j].integrity[y * tileMap[i][j].unit + x] == true)
					{
						singleTile.setTextureRect(sf::IntRect(
							tileMap[i][j].type * 16 + x * (16 / tileMap[i][j].unit),
							y * (16 / tileMap[i][j].unit),
							16 / tileMap[i][j].unit,
							16 / tileMap[i][j].unit));
						singleTile.setPosition((float)i * 16 + fieldOffset.x + x * (16 / tileMap[i][j].unit),
							(float)j * 16 + fieldOffset.y + y * (16 / tileMap[i][j].unit));

						window->draw(singleTile);
					}
				}
			}
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

			if (tileMap[i][j].type == TILE_GRASS || tileMap[i][j].type == TILE_AIR)
				continue;

			if (tileMap[i][j].type == TILE_CONCRETE)
			{
				for (int y = 0; y < tileMap[i][j].unit; y++)
				{
					for (int x = 0; x < tileMap[i][j].unit; x++)
					{
						if (tileMap[i][j].integrity[y * tileMap[i][j].unit + x] == false)
						{
							collides = COLL_NO;
							continue;
						}

						collides = COLL_YES;

						if (newCoords.x <= i * 16 + x * (16 / tileMap[i][j].unit) - 16)
							collides = COLL_NO;
						if (newCoords.x >= i * 16 + x * (16 / tileMap[i][j].unit) + (16 / tileMap[i][j].unit))
							collides = COLL_NO;
						if (newCoords.y <= j * 16 + y * (16 / tileMap[i][j].unit) - 16)
							collides = COLL_NO;
						if (newCoords.y >= j * 16 + y * (16 / tileMap[i][j].unit) + (16 / tileMap[i][j].unit))
							collides = COLL_NO;

						if (collides != COLL_NO)
							break;
					}

					if (collides != COLL_NO)
						break;
				}

			}

			if (collides != COLL_NO)
				break;
		}

		if (collides != COLL_NO)
			break;
	}

	if (collides != COLL_NO)
		return collides;
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