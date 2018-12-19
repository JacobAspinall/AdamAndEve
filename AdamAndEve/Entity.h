#pragma once
#include "EntityType.h"
class Entity
{
public:
	Entity();
	virtual ~Entity();

	EntityType type = EntityType::Empty;

};

