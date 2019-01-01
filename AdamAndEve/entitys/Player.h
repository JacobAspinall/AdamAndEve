#pragma once
#include "Human.h"
#include "MoveType.h"


//Represents the human controlled by the player
class Player :
	public Human
{
public:
	Player();
	Player(Gender mygender);
	~Player();


	MoveType nextMove = MoveType::NoAction;
};

