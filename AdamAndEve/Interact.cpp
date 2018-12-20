#include "Task.h"
#include "Entity.h"
#include "GameMap.h"
#include "TreeInteraction.h"




std::unique_ptr<Task> getInteractTask(std::shared_ptr<Entity> e, std::shared_ptr<GameMap> myMap) {
	if (myMap->tileInFrontof(e) == nullptr || myMap->tileInFrontof(e)->object == nullptr)
		return nullptr;

	switch (myMap->tileInFrontof(e)->object->type) {
	case ObjectType::Tree:
		return std::move(std::make_unique<TreeInteraction>(e, myMap));
	default:
		return nullptr;
	}



}