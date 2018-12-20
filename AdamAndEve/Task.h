#pragma once
class Entity;
class GameMap;

#include <memory>

//Represents an AI routine for an entity
//e.g. "find food", "build a house", etc.
//When using this class, initialize it as a pointer to one of its derived classes to prevent object slicing
//
//Example:
//		std::unique_ptr<Task> t = std::make_unique<WalkRandomly>();
//		t->run();
//
class Task
{
public:
	Task();
	Task(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap);
	virtual ~Task();
	virtual int run();
	std::shared_ptr<Entity> entity;
	std::shared_ptr<GameMap> map;
};

