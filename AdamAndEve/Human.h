#pragma once
#include "Entity.h"

const bool MAN = true;
const bool WOMAN = false;

class Human :
	public Entity
{
public:
	Human();
	Human(bool gender);
	~Human();
	bool isMan() const { return gender ? true : false; }
	bool isWoman() const { return gender ? false : true; }
private:
	bool gender = MAN;

};

