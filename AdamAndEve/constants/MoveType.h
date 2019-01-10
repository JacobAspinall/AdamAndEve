#pragma once
//Contains all possible options entitys have when making a move
enum class MoveType {
	NoAction,
	North,
	East,
	South,
	West,
	NorthEast,
	NorthWest,
	SouthEast,
	SouthWest,
	Interact,
	Drop,
	PickUp
};