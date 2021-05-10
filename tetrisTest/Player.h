#pragma once
#include "Board.h"
class Player
{
public:
	Board board;
	enum DIR { LEFT = 0, RIGHT = 1, ROTATEL = 2, ROTATER = 3, DROP = 4, DOWN = 5 };
};

