#include "Tree.h"
#include "Entity.h"
#include "GameMap.h"
#include "WoodenLog.h"

Tree::Tree()
{
	type = ObjectType::Tree;
	canWalkOn = false;

}

Tree::~Tree() {
}


int Tree::interact(Entity& entity, GameMap& map) {
	if (entity.type == EntityType::Human) {
		if (!startedChopping) {
			startedChopping = true;
			return 10;
		}
		else {
			map.tileInFrontof(entity)->removeObject();
			entity.endCurrentTask();
			static_cast<Human&>(entity).addItemToInventory(std::make_shared<WoodenLog>());
			return 1;
		}
	}
	return 10;
}
