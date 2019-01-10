#include "Player.h"



Player::Player()
{
	nextMove = MovementVector(0, 0);
}

Player::Player(Gender mygender)
{
	gender = mygender;
	type = EntityType::Human;
	nextMove = MovementVector(0, 0);
}


Player::~Player()
{
}



