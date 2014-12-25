#include "Map.h"

#include <iostream>

Map::Map()
{
	typeMapSize = { 13, 13 };

	typeMap = new tileType*[typeMapSize.x];

	for (int i = 0; i < typeMapSize.x; i++)
	{
		typeMap[i] = new tileType[typeMapSize.y];
		for (int j = 0; j < typeMapSize.y; j++)
			typeMap[i][j] = TILE_AIR;
	}

	typeMap[0][0] = TILE_CONCRETE;
	typeMap[1][1] = TILE_GRASS;

	if (!tileTexture.loadFromFile(".\\Resources\\Images\\Tiles.png"))
	{
		std::cout << "Error loading tile texture" << std::endl;
	}

	singleTile.setTexture(this->tileTexture);
	singleTile.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void Map::renderOver(coord fieldOffset)
{
	for (int i = 0; i < typeMapSize.x; i++)
	{
		for (int j = 0; j < typeMapSize.y; j++)
		{
			if (typeMap[i][j] == TILE_AIR ||
				typeMap[i][j] == TILE_BRICK || 
				typeMap[i][j] == TILE_CONCRETE || 
				typeMap[i][j] == TILE_WATER || 
				typeMap[i][j] == TILE_ICE)
				continue;

			singleTile.setTextureRect(sf::IntRect(typeMap[i][j] * 16, 0, 16, 16));
			singleTile.setPosition((float)i * 16 + fieldOffset.x, (float)j * 16 + fieldOffset.y);

				// TRANSPARENT GRASS
				/*if (typeMap[i][j] == TILE_GRASS)
				{
					singleTile.setColor(sf::Color(255, 255, 255, 127));
					window->draw(singleTile);
					singleTile.setColor(sf::Color(255, 255, 255, 255));
					continue;
				}*/

			window->draw(singleTile);
		}
	}
}

void Map::renderUnder(coord fieldOffset)
{
	for (int i = 0; i < typeMapSize.x; i++)
	{
		for (int j = 0; j < typeMapSize.y; j++)
		{
			if (typeMap[i][j] == TILE_GRASS ||
				typeMap[i][j] == TILE_AIR)
				continue;

			singleTile.setTextureRect(sf::IntRect(typeMap[i][j] * 16, 0, 16, 16));
			singleTile.setPosition((float)i * 16 + fieldOffset.x, (float)j * 16 + fieldOffset.y);

			// TRANSPARENT GRASS
			/*if (typeMap[i][j] == TILE_GRASS)
			{
			singleTile.setColor(sf::Color(255, 255, 255, 127));
			window->draw(singleTile);
			singleTile.setColor(sf::Color(255, 255, 255, 255));
			continue;
			}*/

			window->draw(singleTile);
		}
	}
}