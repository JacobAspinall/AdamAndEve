#pragma once
class Entity;
class GameMap;
#include "GameObjectAction.h"
#include "ActionDescription.h"
#include <vector>


class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void executeAction(Entity& e, GameMap& m, GameObjectAction a) {};
	virtual std::vector<ActionDescription> getActions() {return std::vector<ActionDescription>();}
};

