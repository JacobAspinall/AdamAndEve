#pragma once
#include <string>
class Item
{
public:
	Item();
	virtual ~Item();
	std::string name;
	std::string description;
	int size;
	int weight;
};

