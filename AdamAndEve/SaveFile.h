#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Constants.h"



class SaveFile
{
public:
	SaveFile();
	~SaveFile();
	void createSaveFile();
	void saveFullMap(std::vector<Tile> map);

	std::string fileName;
};

