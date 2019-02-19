#include "Player.h"



Player::Player()
{
	nextMove = PlayerMove(MoveType::NoAction);
}

Player::Player(Gender mygender)
{
	gender = mygender;
	type = EntityType::Human;
	nextMove = PlayerMove(MoveType::NoAction);
}


Player::~Player()
{
}



