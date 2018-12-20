#include "TreeInteraction.h"
#include "Entity.h"
#include "GameMap.h"



TreeInteraction::TreeInteraction(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap) {
	entity = e;
	map = myMap;
}


TreeInteraction::~TreeInteraction()
{
}


int TreeInteraction::run() {
	if (!startedChopping) {
		startedChopping = true;
		return 10;
	}
	else {
		map->tileInFrontof(entity)->object = nullptr;
		entity->endCurrentTask();
		return 1;
	}

	
}