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
		Human& h = static_cast<Human&>(entity);
		if (h.inventory.at(h.selectedItem) != nullptr && h.inventory.at(h.selectedItem)->type == ItemType::StoneAxe) {
			if (!startedChopping) {
				startedChopping = true;
				return 10;
			}
			else {
				map.tileInFrontof(entity)->removeObject();
				entity.endCurrentTask();
				h.addItemToInventory(std::make_shared<WoodenLog>());
				startedChopping = false;
				return 1;
			}
		}
	}
	entity.endCurrentTask();
	return 1;
}


void executeAction(Entity& e, GameMap& m, GameObjectAction a) {

}

