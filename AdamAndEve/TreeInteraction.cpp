#include "TreeInteraction.h"
#include "Entity.h"
#include "GameMap.h"






TreeInteraction::~TreeInteraction()
{
}


int TreeInteraction::run() {
	if (!startedChopping) {
		startedChopping = true;
		return 10;
	}
	else {
		map.tileInFrontof(entity)->object = nullptr;
		entity.endCurrentTask();
		return 1;
	}

	
}