#pragma once
#include "Window.h"
#include "GameMaster.h"
#include "Constants.h"
#include "TextDisplayBox.h"
#include "TextinputBox.h"

class DevConsole :
	public Screen
{
public:
	DevConsole(GameMaster& master, Window& mainWindow);
	~DevConsole();

	GameMaster& gameMaster;
	Window& mainWindow;
	TextDisplayBox displayBox;
	TextInputBox inputBox;

	
	void drawScreen(int x, int y, Canvas& c);
	void executeCommand(std::string command);
	void displayInventory();

};

void DevConsoleKeyPressHandler(Screen& window, SDL_Event* e);

