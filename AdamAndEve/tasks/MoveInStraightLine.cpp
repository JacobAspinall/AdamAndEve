#include "MoveInStraightLine.h"
#include "Entity.h"
#include "Move.h"


MoveInStraightLine::~MoveInStraightLine()
{
}

int MoveInStraightLine::run() {

	
	if (xDestination == entity.xCoord && yDestination == entity.yCoord && std::abs(entity.tileXCoord - innerXDestination) <= 2 && std::abs(entity.tileYCoord - innerYDestination) <= 2) {
		entity.endCurrentTask();
		return 1;
	}
	else {
		double a = (xDestination * 32  + innerXDestination - entity.xCoord * 32 - entity.tileXCoord);
		double b = (yDestination * 32  + innerYDestination - entity.yCoord * 32 - entity.tileYCoord);
		double c = std::sqrt(a*a + b * b);
		entity.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MovementVector(a / c, b / c))));
	}
	return 0;
}
