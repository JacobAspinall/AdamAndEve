#pragma once
#include "ObjectType.h"
class Object
{
public:
	Object();
	virtual ~Object();
	ObjectType type = ObjectType::Empty;
	bool canWalkOn;
};

