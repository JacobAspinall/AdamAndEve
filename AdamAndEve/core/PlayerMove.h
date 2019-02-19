#pragma once
#include "MoveType.h"
#include "MovementVector.h"

class PlayerMove
{
public:
	PlayerMove() : type{ MoveType::NoAction } {};
	PlayerMove(MoveType moveType) : type{ moveType } {};
	PlayerMove(MoveType moveType, MovementVector direction) : type{ moveType }, direction{ direction }{};
	~PlayerMove() {};

	MoveType type = MoveType::NoAction;
	MovementVector direction;
};