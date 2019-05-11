#include "Human.h"


Human::Human() {
	inventory.resize(8);
	for (std::shared_ptr<Item> i : inventory) {
		i = nullptr;
	}
}

Human::Human(Gender gender)
	:gender(gender)
{
	type = EntityType::Human;
}


Human::~Human()
{
}


void Human::addItemToInventory(std::shared_ptr<Item> item) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i) == nullptr) {
			inventory.at(i) = item;
			break;
		}
	}
}
