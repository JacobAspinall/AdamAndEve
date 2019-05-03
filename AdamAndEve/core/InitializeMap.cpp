#include "InitializeMap.h"
#include "AppleTree.h"
#include "BlueberryBush.h"

//Fills a game map with tiles
//call when creating a map for the first time
void initializeMap(GameMap& map)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (rand() % 10 < 1) {
				std::unique_ptr<Tile> newTile = std::make_unique<Grass>();
				int zeroToTwo = rand() % 3;
				if (zeroToTwo == 0) {
					newTile->object = std::make_unique<Tree>();
					map.set(i, j, std::move(newTile));
				}
				else if (zeroToTwo == 1) {
					newTile->object = std::make_unique<AppleTree>();
					map.set(i, j, std::move(newTile));
				}
				else if(zeroToTwo == 2){
					newTile->object = std::make_unique<BlueberryBush>();
					map.set(i, j, std::move(newTile));
				}
				

			}
			else
				map.set(i, j, std::make_unique<Grass>());
		}
	}
}
