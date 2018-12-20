#pragma once
#include "Human.h"
#include "MoveType.h"
class Player :
	public Human
{
public:
	Player();
	Player(bool mygender);
	~Player();

	int makeMove();

	MoveType nextMove = MoveType::NoAction;
};

