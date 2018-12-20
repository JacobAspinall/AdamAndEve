#pragma once
#include "Entity.h"

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
private:

protected:
	bool gender = MAN;
	

};

