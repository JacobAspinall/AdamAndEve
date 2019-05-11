#include "Water.h"
#include "Human.h"
#include "FishingRod.h"
#include "Fish.h"



Water::Water()
{
	type = TileType::Water;
	canWalkOn = false;
}


Water::~Water()
{
}

int Water::interact(Entity& e, GameMap& myMap) {
	if (e.type == EntityType::Human) {
		Human& h = static_cast<Human&>(e);
		if (h.inventory.at(h.selectedItem) != nullptr && h.inventory.at(h.selectedItem)->type == ItemType::FishingRod) {
			if (!startedFishing) {
				startedFishing = true;
				return 10;
			}
			else {
				e.endCurrentTask();
				h.addItemToInventory(std::make_shared<Fish>());
				startedFishing = false;
				return 1;
			}
		}
	}
	e.endCurrentTask();
	return 1;
}
