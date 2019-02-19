#pragma once
class Entity;
class GameMap;
#include "ObjectType.h"
#include <memory>

//Abstract class to represent anything that will be seen on the game map but is not controled by AI.
//e.g.a tree or a rock
//
class Object
{
public:
	Object();
	virtual ~Object();
	virtual int interact(Entity& e, GameMap& myMap);

	ObjectType type = ObjectType::Empty;
	bool canWalkOn;
	static const int hitboxRadius = 16;
};

