#pragma once
#include "Player.h"
class BotPlayer :Player
{
	bool findPlace(int shapeType);
	void playerFlow();
	int spaceCounter(int row);
	size_t findShapeByRotate(int spaces);
};

