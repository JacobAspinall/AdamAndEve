#include "MoveInStraightLine.h"
#include "Entity.h"
#include "Move.h"


MoveInStraightLine::~MoveInStraightLine()
{
}

int MoveInStraightLine::run() {

	
	if (xDestination == entity.xCoord && yDestination == entity.yCoord) {
		entity.endCurrentTask();
		return 1;
	}
	else {
		double a = (xDestination * 16  + 7 - entity.xCoord * 16 - entity.tileXCoord);
		double b = (yDestination * 16  + 7 - entity.yCoord * 16 - entity.tileYCoord);
		double c = std::sqrt(a*a + b * b);
		entity.setCurrentTask(std::move(std::make_unique<Move>(entity, map, MovementVector(a / c, b / c))));
	}
	return 0;
}
