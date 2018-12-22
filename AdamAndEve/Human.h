#pragma once
#include "Entity.h"
#include "Item.h"
#include <vector>

const bool MAN = true;
const bool WOMAN = false;

//A human entity
class Human :
	public Entity
{
public:
	Human();
	Human(bool gender);
	~Human();
	bool isMan() const { return gender ? true : false; }
	bool isWoman() const { return gender ? false : true; }
	void addItemToInventory(std::shared_ptr<Item> item);
	std::vector<std::shared_ptr<Item>> inventory;
private:

protected:
	bool gender = MAN;
	
};

