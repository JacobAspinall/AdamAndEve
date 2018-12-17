#include "InitializeMap.h"
#include <cstdlib>

void initializeMap(std::vector<Tile>& map)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (rand() % 10 < 3) {
				Tile newTile = Grass();
				newTile.object = Tree();
				map.push_back(newTile);
			}
			else
				map.push_back(Grass());
		}
	}
}
