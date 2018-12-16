#include "InitializeMap.h"

void initializeMap(std::vector<Tile>& map)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			map.push_back(Grass());
		}
	}
}
