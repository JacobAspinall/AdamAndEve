#pragma once
#include <string>
#include "ItemType.h"
#include "GameObject.h"
class Item :
	public GameObject
{
public:
	Item();
	virtual ~Item();
	ItemType type = ItemType::Log;
	std::string name;
	std::string description;
	int size;
	int weight;
};

