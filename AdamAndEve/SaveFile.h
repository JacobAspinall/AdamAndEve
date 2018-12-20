#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Constants.h"


//Container for the save file of a game
class SaveFile
{
public:
	SaveFile();
	~SaveFile();
	void createSaveFile();
	void saveFullMap(std::vector<Tile> map);

	std::string fileName;
};

