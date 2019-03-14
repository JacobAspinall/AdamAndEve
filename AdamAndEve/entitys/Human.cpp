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
	if(static_cast<int>(inventory.size()) < 8)
		inventory.push_back(std::move(item));
}
