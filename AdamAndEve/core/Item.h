#pragma once
#include <string>
#include "ItemType.h"
class Item
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

