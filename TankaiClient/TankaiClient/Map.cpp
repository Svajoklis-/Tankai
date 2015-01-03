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
	bool collides = false;
	bool collidesWater = false;

	bool *collisionMap;
	int collisionUnit;

	for (int i = 0; i < tileMapSize.x; i++)
	{
		for (int j = 0; j < tileMapSize.y; j++)
		{
			bool localCollides = true;

			if (tileMap[i][j].type == TILE_GRASS || tileMap[i][j].type == TILE_AIR)
				continue;

			if (tileMap[i][j].unit == 4)
			{
				collisionMap = new bool[2 * 2];
				collisionUnit = 2;
				for (int x = 0; x < 2; x++)
				{
					for (int y = 0; y < 2; y++)
					{
						collisionMap[y * 2 + x] = tileMap[i][j].integrity[y * 4 + x * 2] ||
							tileMap[i][j].integrity[y * 4 + (x * 2 + 1)] ||
							tileMap[i][j].integrity[(y + 1) * 4 + x * 2] ||
							tileMap[i][j].integrity[(y + 1) * 4 + (x * 2 + 1)];
					}
				}
			}
			else
			{
				collisionMap = tileMap[i][j].integrity;
				collisionUnit = tileMap[i][j].unit;
			}

			for (int y = 0; y < collisionUnit; y++)
			{
				for (int x = 0; x < collisionUnit; x++)
				{
					if (collisionMap[y * collisionUnit + x] == false)
					{
						localCollides = false;
						continue;
					}

					localCollides = true;

					if (newCoords.x <= i * 16 + x * (16 / collisionUnit) - 16)
						localCollides = false;
					if (newCoords.x >= i * 16 + x * (16 / collisionUnit) + (16 / collisionUnit))
						localCollides = false;
					if (newCoords.y <= j * 16 + y * (16 / collisionUnit) - 16)
						localCollides = false;
					if (newCoords.y >= j * 16 + y * (16 / collisionUnit) + (16 / collisionUnit))
						localCollides = false;

					if (localCollides)
						break;

				} // collisionMap iteration

				if (localCollides)
					break;
			}

			if (localCollides == true)
			{
				if (tileMap[i][j].type == TILE_WATER)
					collidesWater = true;
				else
					collides = true;
			}

			if (tileMap[i][j].unit == 4)
			{
				delete[] collisionMap;
			}

		} // tile iteration

	}

	if (collides && !collidesWater)
		return COLL_YES;
	else if (!collides && collidesWater)
		return COLL_WATER;
	else if (collides && collidesWater)
		return COLL_YES;
	else if (!collides && !collidesWater)
		return COLL_NO;
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

	if (type == TILE_BRICK)
	{
		tileMap[x][y].integrity[0 * 4 + 0] = false;
		tileMap[x][y].integrity[1 * 4 + 0] = false;
		tileMap[x][y].integrity[0 * 4 + 1] = false;
		tileMap[x][y].integrity[1 * 4 + 1] = false;

		tileMap[x][y].integrity[3 * 4 + 0] = false;
		tileMap[x][y].integrity[3 * 4 + 1] = false;
		tileMap[x][y].integrity[3 * 4 + 2] = false;
		tileMap[x][y].integrity[3 * 4 + 3] = false;
	}
}