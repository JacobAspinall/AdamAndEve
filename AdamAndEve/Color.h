#pragma once
#include "curses.h"

//Contains colors and symbol constants for rendering graphics with PDcurses

//Tiles
const int GRASS_COLOR = COLOR_GREEN;
const int SAND_COLOR = COLOR_YELLOW;

//Objects
const int TREE_COLOR = COLOR_CYAN;

//Entities
const int MAN_COLOR = COLOR_BLUE;
const int WOMAN_COLOR = COLOR_MAGENTA;

//Symbols
const char EMPTY_SYMBOL = ' ';
const char TREE_SYMBOL = 't';
const char MAN_SYMBOL = '@';
const char WOMAN_SYMBOL = '&';
