#include "InitializeMap.h"
#include <cstdlib>

void initializeMap(GameMap& map)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (rand() % 10 < 3) {
				std::shared_ptr<Tile> newTile = std::make_shared<Grass>();
				newTile->object = std::make_shared<Tree>();
				map.set(i, j, newTile);
			}
			else
				map.set(i, j, std::make_shared<Grass>());
		}
	}
}
