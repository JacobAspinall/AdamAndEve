#pragma once
#include "Human.h"
#include "MoveType.h"


//Represents the human controlled by the player
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

