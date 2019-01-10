#pragma once
class Entity;
class Object;
class GameMap;

#include <memory>

//Represents an AI routine for an entity
//e.g. "find food", "build a house", etc.
//
class Task
{
public:
	Task(Entity& e, GameMap& myMap);
	virtual ~Task();
	virtual int run();
	Entity& entity;
	GameMap& map;
	bool isMovementTask = false;
};

