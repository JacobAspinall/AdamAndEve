#include "SaveFile.h"



SaveFile::SaveFile()
	:fileName("Game1")
{
	
	createSaveFile();
}


SaveFile::~SaveFile()
{
}

void SaveFile::createSaveFile() {
	std::ofstream saveFile;
	saveFile.open(fileName, std::ios::out | std::ios::binary | std::ios::trunc);//, 

	//write header
	saveFile.write((char*)&STARTING_X_COORD, 4);
	saveFile.write((char*)&STARTING_Y_COORD, 4);
	saveFile.write((char*)&MAP_WIDTH, 4);

	saveFile.close();
}

void SaveFile::saveFullMap(std::vector<Tile> map) {
	std::ofstream saveFile;
	saveFile.open(fileName, std::ios::out | std::ios::app | std::ios::binary);

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//cast enum to an int, then to char*
			int tileData = static_cast<int>(map[i*MAP_WIDTH + j].type);
			saveFile.write((char*)&tileData, 4);
		}
	}

}
