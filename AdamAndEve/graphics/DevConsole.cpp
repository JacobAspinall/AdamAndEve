#include "DevConsole.h"
#include "TextDisplayBox.h"



DevConsole::DevConsole(GameMaster& master, Window& mainWindow)
	:gameMaster {master}, mainWindow{ mainWindow }, Screen(mainWindow), displayBox{ TextDisplayBox(SCREEN_WIDTH , SCREEN_HEIGHT / 2 - 16, *this) }, inputBox{ TextInputBox(SCREEN_WIDTH , 16, *this) }
{
	elements.push_back(&displayBox);
	xPosition = 0;
	yPosition = SCREEN_HEIGHT / 2;

}


DevConsole::~DevConsole()
{
}

void DevConsole::drawScreen(int x, int y, Canvas& c) {

	displayBox.drawElement(x, y, c);
	inputBox.drawElement(x, SCREEN_HEIGHT - 16, c);

}

void DevConsole::executeCommand(std::string command) {
	if (command == "i") {
		displayInventory();
	}
}

void DevConsole::displayInventory() {
	std::string output = "";

	for (int i = 0; i < gameMaster.player.lock()->inventory.size(); i++) {
		output.append(std::to_string(i + 1) + ": " + gameMaster.player.lock()->inventory[i]->name + "\n");
	}
	displayBox.content = output;
}


void DevConsole::keyPressHandler(Screen& window, SDL_Event* e) {

	if (e == nullptr) {
		return;
	}
	DevConsole& devConsole = static_cast<DevConsole&>(window);
	TextInputBox& inputBox = devConsole.inputBox;
	if (e->type == SDL_KEYDOWN) {
		if (e->key.keysym.sym == SDLK_BACKSPACE && inputBox.content.length() > 0) {
			inputBox.content.pop_back();
		}
		if (e->key.keysym.scancode == SDL_SCANCODE_RETURN) {
			devConsole.executeCommand(inputBox.content);
			inputBox.content = "";
		}
	}
	else if (e->type == SDL_TEXTINPUT && e->text.text[0] != '`') {
		inputBox.appendText(e->text.text);
	}

}
