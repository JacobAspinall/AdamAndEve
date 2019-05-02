#pragma once
#include "Entity.h"
#include "Item.h"
#include <vector>

enum class Gender {
	MAN,
	WOMAN
};

//A human entity
class Human :
	public Entity
{
public:
	Human();
	Human(Gender gender);
	~Human();
	bool isMan() const { return gender == Gender::MAN ? true : false; }
	bool isWoman() const { return gender == Gender::WOMAN ? false : true; }
	void addItemToInventory(std::shared_ptr<Item> item);
	std::vector<std::shared_ptr<Item>> inventory;
	//Inventory index of the selected item. -1 for no selection
	int selectedItem = 0;
private:

protected:
	Gender gender = Gender::MAN;
	
};

