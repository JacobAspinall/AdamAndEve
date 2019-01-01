#include "Human.h"


Human::Human() {

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
	inventory.push_back(std::move(item));
}
