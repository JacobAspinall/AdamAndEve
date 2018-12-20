#pragma once
class Entity;
class GameMap;

#include <memory>


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

