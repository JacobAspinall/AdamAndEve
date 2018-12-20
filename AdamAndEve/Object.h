#pragma once
#include "ObjectType.h"
#include "Entity.h"
#include <memory>

//Abstract class to represent anything that will be seen on the game map but is not controled by AI.
//e.g.a tree or a rock
//When using this class, initialize it as a pointer to one of its derived classes to prevent object slicing
//
//Example:
//		std::unique_ptr<Object> o = std::make_unique<Tree>();
//
class Object
{
public:
	Object();
	virtual ~Object();

	ObjectType type = ObjectType::Empty;
	bool canWalkOn;
};

