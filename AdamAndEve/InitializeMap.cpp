#include "InitializeMap.h"
#include <cstdlib>

//Fills a game map with tiles
//call when creating a map for the first time
void initializeMap(GameMap& map)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (rand() % 10 < 1) {
				std::shared_ptr<Tile> newTile = std::make_shared<Grass>();
				newTile->object = std::make_shared<Tree>();
				map.set(i, j, newTile);
			}
			else
				map.set(i, j, std::make_shared<Grass>());
		}
	}
}
