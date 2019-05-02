#include "RightClickMenuButton.h"



RightClickMenuButton::RightClickMenuButton(Screen& s, std::string contents, GameObject& object, GameObjectAction a) : Button(s, contents), gameObject{ object }, action{ a }
{
}


RightClickMenuButton::~RightClickMenuButton()
{
}
