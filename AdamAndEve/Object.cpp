#include "Object.h"
#include "Entity.h"
#include "GameMap.h"



Object::Object()
{
}


Object::~Object()
{
}


int Object::interact(Entity& e, GameMap& myMap) {
	return 1;
}
