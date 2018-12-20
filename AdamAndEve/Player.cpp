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

int Player::makeMove() {
	return taskQueue.front()->run();

}


