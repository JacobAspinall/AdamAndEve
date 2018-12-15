#pragma once
#include "Tile.h"
const int CHUNK_WIDTH = 256;

class Chunk
{
public:
	Chunk(int xCoord, int yCoord);
	~Chunk();
	Tile* tileMap[CHUNK_WIDTH][CHUNK_WIDTH];
	int xCoord;
	int yCoord;
	int saveAddress;//Where this chunk is located in the save file
};

