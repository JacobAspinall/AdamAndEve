#include "Player.h"



Player::Player()
{
}

Player::Player(bool mygender)
{
	gender = mygender;
	type = EntityType::Human;
}


Player::~Player()
{
}

void Player::makeMove() {
	task->run();

}


