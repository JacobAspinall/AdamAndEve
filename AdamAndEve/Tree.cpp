#include "Tree.h"

Tree::Tree() {
	type = TileType::Tree;
	symbol = 't';
	foregroundColor = COLOR_CYAN;
	backgroundColor = COLOR_GREEN;
	init_pair(2, foregroundColor, backgroundColor);
	colorPair = 2;
}

Tree::~Tree() {
}