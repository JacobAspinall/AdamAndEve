#include "Grass.h"



Grass::Grass()
{
	type = TileType::Grass;
	symbol = ',';
	foregroundColor = COLOR_GREEN;
	backgroundColor = COLOR_GREEN;
	init_pair(1, foregroundColor, backgroundColor);
	colorPair = 1;
}


Grass::~Grass()
{
}
