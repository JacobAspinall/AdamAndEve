#pragma once
#include "curses.h"

//Contains colors and symbol constants for rendering graphics with PDcurses

/***********************************************Colors************************************************/
//Tiles
const int GRASS_COLOR = COLOR_GREEN;
const int SAND_COLOR = COLOR_YELLOW;

//Objects
const int TREE_COLOR = 58;

//Entities
const int MAN_COLOR = COLOR_BLUE;
const int WOMAN_COLOR = COLOR_MAGENTA;

//Items
const int LOG_COLOR = 59;

/***********************************************Symbols************************************************/
const char EMPTY_SYMBOL = ' ';

//Objects
const char TREE_SYMBOL = 'T';

//Entitys
const char MAN_SYMBOL = '@';
const char WOMAN_SYMBOL = '&';

//Items
const char LOG_SYMBOL = 't';
