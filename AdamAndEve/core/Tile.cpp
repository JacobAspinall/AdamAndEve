#include "Tile.h"



Tile::Tile()
{
}


Tile::~Tile()
{
}


void Tile::removeObject() {
	object = nullptr;

}

int Tile::interact(Entity& e, GameMap& myMap) {
	e.endCurrentTask();
	return 1;
}